//很简单的思路
class Solution {
private:
    TreeNode *helper(TreeNode *root)
    {
        if(root == nullptr) return nullptr;
        TreeNode *L = helper(root->left);
        TreeNode *R = helper(root->right);
        
        root->left = nullptr; //set left child null
        root->right = L;
        TreeNode *last = root;
        while(last->right) last=last->right;
        last->right = R;
        return root;
    }

public:
    void flatten(TreeNode *root) {
        root=helper(root);
    }
};
