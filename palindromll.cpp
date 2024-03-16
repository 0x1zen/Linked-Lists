

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* middleNodeFn(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
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
    bool compareList(ListNode* &head,ListNode* &head2){
        while(head!=NULL && head2!=NULL){
            if(head->val!=head2->val){
                return false;
            }
            else{
                head=head->next;
                head2=head2->next;
            }
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        // break into two halves
        ListNode* middleNode=middleNodeFn(head);
        ListNode* head2=middleNode->next;
        middleNode->next=NULL;
        // reverse the second half
        head2=reverseList(head2);
        bool ans=compareList(head,head2);
        return ans;
    }
};