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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0 ;
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = head;
        while(temp!= NULL){
            temp = temp->next;
            cnt++;
        }

        int nn = cnt - n;
        temp = dummy;

        for(int i = 0; i<nn; i++){
            temp = temp->next;
        }

        ListNode* toDel = temp->next;
        temp->next=  temp->next->next; 
        delete toDel ;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;

    }
};