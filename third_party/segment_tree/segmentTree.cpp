#include "segmentTree.h"
#include "algorithm"
#include "iostream"

using namespace GAlgo;

template<class TValue>
SegmentTreeNode<TValue>::SegmentTreeNode(int pos)
{
    this->value = TValue::neutral();
    this->left = nullptr;
    this->right = nullptr;
    this->leftBorder = this->rightBorder = pos;
}

template<class TValue>
SegmentTreeNode<TValue>::SegmentTreeNode(int a, int pos)
{
    this->value = TValue::fromInt(a);
    this->left = nullptr;
    this->right = nullptr;
    this->leftBorder = this->rightBorder = pos;
}

template<class TValue>
SegmentTreeNode<TValue>::SegmentTreeNode(SegmentTreeNode *left, SegmentTreeNode *right)
{
    this->value = TValue::merge(left->value, right->value);
    this->left = left;
    this->right = right;
    this->leftBorder = left->getLeftBorder();
    this->rightBorder = right->getRightBorder();
}

template<class TValue>
SegmentTreeNode<TValue>* SegmentTreeNode<TValue>::getLeft() const 
{
    return this->left;
}

template<class TValue>
SegmentTreeNode<TValue>* SegmentTreeNode<TValue>::getRight() const 
{
    return this->right;
}

template<class TValue>
int SegmentTreeNode<TValue>::getLeftBorder() const 
{
    return this->leftBorder;
}

template<class TValue>
int SegmentTreeNode<TValue>::getRightBorder() const 
{
    return this->rightBorder;
}

template<class TValue>
TValue SegmentTreeNode<TValue>::getValue() const 
{
    return this->value;
}

template<class TValue>
bool SegmentTreeNode<TValue>::isLeaf() const
{   
    return (this->leftBorder == this->rightBorder);
}

template<class TValue>
void SegmentTree<TValue>::build(int *arr, int len)
{
    int new_len = 1;
    while(new_len < len) new_len <<= 1;
    this->root = this->build_(0, new_len, arr, len);
}

template<class TValue>
SegmentTreeNode<TValue>* SegmentTree<TValue>::build_(int l, int r, int *arr, int len)
{
    if(l == r)
    {
        if(l >= len)
        {
            return new SegmentTreeNode<TValue>(l);
        }
        return new SegmentTreeNode<TValue>(arr[l], l);
    }
    int m = (l + r) / 2; 
    auto left = this->build_(l, m, arr, len);
    auto right = this->build_(m + 1, r, arr, len);
    return new SegmentTreeNode<TValue>(left, right);

}

template<class TValue>
TValue SegmentTree<TValue>::get(int l, int r)
{
    return this->get_(this->root, l, r);
}

template<class TValue>
TValue SegmentTree<TValue>::get_(SegmentTreeNode<TValue> *current, int ll, int rr)
{   
    int l = current->getLeftBorder();
    int r = current->getRightBorder();

    if(l == ll && rr == r)
    {
        return TValue(current->getValue());
    }

    int m = (l + r) / 2;
    bool leftSuccess = false;
    bool rightSuccess = false;
    TValue leftValue, rightValue;

    if(ll <= std::min(m, rr))
    {
        leftValue = this->get_(current->getLeft(), ll, std::min(m, rr));
        leftSuccess = true;
    }

    if(std::max(ll, m + 1) <= rr)
    {
        rightValue = this->get_(current->getRight(), std::max(ll, m + 1), rr);
        rightSuccess = true;
    }

    if(leftSuccess && rightSuccess)
    {
        return TValue::merge(leftValue, rightValue);
    }
    else if(leftSuccess)
    {
        return TValue(leftValue);
    }
    else if(rightSuccess)
    {
        return TValue(rightValue);  
    }
}

template<class TValue>
void SegmentTree<TValue>::update(int pos, int val)
{
    this->root = this->update_(this->root, pos, val);
}


template<class TValue>
SegmentTreeNode<TValue>* SegmentTree<TValue>::update_(SegmentTreeNode<TValue> *cur, int pos, int val)
{
    if(cur->isLeaf())
    {
        delete cur;
        return new SegmentTreeNode<TValue>(val, cur->getLeftBorder());
    }

    int l = cur->getLeftBorder();
    int r = cur->getRightBorder();
    int m = (l + r) / 2;
    auto left = cur->getLeft();
    auto right = cur->getRight();

    if(pos <= m)
    {
        left = this->update_(left, pos, val);
    }
    else
    {
        right = this->update_(right, pos, val);
    }

    delete cur;
    return new SegmentTreeNode<TValue>(left, right);
}
