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
        ListNode*temp=head;
        if(head==NULL){
            return NULL;
        }
        
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        
        int pos=count-n;

        ListNode*temp2=head;
        ListNode *prev=NULL;
        while( pos-- ){
            prev=temp2;
            temp2=temp2->next;
        }
        
        if(prev==NULL){
            head=head->next;
            return head;
        }
        ListNode* node2=prev->next;
        prev->next=prev->next->next;
        delete node2;
        
        return head;
        
    }
};