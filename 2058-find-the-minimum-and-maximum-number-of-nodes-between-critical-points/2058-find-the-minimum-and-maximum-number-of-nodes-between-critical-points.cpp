/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans = {-1, -1};
        int minDistance = INT_MAX;

        ListNode* previousNode = head;
        ListNode* currentNode = head->next;
        int currentInd = 1 ;
        int preCritInd = 0;
        int firstCritInd = 0 ;

        while(currentNode->next!= NULL){
            if((currentNode->val > previousNode->val && currentNode->val > currentNode->next->val) || 
               ( currentNode->val < previousNode->val && currentNode->val < currentNode->next->val)
            ){
                if(preCritInd == 0){
                    preCritInd = currentInd ;
                    firstCritInd = currentInd ;
                }
                else{
                    minDistance = min(minDistance , currentInd - preCritInd);
                    preCritInd = currentInd ;
                }
            }
            currentInd ++ ;
            previousNode = currentNode; 
            currentNode = currentNode->next;
        }
        if(minDistance!=INT_MAX){
            int maxDistance = preCritInd - firstCritInd ;
            ans = {minDistance  , maxDistance} ;
        }
        return ans;
    }
};