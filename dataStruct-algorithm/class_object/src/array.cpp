//
// Created by gn on 24-2-21.
//

#include <cstring>

#include "array.h"

using namespace std;

// 定义一个static成员变量
int Array::_index_error = 999999;

Array::Array() {
    cout << "Array::Array()" << endl;
    _data = new int[init_len];
    _sign = new int[init_len];
    for (int i = 0; i < init_len; ++i) {
        _data[i] = 0;
        _sign[i] = 0;
    }
    _len = init_len;
    _item_num = 0;
}

Array::Array(size_t len) {
    cout << "Array::Array(size_t)" << endl;
    _data = new int[len];
    _sign = new int[len];
    for (int i = 0; i < len; ++i) {
        _data[i] = 0;
        _sign[i] = 0;
    }
    _len = len;
    _item_num = 0;
}

Array::Array(const Array &array) {
    cout << "Array::Array(const Array &)" << endl;
    _data = new int[array.length()];
    _sign = new int[array.length()];
    _len = array.length();
    _item_num = array.GetItemNum();
    for (int i = 0; i < array.length(); ++i) {
        _data[i] = array._data[i];
        _sign[i] = array._sign[i];
    }
}

Array::~Array() {
    cout << "Array::~Array()" << endl;
    if (_data) {
        delete[] _data;
        delete[] _sign;
        _len = 0;
        _item_num = 0;
    }
}

size_t Array::length() const {
    return _len;
}

size_t Array::GetItemNum() const {
    return _item_num;
}

/* @brief 返回指定位置的元素
 * @param index 下标
 * @return int， 下标对应的元素
 * */
int Array::GetItemByIndex(size_t index) {
    if (index > _len) {
        cout << "index out of range !" << endl;
        return _index_error;
    }
    return _data[index];
}

int Array::GetSignByIndex(size_t index) {
    if (index > _len) {
        cout << "index out of range !" << endl;
        return _index_error;
    }
    return _sign[index];
}

void Array::AutoExtend() {
    int *tmp = _data; // 使用临时指针保存原来堆空间的首地址
    int *tmp1 = _sign;
    _data = new int[2 * _len];
    _sign = new int[2 * _len];
    for (int i = 0; i < 2 * _len; ++i) {
        _data[i] = 0;
        _sign[i] = 0;
    }
    // 将原来空间内容拷贝到新空间中
    memcpy(_data, tmp, sizeof(int) * _len);
    memcpy(_sign, tmp1, sizeof(int) * _len);

    _len *= 2;
    // 释放掉原来空间
    delete[] tmp;
    delete[] tmp1;
}

bool Array::Destroy() {
    if (_data) {
        delete[] _data;
        delete[] _sign;
        _data = nullptr;
        _sign = nullptr;
        _len = 0;
        _item_num = 0;
    }
    return false;
}

void Array::Insert(size_t index, int val) {
    if (index >= _len) {
        AutoExtend();
        //        if (_item_num == _len) { // 数组已满 扩容，之后无论数组满不满都在
        //            AutoExtend();
        //        }
        //        _data[_item_num] = val;
        _data[index] = val;
        _sign[index] = 1;
    } else { // index <= _len
        if (_item_num == _len) {
            AutoExtend();
        }
        if (index > _item_num) {
            size_t i = index;
            while (_sign[i] == 1) {
                i++;
            }
            _data[i] = val;
            _sign[i] = 1;
            _item_num++;
            return;
        }
        size_t loop_len = _item_num - index;
        size_t i;
        for (i = 0; i < loop_len; ++i) {
            if (_sign[index + i] == 0)
                break;
            if (_sign[index + i + 1] == 0)
                loop_len++;
            if (_sign[loop_len - i] == 0) {
                _data[loop_len - i] = _data[loop_len - 1 - i];
                _sign[loop_len - i] = 1;
                break;
            }
            _data[loop_len - i] = _data[loop_len - 1 - i];
        }
        _data[i] = val;
        _sign[i] = 1;
    }
    _item_num++;
}
