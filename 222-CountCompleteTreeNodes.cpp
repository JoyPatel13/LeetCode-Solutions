//Brute force

class Solution {
public:
    int countNodes(TreeNode* root) {
        int ans = 0; 
        if(root==nullptr) return 0;
        queue<TreeNode*>queue ;
        queue.push(root);
        ans++;
        while(!queue.empty()){
            TreeNode* current = queue.front();
            queue.pop();
            if(current->left) {
                queue.push(current->left);
                ans++;
            }
            if(current->right){
                queue.push(current->right);
                ans++;
            }
        }
        return ans;
    }
};