class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *head_traverse = new ListNode(0);
        ListNode *head_store = head_traverse;
        head_traverse ->next = head;
        while(head_traverse->next != nullptr)
        {
            if(head_traverse->next->val == val)
            {
                ListNode*temp = head_traverse->next;
                head_traverse->next = head_traverse->next->next;
                delete temp;
            }
            else
            {
                head_traverse = head_traverse->next;
            }
        }
        head_store = head_store->next;
        return head_store;
        
        
        
    }
};


//! 递归的思路去做
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};

