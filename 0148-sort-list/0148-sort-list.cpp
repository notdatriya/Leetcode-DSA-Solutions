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
    
    ListNode* findmiddle(ListNode* head){
        if(head==NULL || head->next==NULL)return head;
        
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode* dummy=new ListNode(-1);
        
        ListNode* temp=dummy;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                temp->next=list1;
                temp=temp->next;
                list1=list1->next;
            }
            
            else{
               temp->next=list2;
                temp=temp->next;
                list2=list2->next; 
            }
        }
        
        if(list1)temp->next=list1;
        else temp->next=list2;
        
        return dummy->next;
        
    }
    
    ListNode* sortList(ListNode* head) {
        
//         vector<int>arr;
//         ListNode* temp=head;
//         while(temp){
//             arr.push_back(temp->val);
//             temp=temp->next;
//         }
        
//         sort(arr.begin(),arr.end());
        
//         temp=head;
//         int i=0;
//         while(temp){
//             temp->val=arr[i++];
//             temp=temp->next;
//         }
//         return head;
        
        
        //m-2  merge sort on ll
        
        if(head==NULL || head->next==NULL)return head;
        
        ListNode* middle=findmiddle(head);
        ListNode* lefthead=head;
        ListNode* righthead=middle->next;
        middle->next=NULL;
        
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        
        return merge(lefthead,righthead);
    }
};