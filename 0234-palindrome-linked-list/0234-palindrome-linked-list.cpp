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
    bool isPalindrome(ListNode* head) {
        
        //brute force- convert ll into array or vector and chek palindrome in vector
        //space-O(n);
        //time-O(n)
        
        //Optimal-find middle of ll and reverse the right half and compare both halfs;
        //time-O(3n/2) space-O(1)
        
        if(head==NULL || head->next==NULL){
            return true;
        }
        
       ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){ //for first middle
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode*prevptr=NULL;
        ListNode*currptr=slow->next;
        ListNode*nextptr;
        while(currptr!=NULL){
            nextptr=currptr->next;
            currptr->next=prevptr;
            
            prevptr=currptr;
            currptr=nextptr;
        }
        slow->next=prevptr;
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val){
                return false;
            }
            slow=slow->next;
            head=head->next;
        }
        return true;
        
        
    
    }
};