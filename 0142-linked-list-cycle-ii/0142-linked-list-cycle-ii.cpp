/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        //bruet force is to use hashing
        //optimal-fast and slow pointer
        
        
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode*fast=head;
        
        
            //intuition behind this below- lets say they met at distance l2 from starting point 
        //of cycle, and l1 is the dist. of head to cycle starting point. slow ptr moved l1+l2 dist and fast have moved l1+l2+nc dist where c is the length of cycle , as we know fast moved twice, l1+l2+nc=2(l1+l2) .this giver
        // l1+l2=nc 
        //l1=nc-l2   nc-l2 is rem. dist by slow pointer to reach point starting cycle
       
        
        while( fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                fast=head;
           while(fast!=slow){
               fast=fast->next;
               slow=slow->next;
           }
           return slow;
            }
        }
        
      return NULL;
        
    
           
       
        
        
    }
};