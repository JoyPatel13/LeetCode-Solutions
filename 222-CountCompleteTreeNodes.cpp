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


//Optimal solution
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0 ;
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        if(lh == rh) return (1<<lh) - 1;
        return 1 + countNodes(root->left ) + countNodes(root->right);
    }
    int findLeftHeight(TreeNode* node){
        int h= 0 ;
        while(node){
            h++;
            node =node->left;
        }
        return h;
    }
    int findRightHeight(TreeNode* node){
        int h = 0;
        while(node){
            h++;
            node=node->right;
        }
        return h;
    }
};