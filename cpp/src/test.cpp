/***************************************************************************
 * 
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file test.cpp
 * @author liwenbao(liwenbao@baidu.com)
 * @date 2019/03/11 17:57:04
 * @version $Revision$ 
 * @brief 
 *  
 **/


#include <iostream>

using namespace std;


int main() {
    char* cts = new char[10];
    cout << sizeof(cts) << endl;

    for (int i = 0; i < 5; i++) {
        cts[i] = 'i';
        cout << sizeof(cts) << endl;
    }

    return 0;

}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
