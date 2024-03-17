
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
            if(fast!=NULL && fast==slow){
                return true;
            }
            
        }

        return false;
    }
}; 