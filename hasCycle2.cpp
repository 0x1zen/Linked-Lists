
    ListNode* traverseLL(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        
        slow = head;
        
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
    class Solution {
    public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        return traverseLL(head);
    }
};