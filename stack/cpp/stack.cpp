#include "iostream"
#include "string"
#include "stack.h"

template<class T>
Stack<T>::Stack(int size)
{
    this->size = size;
    this->base = this->top = new T[size];
}

template<class T>
Stack<T>::~Stack()
{
    delete this->base;
}

template<class T>
bool Stack<T>::empty() const 
{
    return base == top;
}

template<class T>
void Stack<T>::push(const T& v) 
{
    if (this->top - this->base == this->size) 
        throw "stack crowded";

    *(++this->top) = v;
}

template<class T>
T Stack<T>::pop()
{
    if (this->empty())
        throw "stack is empty";

    return *(top--);
}

int main()
{
    auto s = Stack<int>();

    std::string cmd = "";

    while(1)
    {
        std::cin >> cmd;
        if(cmd == "exit") break;

        if(cmd == "push")
        {
            int val = 0;
            std::cin >> val;
            s.push(val);
        }
        if(cmd == "pop")
        {
            std::cout << s.pop() << std::endl;
        }
    }    

    return 0;
}
