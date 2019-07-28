/***************************************************************************
 * 
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file stack_construct.cpp
 * @author liwenbao(liwenbao@baidu.com)
 * @date 2019/07/27 00:59:10
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>

#include <queue>

#include <exception>

template<class T> class MyStack {

public:
    void push(const T& value);
    T pop();
    T top();
    void swapQueue();
    int size();
private:
    std::queue<T> dataQueue;
    std::queue<T> helpQueue;

};

template<typename T>
int MyStack<T>::size() {
    return dataQueue.size();
}

template<typename T>
void MyStack<T>::push(const T& value) {
    dataQueue.push(value);
}

template<typename T>
void MyStack<T>::swapQueue() {
    std::queue<T> tmp = dataQueue;
    dataQueue = helpQueue;
    helpQueue = tmp;
}

template<typename T>
T MyStack<T>::pop() {
    if (dataQueue.empty()) {
        throw std::runtime_error("queue is empty");
    }
    while(dataQueue.size() > 1) {
        helpQueue.push(dataQueue.front());
        dataQueue.pop();
    }
    T res = dataQueue.front();
    dataQueue.pop();
    swapQueue();
    return res;
}

template<typename T>
T MyStack<T>::top() {
    if (dataQueue.empty()) {
        throw std::runtime_error("queue is empty");
    }
    while(dataQueue.size() > 1) {
        helpQueue.push(dataQueue.front());
        dataQueue.pop();
    }
    T res = dataQueue.front();
    helpQueue.push(res);
    dataQueue.pop();
    swapQueue();
    return res;
}

int main() {
    MyStack<int> mStack;

    mStack.push(3);
    std::cout << "mystack size: " << mStack.size() << std::endl;
    mStack.push(2);
    std::cout << "mystack size: " << mStack.size() << std::endl;
    mStack.push(1);
    std::cout << "mystack size: " << mStack.size() << std::endl;

    int a = mStack.pop();
    std::cout << "mystack size: " << mStack.size() << std::endl;
    int b = mStack.top();
    std::cout << "mystack size: " << mStack.size() << std::endl;
    return 0;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 */
