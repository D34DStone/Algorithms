#ifndef STACK_H_
#define STACK_H_

template<class T>
class Stack
{
private:
    T *base;
    T *top;
    int size = 0;

public:
    Stack(int size=1024);
    ~Stack();
    bool empty() const;

    void push(const T& v);
    T pop();
};

#endif// STACK_H_
