#include "stack.cpp"
#include "iostream"
#include "string"

int main()
{
    std::string cmd;
    Stack<int> s = Stack<int>();

    while(1)
    {
        std::cin >> cmd;
        try 
        {
            if(cmd == "push") 
            {
                int v;
                std::cin >> v;
                s.push(v);  
            }
            if(cmd == "pop")
            {
                std::cout << s.pop() << std::endl;
            }
        }
        catch(char const* err)
        {
            std::cout << err << std::endl;
            return 1;
        }
    }

    return 0;
}
