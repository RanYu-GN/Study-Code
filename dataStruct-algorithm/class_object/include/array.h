//
// Created by gn on 24-2-21.
//

#ifndef CLASS_OBJECT_ARRAY_H
#define CLASS_OBJECT_ARRAY_H

#include <iostream>

constexpr size_t init_len = 4;
// const int index_error = 999999;

class Array {

    // 属性
private:
    static int _index_error; // 声明static成员变量
    int *_data;
    int *_sign; // 只存0 1, 对应data的数据，0 代表当前位置没有存储，1 代表已经存储
    size_t _len;
    size_t _item_num;

    // 方法
public:
    // 无参构造
    Array();

    // 有参构造
    explicit Array(size_t);

    // 拷贝构造函数
    Array(const Array &);

    // 析构函数
    ~Array();

    // 返回数组长度
    size_t length() const;

    // 返回数组存储元素个数
    size_t GetItemNum() const;

    // 返回指定位置的元素
    int GetItemByIndex(size_t);

    // 返回指定位置的标志，看当前位置是初始数字 0 还是我们插入的 0
    int GetSignByIndex(size_t);

    // 销毁动态数组
    bool Destroy();

    void Insert(size_t, int);

    // private:
    //  自动扩容
    void AutoExtend();

public:
};

#endif // CLASS_OBJECT_ARRAY_H
