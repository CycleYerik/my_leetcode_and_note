// 链表反转
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

// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。


// 迭代做法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next; // 保存下一个节点
            curr->next = prev; // 反转当前节点的指针
            prev = curr; // 更新 prev 为当前节点
            curr = next; // 移动到下一个节点
        }
        return prev; // prev 是新链表的头节点
    }
};