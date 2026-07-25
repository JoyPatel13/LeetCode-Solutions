/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i =0 ;i<size ;i++){
                Node* curr1 = q.front();
                q.pop();
                if(i<size -1){
                    Node*curr2 = q.front();
                    // q.pop();
                    curr1->next = curr2 ;
                    
                }
                if(q.empty()){
                    curr1->next = NULL;
                }
                if(curr1->left) q.push(curr1->left);
                if(curr1->right) q.push(curr1->right);
            }
        }
        return root;
    }
};