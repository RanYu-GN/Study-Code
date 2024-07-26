#include <iostream>

#include "array.h"

using namespace std;

/* 需求：
 * 1、设计一个动态数组类，存储整型数据
 * 2、实现如下功能：
 *  A、实现自动扩容（当数组长度不够时能够自动对数组长度进行扩容）
 *  B、销毁动态数组
 *  C、在指定位置插入元素
 *  D、删除指定位置的元素
 *  E、删除指定元素
 * */

int main() {
    Array array;

    for (int i = 0; i < array.length(); ++i) {
        cout << array.GetItemByIndex(i) << " " << array.GetSignByIndex(i) << endl;
    }
    cout << array.length() << " " << array.GetItemNum() << "\n***********************" << endl;

    array.Insert(0, 20);
    array.Insert(1, 20);
    //    array.Insert(2, 20);
    //    array.Insert(3, 30);
    array.Insert(4, 40);
    array.Insert(4, 50);

    array.Insert(1, 50);
    array.Insert(1, 10);
    //    array.Insert(1, 50);
    //    array.Insert(2, 20);
    //    array.Insert(7, 70);

    for (int i = 0; i < array.length(); ++i) {
        cout << array.GetItemByIndex(i) << " " << array.GetSignByIndex(i) << endl;
    }
    cout << array.length() << " " << array.GetItemNum() << endl;

    return 0;
}
