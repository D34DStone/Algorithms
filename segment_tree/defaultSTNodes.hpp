#ifndef DEFAULT_ST_NODES_H_
#define DEFAULT_ST_NODES_H_

#include "algorithm"

namespace GAlgo 
{
    struct IntSum
    {
        int val;

        static IntSum merge(const IntSum &a, const IntSum &b)
        {
            IntSum newValue; newValue.val = a.val + b.val;
            return newValue;
        }

        static IntSum fromInt(int a)
        {
            IntSum newValue; newValue.val = a;
            return newValue;
        }

        static IntSum neutral()
        {
            IntSum newValue; newValue.val = 0;
            return newValue;
        }
    };

    struct IntMin
    {
        static const int INF = 1e9 - 1;
        int val;

        static IntMin merge(const IntMin &a, const IntMin &b)
        {
            IntMin newValue; newValue.val = std::min(a.val, b.val);
            return newValue;
        }

        static IntMin fromInt(int a)
        {
            IntMin newValue; newValue.val = a;
            return newValue;
        }

        static IntMin neutral()
        {
            IntMin newValue; newValue.val = INF;
            return newValue;
        }
    };
};

#endif//DEFAULT_ST_NODES_H_