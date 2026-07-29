struct NodeValue {
    int minNode, maxNode, sum;
    bool isBST;

    NodeValue(int minN, int maxN, int s, bool bst) 
        : minNode(minN), maxNode(maxN), sum(s), isBST(bst) {}
};

class Solution {
    int maxSum = 0;

    NodeValue helper(TreeNode* root) {
        // Base case: An empty tree is a valid BST with sum 0
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0, true);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        // Check if current node forms a valid BST
        if (left.isBST && right.isBST && left.maxNode < root->val && root->val < right.minNode) {
            int currentSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currentSum);

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currentSum,
                true
            );
        }

        // If not a valid BST, mark isBST as false
        return NodeValue(INT_MIN, INT_MAX, 0, false);
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        helper(root);
        return maxSum;
    }
};