/*
TC = O(n)
SC = O)(h) where h is height of tree
*/
class Solution {
public:
void recursion(TreeNode* root , int level , vector<int> &res){
    if(root == nullptr) return;
    if(level == res.size() ) res.push_back(root->val);
    if(root->right) recursion(root->right , level+1 , res);
    if(root->left) recursion(root->left, level+1 , res);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root , 0 , res);
        return res;
    }
};