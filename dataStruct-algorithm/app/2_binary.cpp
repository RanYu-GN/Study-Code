#include <iostream>
#include <cstdlib>  // 包含 rand() 和 srand() 函数
#include <algorithm>
#include <chrono>

int* GenerateRandomArray(const int max_size, const int max_value, int& len) {
	/*
	 *  rand() 和 srand() 用于生成伪随机数。
		time(0) 用作随机数种子，以确保每次运行生成的随机数不同。
		使用 rand() / (RAND_MAX + 1.0) 生成一个范围在 [0, 1) 之间的浮点数，类似于 Java 的 Math.random()。
		根据 maxSize 和 maxValue 的值计算数组大小和数组元素的值。
	 */
	 // srand(static_cast<unsigned int>(time(nullptr)));                      // 使用当前时间作为随机数种子
	const auto now = std::chrono::high_resolution_clock::now(); // 使用高精度时钟获取当前时间点
	// 将时间点转换为自纪元以来的微秒数
	const auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();
	// 使用微妙数作为随机数种子
	srand(static_cast<unsigned int>(microseconds));
	len = static_cast<int>((max_size + 1) * (rand() / (RAND_MAX + 1.0))); // 随机一个大小在 0 - max_size 的数组
	const auto arr = new int[len];

	// 填充数组，生成 [-max_value, max_value] 范围内的随机数
	for (int i = 0; i < len; ++i) {
		// [-?, ?]
		// arr[i] = static_cast<int>((max_value + 1) * (rand() / (RAND_MAX + 1.0)) - static_cast<int>(max_value * (rand() / (RAND_MAX + 1.0))));
		// arr[i] = static_cast<int>((max_value + 1) * (rand() / (RAND_MAX + 1.0)) - max_value * (rand() / RAND_MAX + 1.0));
		const double rand_value = (rand() / (RAND_MAX + 1.0)) * 2 - 1;  // 生成 [-1, 1] 范围内的随机数
		arr[i] = static_cast<int>((max_value + 1) * rand_value);
	}
	return arr;
}

// 查找有序数组中是否存在 num
bool ExistBinary(const int* arr, const int num, const int len) {
	if (arr == nullptr || len == 0) {
		return false;
	}
	int l = 0, r = len - 1;
	while (l < r) {
		// N * 2 + 1   ===   (N << 1) | 1  左移一位乘 2 ， 或 1， 把左移用 0 补的那一位，变 1，相当于加 1  位运算 比 加减快 比 乘除快
		const int mid = l + ((r - l) >> 1);
		if (arr[mid] == num) {
			return true;
		} else if (arr[mid] < num) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return arr[l] == num;
}

// 寻找 >= value 的最左边的位置
int Comparator(const int* arr, const int value, const int len) {
	for (int i = 0; i < len; i++) {
		if (arr[i] >= value) {
			return i;
		}
	}
	return  -1;
}

int NearestIndex(const int* arr, const int value, const int len) {
	int l = 0, r = len - 1;
	int index = -1;
	while (l <= r) {
		const int mid = l + ((r - l) >> 1);
		if (arr[mid] >= value) {
			index = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return index;
}

// 局部最小值 （找到一个局部最小值的位置） arr 无序，但是任意相邻两个数都不相等
int GetLessIndex(const int* arr, const int len) {
	if (arr == nullptr || len == 0) {
		return -1;
	}
	if (len == 1 || arr[0] < arr[1]) {  // 先升
		return 0;
	}
	if (arr[len - 1] < arr[len - 2]) {  // 先降
		return len - 1;
	}
	int l = 1, r = len - 2;  //  说明当前不满足上述条件，那么说明 0~1 下降， n-2 ~ n-1 上升，那么中间一定存在局部最小
	while (l < r) {
		const int mid = l + ((r - l) >> 1);
		if (arr[mid] > arr[mid - 1]) {  // mid 和左边比较，更新右边界 上升
			r = mid - 1;
		} else if (arr[mid] > arr[mid + 1]) {  // mid 和右边比较，更新左边界 下降
			l = mid + 1;
		} else {  // 说明他不满足上面两个条件， 也就是他 左右两个数都比他大，他自己就是局部最小
			return mid; 
		}
	}
	return l;
}


int main(int argc, char* argv[]) {
	// const int arr[] = { 1,2,3,4,5,6,7,8,9 };
	// constexpr int num = 5, len = static_cast<int>(std::size(arr));  // std::size() 是 c++17 的新标准库函数，获取容器或数组的大小，如vector，array等；对于 new 的数组不能使用
	// const bool is_exist = ExistBinary(arr, num, len);
	// std::cout << (is_exist ? "Nice" : "Fucking Fucked!") << std::endl;

	constexpr int test_time = 10;
	bool succeed = true;
	// for (int i = 0; i < test_time; i++) {
	// 	constexpr int max_value = 10;
	// 	constexpr int max_size = 10;
	// 	int len;
	// 	const int value = static_cast<int>((max_value + 1) * (rand() / (RAND_MAX + 1.0)) - static_cast<int>(max_value * (rand() / (RAND_MAX + 1.0))));
	// 	int* arr = GenerateRandomArray(max_size, max_value, len);
	// 	std::sort(arr, arr + len);
	//
	// 	std::cout << "Arr: ";
	// 	for (int j = 0; j < len; j++) {
	// 		std::cout << arr[j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// 	std::cout << "Find nearest index for value" << std::endl;
	//
	// 	if (Comparator(arr, value, len) != NearestIndex(arr, value, len)) {
	// 		succeed = false;
	// 		break;
	// 	}
	// 	delete[] arr;
	// }

	for (int i = 0; i < test_time; i++) {
		constexpr int max_value = 10;
		constexpr int max_size = 10;
		int len;
		const int* arr = GenerateRandomArray(max_size, max_value, len);

		std::cout << "Arr: ";
		for (int j = 0; j < len; j++) {
			std::cout << arr[j] << " ";
		}
		std::cout << std::endl;
		if (GetLessIndex(arr, len) == -1) {
			succeed = false;
			break;
		}
		delete[] arr;
	}
	std::cout << "\n" << (succeed ? "Nice" : "Fucking Fucked!") << std::endl;

	std::cin.get();

	return 0;
}
