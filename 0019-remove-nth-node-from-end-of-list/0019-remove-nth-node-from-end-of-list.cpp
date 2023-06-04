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
//         ListNode*temp=head;
//         if(head==NULL){
//             return NULL;
//         }
        
//         int count=0;
//         while(temp!=NULL){
//             count++;
//             temp=temp->next;
//         }
        
//         int pos=count-n;

//         ListNode*temp2=head;
//         ListNode *prev=NULL;
//         while( pos-- ){
//             prev=temp2;
//             temp2=temp2->next;
//         }
        
//         if(prev==NULL){
//             head=head->next;
//             return head;
//         }
//         ListNode* node2=prev->next;
//         prev->next=prev->next->next;
//         delete node2;
        
//         return head;
        
    //Here time-O(2n) and space-O(1)
        
        //optimal approach- use slow and fast poniter
        //move fast pointer to n steps, now fast will be k-n+1 steps away from the last node
        //those k-n+1 steps will be covered by slow pointer
        
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }
        
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        
        ListNode* todelete=slow->next;
        slow->next=slow->next->next;
        delete todelete;
        return dummy->next;
        
    }
};