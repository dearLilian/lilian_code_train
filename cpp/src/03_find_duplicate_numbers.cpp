/***************************************************************************
 * 
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file 03_find_duplicate_numbers.cpp
 * @author liwenbao(liwenbao@baidu.com)
 * @date 2019/03/09 07:49:07
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include<gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>


bool find_duplicate_num_m1(int numbers[], int length, int* duplication) {
   //判断参数合法性
   if (numbers == nullptr || length <= 0) {
        std::cerr << "ERROR: invalid numbers or length" << std::endl;
        return false;
   }

   //校验数组元素范围
   for (int i = 0; i < length; i++) {
        if (numbers[i] < 0 || numbers[i] > length - 1) {
            std::cerr << "ERROR: index[" << i << "] has value[" << numbers[i] << "] over scale" << std::endl;
            return false;
        }
   }

   for (int i = 0; i < length; i++) {
        while (i != numbers[i]) {
            //判断即将要交换的数是否一致
            if (numbers[numbers[i]] == numbers[i]) {
                *duplication = numbers[i];
                std::clog << "LOG: found duplication: " << *duplication << std::endl;
                return true;
            }
            // 交换两个位置的数
            int tmp = numbers[numbers[i]];
            numbers[numbers[i]] = numbers[i];
            numbers[i] = tmp;
        }
        
   }
   return true;
}

bool print_arr(int numbers[], int length) {
    //判断参数合法性
    if (numbers == nullptr || length <= 0) {
        std::cerr << "ERROR: invalid numbers or length" << std::endl;
        return false;
    }
    std::clog << "{ " << numbers[0];
    for (int i = 1; i < length; i++) {
        std::clog << ", " << i;
    }
    std::clog << "}" << std::endl;
    return true;
}

int main() {
    int numbers[] = {2,3,1,0,2,5,3};
    int length = 7;
    int* dumplication;
    
    std::clog << "LOG: input arr is ";
    print_arr(numbers, length);
    find_duplicate_num_m1(numbers, length, dumplication);
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
