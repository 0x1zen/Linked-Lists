

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        ListNode* current1 = list1;
        ListNode* current2 = list2;

        while(current1 != nullptr && current2 != nullptr) 
        {
            int value = 0;
            if(current1->val <= current2->val)
            {
                value = current1->val;
                current1 = current1->next;
            }
            else 
            {
                value = current2->val;
                current2 = current2->next;
            }
            ListNode* tmp = new ListNode(value);
            current->next = tmp;
            current = current->next;
        }

        if(current1 != nullptr) current->next = current1;
        else if(current2 != nullptr) current->next = current2;

        return dummy->next;
    }
};