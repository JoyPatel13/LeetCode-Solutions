/*
TC = O(n)
SC = O(1)
*/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxValue(root , maxi);
        return maxi;
    }
private:
    int maxValue(TreeNode *node , int&maxi){
        if(node == nullptr) return 0;
        int leftSum = max(0,maxValue(node->left , maxi));
        int rightSum = max(0,maxValue(node->right ,maxi));
        maxi = max(maxi , leftSum+rightSum + node->val);
        return max(leftSum , rightSum) + node->val;
    }
};