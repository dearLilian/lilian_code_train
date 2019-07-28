/***************************************************************************
 * 
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file search_algo.cpp
 * @author liwenbao(liwenbao@baidu.com)
 * @date 2019/07/28 11:07:28
 * @version $Revision$ 
 * @brief 
 *  
 **/


#include <iostream>
#include <exception>

/**顺序查找
*思路：遍历数组，并进行元素比较，针对一般的线性顺序表或者线性链表
*优点：对于数组元素的存储没有要求
*缺点：时间复杂度O(n),当n很大时，查找效率较差.
*/
int sequentialSearch(int array[], int length, int value) {
    if (array == NULL) {
        throw "input param invalid";
    }

    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            return i;
        }
    }

    return -1; 
}

/**二分查找
*思路：针对有序数组(从小到大)
*优点：时间复杂度O(logn)
*缺点：
*/
int binarySearch(int array[], int length, int value) {
    
    if (array == NULL) {
        throw "invalid param";
    }

    int begin = 0;
    int end = length - 1;

    while (begin <= end) {
        std::cout << "search between index [" << begin << "," << end << "],";
        int middle = (begin + end) / 2;
        int curValue = array[middle];
        std::cout << "middle index " << middle << ", its value: " << curValue;
        if (curValue == value) {
            std::cout << " equal search_value " << value << ", search end." << std::endl;
            return middle;
        } else if (value < curValue) {
            std::cout << " > search_value " << value << ", go to next search." << std::endl;
            end = middle - 1;
        } else {
            std::cout << " < search_value " << value << ", go to next search." << std::endl;
            begin = middle + 1;
        }

    }
    std::cout << "search end, can not find the search value" << std::endl;
    return -1;
}

/**插值查找
*思路：是对二分查找的改进，二分查找是选择中间的数据进行比较，而插值查找则是寻找离近的index去比较,
*其比较index=low + (high-low) * (key - array[low]) / (array[high] - array[low])，对于一些元素分布均匀的数组来说，其查找时间能够大大下降，比如这个case:在数组{1,3,5,7,9,10,13, 15, 20}中查找20这个元素，用二分查找要查4次，而用插值查找只需要1次
*/

int binarySearchV2(int array[], int length, int value) {
    
    if (array == NULL) {
        throw "invalid param";
    }

    int begin = 0;
    int end = length - 1;

    while (begin <= end) {
        std::cout << "search between index [" << begin << "," << end << "],";
        int middle = begin + int((value - array[begin]) * 1.0 / (array[end] - array[begin]) * (end - begin));
        if (middle < begin || middle > end) {
            std::cout << "search index " << middle << " jump out, search end, can not find the search value" << std::endl;
            return -1;
        }
        int curValue = array[middle];
        std::cout << "middle index " << middle << ", its value: " << curValue;
        if (curValue == value) {
            std::cout << " equal search_value " << value << ", search end." << std::endl;
            return middle;
        } else if (value < curValue) {
            std::cout << " > search_value " << value << ", go to next search." << std::endl;
            end = middle - 1;
        } else {
            std::cout << " < search_value " << value << ", go to next search." << std::endl;
            begin = middle + 1;
        }

    }
    std::cout << "search end, can not find the search value" << std::endl;
    return -1;
}

//哈希表查找

//二叉排序树查找


int testSquentialSearch() {
    int a[7] = {1,5,2,3,0,10,7};
    int n = 7;
    int value = 3;
    int index = sequentialSearch(a, n, value);
    std::cout << value << " in array index=" << index << std::endl;

    return 0;
}

int testBinarySearch() {
    int a[9] = {1,3,5,7,9,10,13, 15, 20};
    int n = 9;
    int value = 20;
    std::cout << "============v1=========" << std::endl;
    int index = binarySearch(a, n, value);
    std::cout << value << " in array index=" << index << std::endl;
    
    std::cout << "============v2=========" << std::endl;
    int index = binarySearchV2(a, n, value);
    std::cout << value << " in array index=" << index << std::endl;

    return 0;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 */
