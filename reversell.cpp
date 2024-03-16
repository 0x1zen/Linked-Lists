class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* current=head;
        
        while(current!=NULL){
            ListNode* nextNode=current->next;
            current->next=prev;
            prev=current;
            current=nextNode;
            
        }
        return prev;
    }
};