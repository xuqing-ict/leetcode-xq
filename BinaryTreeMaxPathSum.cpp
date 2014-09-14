Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

//DP 保存一个local值，以及每次维护一个global的值，并且每次更新之
class Solution {
    //由于每一步都需要更新global的值，那么这里我们需要的就是将global的值传递给每一次调用！！！
private:
    int helper(TreeNode *root, int &global)
    {
        if(root == nullptr) return 0;
        int left = helper(root->left, global);
        int right = helper(root->right, global);
        int ret = max(root->val, max(left+root->val, right+root->val));
        global = max(global,max(ret,left+root->val+right));
        return ret;
    }

public:
    int maxPathSum(TreeNode *root) {
        int ret = INT_MIN;
        helper(root,ret);
        return ret;
    }
};
