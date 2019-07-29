/***************************************************************************
 * 
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file two_sum.cpp
 * @author liwenbao(liwenbao@baidu.com)
 * @date 2019/07/28 12:18:12
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <algorithm>


vector<int> twoSum(vector<int>& nums, int target) {
    if (nums == NULL) {
        throw "invalid param";
    }
    
    sort(nums.begin(), nums.end());

    

    
    
}

int main() {

    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(10);
    nums.push_back(11);
    
    int target = 9;
    vector<int> indices = twoSum(nums, target);
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
