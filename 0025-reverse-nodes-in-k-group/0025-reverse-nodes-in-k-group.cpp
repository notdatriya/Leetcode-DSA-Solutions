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
    ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL)return head;

    ListNode* curr=head;
    ListNode* prev=NULL;
    ListNode* nextptr;
    while(curr){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    return prev;
}
    
    ListNode* findkthnode(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL  && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevnode=NULL;
        while(temp){
            ListNode* kthnode=findkthnode(temp,k);
            
            if(kthnode==NULL){
                if(prevnode)prevnode->next=temp;
                break;
            }
            else{
                ListNode* nextnode=kthnode->next;
                kthnode->next=NULL;
                reverse(temp);
                if(temp==head){
                    head=kthnode;
                }
                else{
                    prevnode->next=kthnode;
                }
                prevnode=temp;
                temp=nextnode;
                
                
            }
        }
        return head;
    }
};