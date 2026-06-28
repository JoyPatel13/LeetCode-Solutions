/*
TC = O(n) 
SC + O(n)
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans; 
        if(root == nullptr) return ans ;
        queue<TreeNode*>nodes;
        nodes.push(root);
        bool leftToRight = true ;
        while(!nodes.empty()){
            int n = nodes.size();
            vector<int>row(n);
            for(int i =0 ;i<n ; i++){
                TreeNode* node = nodes.front();
                nodes.pop();

                int index = (leftToRight) ? i : (n -1 - i);

                row[index] = node->val;

                if(node->left){
                    nodes.push(node->left);
                }
                if(node->right){
                    nodes.push(node->right);

                }

            }
            leftToRight = !leftToRight;
            ans.push_back(row);
        }
        return ans;
    }
};