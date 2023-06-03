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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* temp1=list1;
        ListNode *temp2=list2;
        ListNode*dummy=new ListNode(-1);
        ListNode*list3 =dummy;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<temp2->val){
                list3->next=temp1;
                temp1=temp1->next;
            }
            else{
                 list3->next=temp2;
                temp2=temp2->next;
            }
            list3=list3->next;
        }
        
        while(temp1!=NULL){
              list3->next=temp1;
                temp1=temp1->next;
            list3=list3->next;
        }
         while(temp2!=NULL){
              list3->next=temp2;
                temp2=temp2->next;
             list3=list3->next;
        }
         return dummy->next;
    }
   
};