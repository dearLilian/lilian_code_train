/***************************************************************************
 * 
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file queue_consruct.cpp
 * @author liwenbao(liwenbao@baidu.com)
 * @date 2019/07/27 00:58:41
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <stack>
#include <exception>

template<class T> class MyQueue {

public:
    void push(const T& value);
    T pop();
    T top();
    int size();
private:
    std::stack<T> s1;
    std::stack<T> s2;
};

template<typename T>
void MyQueue<T>::push(const T& value) {
    s1.push(value);
}

template<typename T>
T MyQueue<T>::pop() {
    if (s2.empty()) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    if (s2.empty()) {
        throw std::runtime_error("queue is empty");
    }

    T res = s2.top();
    s2.pop();
    return res;
}

template<typename T>
T MyQueue<T>::top() {
    if (s2.empty()) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    if (s2.empty()) {
        throw std::runtime_error("queue is empty");
    }

    T res = s2.top();
    return res;
}

template<typename T>
int MyQueue<T>::size() {
    return s1.size() + s2.size();
}

int main() {
    MyQueue<int> q;

    q.push(1);
    std::cout << "queue size: " << q.size() << std::endl;
    q.push(2);
    std::cout << "queue size: " << q.size() << std::endl;
    q.push(3);
    std::cout << "queue size: " << q.size() << std::endl;

    int a = q.pop();
    std::cout << "queue size: " << q.size() << std::endl;
    int b = q.top();
    std::cout << "queue size: " << q.size() << std::endl;

    return 0;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 */
