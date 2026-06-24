// TC = O(n^2)
// SC = O(1)
int maxDepth(TreeNode* root) {
        if(root== nullptr) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
} 

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr ) return true;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        int ans = abs(lh-rh);
        if(ans>1) return false; 
        int leftBalance = isBalanced(root->left);
        int rightBalance = isBalanced(root->right);
        if(leftBalance == true && rightBalance == true) return true;
        return false;
        
    }
};

// TC + O(n)
// SC = O(1)

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return heightCheck(root) != -1;

    }
    int heightCheck(TreeNode*root){
        if(root==nullptr) return 0;
        int lh = heightCheck(root->left);
        if(lh == -1) return -1;
        int rh = heightCheck(root->right);
        if(rh== -1) return -1;
        if(abs(lh -rh) > 1) return -1;
        return max(lh,rh) + 1;
        
    }
};