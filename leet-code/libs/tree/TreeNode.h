#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

template <typename T=int> class TreeNode
{
    private:
    public:
    T         val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T d) : val(d), left(nullptr), right(nullptr) {};

    T getData() const
    {
        return val;
    }

    TreeNode* getLeft() const
    {
        return left;
    }

    TreeNode* getRight() const
    {
        return right;
    }

    void setRight(TreeNode* const node)
    {
        right = node;
    }

    void setLeft(TreeNode* const node)
    {
        left = node;
    }

    void setData(const T d)
    {
        val = d;
    }
};

#endif // _TREE_NODE_H_
