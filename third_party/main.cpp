#include "segment_tree/segmentTree.cpp"
#include "segment_tree/defaultSTNodes.hpp"
#include "iostream"
#include "algorithm"

using namespace GAlgo;


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    SegmentTree<IntSum> s;
    s.build(arr, 10);
    
    for(int i = 0; i < 10; i++)
    {
        char c = '0';

        std::cin >> c;

        if(c == 'g')
        {
            int a, b;
            std::cin >> a >> b;
            auto val = s.get(a - 1, b - 1);
            std::cout << "Result: " << val.val << std::endl;
        }
        if(c == 'u')
        {
            int a, b;
            std::cin >> a >> b;
            s.update(a - 1, b);
            std::cout << "Updated" << std::endl;
        }
    }
}