/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>&A , int& i ,int lower , int higher){   
        if(i == A.size()) return NULL ;
       
        if( A[i] < lower ||  A[i]> higher)return NULL ;
        TreeNode* root = new TreeNode(A[i++]);
        root->left  = helper(A , i , lower , root->val);
        root->right = helper(A , i , root->val , higher);
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       int i =0; 
       return helper(preorder , i , INT_MIN , INT_MAX);

    }
};