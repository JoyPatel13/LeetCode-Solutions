class Solution {
public:
    void inorder(TreeNode* node, vector<int>&ans){
        if(node == NULL) return;

        inorder(node->left, ans);
        ans.push_back(node->val);
        inorder(node->right, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0 ;
        vector<int> ans;
        inorder(root, ans);
        return ans[k-1];
    }
};