class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* current=head;
        
        while(current!=NULL){
            ListNode* next=current->next;
            current->next=prev;
            prev=current;
            current=next;
            
        }
        return prev;
    }
};