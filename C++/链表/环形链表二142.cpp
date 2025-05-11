/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode * dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode * slow = dummy_head->next;
        ListNode * fast = dummy_head->next;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) // 相遇，存在环
            {
                ListNode * p = head; //根据数学推导，从头结点开始，和slow指针一起走，相遇的地方就是环的入口
                while(p != slow)
                {
                    p = p->next;
                    slow = slow->next;
                }
                return p;
            }
        }
    return NULL;


    }
};