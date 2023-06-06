/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       map<Node*,Node*>mpp;
        Node*temp=head;
        while(temp!=NULL){
            mpp[temp]=new Node(temp->val);
            temp=temp->next;
        }
        
        temp=head;
        while(temp!=NULL){
            mpp[temp]->next=(temp->next!=NULL)?mpp[temp->next]:NULL;
            mpp[temp]->random=(temp->random!=NULL)?mpp[temp->random]:NULL;
            temp=temp->next;
        }
        
        return mpp[head];
        
        //time complexity-O(n)+O(n);
        //space-O(n);
        
        //there is optimal solution as well, check article
        
        
        
        
    }
};