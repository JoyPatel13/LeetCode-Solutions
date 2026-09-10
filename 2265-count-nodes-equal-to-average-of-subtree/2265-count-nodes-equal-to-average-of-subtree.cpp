class Solution {

public:
    int sizeOfSubtree(TreeNode* node){
        if(node == NULL) return 0 ;
        int size = 1 ;
        if(node->right){
            size += sizeOfSubtree(node->right);
        }
        if(node->left){

            size+= sizeOfSubtree(node->left);
        }
        return size;
    }

    int sumOfSubtree(TreeNode* node){
        int sum = 0 ;
        if(node == NULL) return 0;
        sum+= node->val;
        if(node->right){
            sum+= sumOfSubtree(node->right);
        }
        if(node->left){
            sum+= sumOfSubtree(node->left);
        }
        return sum;
    }

public:
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0 ;
        int avg = sumOfSubtree(root)/sizeOfSubtree(root);
        if(avg == root->val) ans+=1;

        if(root->right){
            ans+=  averageOfSubtree(root->right);
        }
        if(root->left){
            ans+= averageOfSubtree(root->left);
        }
        return ans;
    }
};