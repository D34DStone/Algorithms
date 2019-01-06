#ifndef SEGMENT_TREE_H_
#define SEGMENT_TREE_H_

namespace GAlgo
{
    template<class TValue>
    class SegmentTreeNode 
    {
    private:
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        TValue value;
        int leftBorder;
        int rightBorder;

    public:
        SegmentTreeNode(int pos);
        SegmentTreeNode(int val, int pos);
        SegmentTreeNode(SegmentTreeNode *, SegmentTreeNode *);

        SegmentTreeNode* getLeft() const;
        SegmentTreeNode* getRight() const;
        int getLeftBorder() const;
        int getRightBorder() const;
        TValue getValue() const;
        bool isLeaf() const;
    };

    template<class TValue>
    class SegmentTree
    {
    public:
        TValue get(int l, int r);

        void build(int *arr, int len);
        void update(int pos, int val);

    private:
        SegmentTreeNode<TValue>* root;
        SegmentTreeNode<TValue>*  build_(int l, int r, int *arr, int len);
        TValue get_(SegmentTreeNode<TValue>* cur, int ll, int rr);
        SegmentTreeNode<TValue>* update_(SegmentTreeNode<TValue> *cur, int pos, int val);
    };
};

#endif// SEGMENT_TREE_H_