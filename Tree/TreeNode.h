#ifndef TREENODE_INCLUDED
#define TREENODE_INCLUDED

template<typename Object>
struct TreeNode
{
    Object val;
    Object *left;
    Object *right;
    TreeNode(Object x) : val(x), left(NULL), right(NULL) {}
};

#endif // TREENODE_INCLUDED
