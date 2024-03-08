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
    ListNode* middleNode(ListNode* head) {
//         int length=0;
//         ListNode*temp=head;
//         while(temp!=NULL){
//             length++;
//             temp=temp->next;
//         }
        
//         ListNode* temp2=head;
//         if(length%2==0){
//             length=(length/2)+1;
            
//         }
//         else{
//             length=(length+1)/2;
//         }
//         length--;
        
//         while(length--){
//             temp2=temp2->next;
//         }
    
        //return temp2;
        //Time-O(n)+O(n/2) space-O(1)
        
        
        
        
        
//     //Optimal - Time-O(n/2) space-O(1)
    
    
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    
    }
    
    
    
};