#ifndef STACK_H_
#define STACK_H_

#define BEGIN_SIZE 8

template<class T>
class Stack 
{
private:
    int offset;
    int size;
    T* stack;

    void expand();

public:
    Stack();
    ~Stack();
    
    bool empty() const;
    void push(const T&);
    T pop(); 
};

#endif// STACK_H_
