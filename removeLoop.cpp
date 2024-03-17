void traverseLL(ListNode* head, ListNode* &slow, ListNode* fast) {
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    // Check if there's no cycle
    if (fast == nullptr || fast->next == nullptr) {
        slow = nullptr;
        return;
    }

    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
}

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;
        
        traverseLL(head, slow, fast);

        ListNode* temp = head;
        while (temp != slow) {
            temp = temp->next;
            slow = slow->next;
        }
        temp = head;
        while (temp->next != slow) {
            temp = temp->next;
        }
        temp->next = nullptr;

        return head;
    }
};
