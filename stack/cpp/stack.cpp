#include "stack.h"
#include "cstring"

template<class T>
Stack<T>::Stack()
{
    size = BEGIN_SIZE;
    stack = new T[size];
    offset = 0;
}

template<class T>
Stack<T>::~Stack()
{
    delete stack;
}

template<class T>
bool Stack<T>::empty() const
{
    return offset == 0;
}

template<class T>
void Stack<T>::push(const T& val)
{
    stack[offset] = val;
    offset++;

    if(offset == size) 
    {
        expand();
    }
}

template<class T>
void Stack<T>::expand()
{
    auto new_stack = new T[2 * size];
    if(!new_stack)
    {
        throw "Exception: failed to allocate more memory";
    }
    memcpy(new_stack, stack, offset * sizeof(T));
    delete stack;
    stack = new_stack;
    size *= 2;
}

template<class T>
T Stack<T>::pop()
{
    if(empty())
    {
        throw "Exception: stack is empty";
    }
    return stack[--offset];
}

