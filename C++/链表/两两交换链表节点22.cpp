/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//两两交换链表节点
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* store_head = dummy_head;
        if( dummy_head-> next == NULL)
        {
            return head;
        }
        if(dummy_head->next->next == NULL)
        {
            return head;
        }
        while(dummy_head->next != NULL && dummy_head->next->next != NULL)
        {
            ListNode* now = dummy_head->next;
            ListNode* now_next = dummy_head->next->next;
            dummy_head->next = now_next;
            now->next = now_next->next;
            now_next->next = now;
            dummy_head = now;
        }
        return store_head->next;
    }
};


//递归

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};
