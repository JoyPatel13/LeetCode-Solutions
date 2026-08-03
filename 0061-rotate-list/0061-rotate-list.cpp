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
 ListNode* find(ListNode*head  , int k){
    ListNode*temp = head;
    int cnt =0;
    while(temp!=NULL){
        if(cnt==k){
            return temp ;
        }
        cnt++;
        temp=temp->next;

    }
    return temp ;
 }

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        ListNode* tail = head; 
        int len = 1; 
        while(tail->next!=NULL){
            tail = tail->next;
            len+=1;
        }
        if(k%len == 0) return head;
        k = k%len;

        tail->next = head ;
        ListNode*newlastnode = find(head , len-k-1);
        head = newlastnode->next;
        newlastnode->next = NULL ;
        return head;
    }
};