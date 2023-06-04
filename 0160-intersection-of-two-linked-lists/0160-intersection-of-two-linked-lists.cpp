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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //brute force is to use two loops, iterate and find,if any node matches,then return;
        //time-O(m*n) space-O(1)
        
        //better-Use hashset,store all nodes of 1 ll and, then iterate over second linkedlist and find if that node exists in set, then return;
        //Time-O(m+n); space-O(n);
        
        //optimal - 1st method
        //simultaneously find length of both arrays,let length of bigger array-m and shorter
        // n . then we will move the longer ll pointer to m-n steps,then simultaneously iterate and check when temp1=temp2,and return ans, if becomes null,return null;
        //time- O(m)+O(m-n)+O(n); space-O(1)
        
        
        //2nd best optimal solution
        
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        
        ListNode*a=headA;
        ListNode*b=headB;
        
        while(a!=b){
            a=a==NULL?headB:a->next;
            b=b==NULL?headA:b->next;
        }
        return a;
    }
};