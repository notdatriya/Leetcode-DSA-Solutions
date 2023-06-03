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
        
//         ListNode* temp1=list1;
//         ListNode *temp2=list2;
//         ListNode*dummy=new ListNode(-1);
//         ListNode*list3 =dummy;
//         while(temp1!=NULL && temp2!=NULL){
//             if(temp1->val<temp2->val){
//                 list3->next=temp1;
//                 temp1=temp1->next;
//             }
//             else{
//                  list3->next=temp2;
//                 temp2=temp2->next;
//             }
//             list3=list3->next;
//         }
        
//         while(temp1!=NULL){
//               list3->next=temp1;
//                 temp1=temp1->next;
//             list3=list3->next;
//         }
//          while(temp2!=NULL){
//               list3->next=temp2;
//                 temp2=temp2->next;
//              list3=list3->next;
//         }
//          return dummy->next;
        
        //Time  -O(n+m) Space-O)n+m
        
        //Optimal solution
        //we will break bonds and make new connections
        
        if(list1==NULL) return list2;
        if(list2 ==NULL) return list1;
        
        if(list1->val>list2->val){
            swap(list1,list2);
        }
        
        ListNode * ans=list1;
        while(list1!=NULL && list2!=NULL){
            ListNode*temp=NULL;
            while(list1!=NULL && list1->val<=list2->val ){
                temp=list1;
                list1=list1->next;
            }
            temp->next=list2;
            swap(list1,list2);
        }
        return ans;
    }
   
};