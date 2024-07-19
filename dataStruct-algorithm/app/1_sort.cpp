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
	auto now = std::chrono::high_resolution_clock::now(); // 使用高精度时钟获取当前时间点
	// 将时间点转换为自纪元以来的微秒数
	auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();
	// 使用微妙数作为随机数种子
	srand(static_cast<unsigned int>(microseconds));

	len = static_cast<int>((max_size + 1) * (rand() / (RAND_MAX + 1.0))); // 随机一个大小在 0 - max_size 的数组
	const auto arr = new int[len];

	// 填充数组，生成 [-max_value, max_value] 范围内的随机数
	for (int i = 0; i < len; ++i) {
		// [-?, ?]
		// arr[i] = static_cast<int>((max_value + 1) * (rand() / (RAND_MAX + 1.0)) - static_cast<int>(max_value * (rand() / (RAND_MAX + 1.0))));
		// arr[i] = static_cast<int>((max_value + 1) * (rand() / (RAND_MAX + 1.0)) - max_value * (rand() / RAND_MAX + 1.0));
		double rand_value = (rand() / (RAND_MAX + 1.0)) * 2 - 1;  // 生成 [-1, 1] 范围内的随机数
		arr[i] = static_cast<int>((max_value + 1) * rand_value);
	}
	return arr;
}


int* CopyArray(const int* arr, const int len) {
	if (arr == nullptr) {
		return nullptr;
	}
	const auto arr1 = new int[len];
	for (int i = 0; i < len; i++) {
		arr1[i] = arr[i];
	}
	return arr1;
}

void Swap(int* arr, const int l, const int r) {
	// arr[l] ^= arr[r];
	// arr[r] ^= arr[l];
	// arr[l] ^= arr[r];
	const int tmp = arr[r];
	arr[r] = arr[l];
	arr[l] = tmp;
}

// 选择排序---每次选择最小的放在最前面
// 0 ~ N-1
// 1 ~ N-1
void SelectSort(int* arr, const int len) {
	if (arr == nullptr || len < 2)
		return;
	for (int i = 0; i < len - 1; i++) {
		int min_num_index = i;
		for (int j = i + 1; j < len; j++) {
			// if (arr[j] < arr[min_num_index]) {
			// 	min_num_index = j;
			// }
			min_num_index = arr[j] < arr[min_num_index] ? j : min_num_index;
		}
		Swap(arr, i, min_num_index);
	}
}

// 冒泡排序---每次比较相邻两个，大的放在后面，也就是一轮后，最大的一定在最后
// 0 ~ N-1
// 0 ~ N-2
void BubbleSort(int* arr, const int len) {
	if (arr == nullptr || len < 2) {
		return;
	}
	for (int i = len - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				Swap(arr, j, j + 1);
			}
		}
	}
}

// 插入排序---也就是把  0  1  2 依次有序
// 0 ~ 1  先从 0-1 有序，用 1 和 0 比较，小的话和前一位交换
// 0 ~ 2  因为 0-1 有序，用 2 和 1，0 比较，小的话和前一位交换
void InsertSort(int* arr, const int len) {
	if (arr == nullptr || len < 2) {
		return;
	}
	for (int i = 1; i < len; i++) {
		// for (int j = i; j > 0; j--) {
		// 	if (arr[j] < arr[j - 1]) {
		// 		Swap(arr, j, j - 1);
		// 	}
		// }
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
			Swap(arr, j, j - 1);
		}
	}
}

void Comparator(int* arr, const int len) {
	std::sort(arr, arr + len);
}

bool IsEqual(const int* arr1, const int* arr2, const int len) {
	if ((arr1 == nullptr && arr2 != nullptr) || (arr1 == nullptr && arr2 != nullptr)) {
		return false;
	}
	if (arr1 == nullptr && arr2 == nullptr) {
		return true;
	}
	for (int i = 0; i < len; i++) {
		if (arr1[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[]) {
	constexpr int test_time = 10;
	bool succeed = true;
	for (int i = 0; i < test_time; i++) {
		constexpr int max_value = 10;
		constexpr int max_size = 10;
		int len;
		// constexpr int len = 9;
		// int arr[] = { 8, 5, 2, 3, 1, 4, 7, 9, 6 };
		int* arr1 = GenerateRandomArray(max_size, max_value, len);
		int* arr2 = CopyArray(arr1, len);

		std::cout << "Arr1 Before Sort: ";
		for (int j = 0; j < len; j++) {
			std::cout << arr1[j] << " ";
		}
		std::cout << std::endl;
		std::cout << "Arr2 Before Sort: ";
		for (int j = 0; j < len; j++) {
			std::cout << arr2[j] << " ";
		}
		std::cout << std::endl;

		// 调用排序算法
		InsertSort(arr1, len);
		// 用比较器的方法排序 arr2，可以用自己写的其他的
		Comparator(arr2, len);
		
		std::cout << "Arr1 After Sort: ";
		for (int j = 0; j < len; j++) {
			std::cout << arr1[j] << " ";
		}
		std::cout << std::endl;
		std::cout << "Arr2 After Sort: ";
		for (int j = 0; j < len; j++) {
			std::cout << arr2[j] << " ";
		}
		std::cout << std::endl;
		// 对比两种方法结果是否一样，就可以检验写对了没
		if (!IsEqual(arr1, arr2, len)) {
			succeed = false;
			break;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		delete[] arr1;
		delete[] arr2;
	}
	std::cout << (succeed ? "Nice" : "Fucking Fucked!") << std::endl;

	// std::cout << "Before Sort: ";
	// for (const auto& arr : arr1) {
	// 	std::cout << arr1 << " ";
	// }
	// std::cout << std::endl;
	//
	// // 调用排序算法
	// InsertSort(arr1, len);
	//
	// std::cout << "After Sort: ";
	// for (const auto& arr : arr1) {
	// 	std::cout << arr1 << " ";
	// }
	// std::cout << std::endl;

	// system("pause");
	std::cin.get();

	return 0;
}
