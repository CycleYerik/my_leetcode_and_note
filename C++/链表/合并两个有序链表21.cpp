// 非递减顺序
// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
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

// 原始的迭代
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* run_head = new ListNode(0);
        ListNode* new_head = run_head;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                run_head->next = list1;
                list1 = list1->next;
            }
            else
            {
                run_head->next = list2;
                list2 = list2->next;
            }
            run_head = run_head->next;
        }
        while(list1 != nullptr)
        {
            run_head->next = list1;
            list1 = list1->next;
            run_head = run_head->next;
        }
        while(list2 != nullptr)
        {
            run_head->next = list2;
            list2 = list2->next;
            run_head = run_head->next;
        }
        new_head = new_head->next;

        
        return new_head;

    }
};

// 优化后的迭代
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        curr->next = (list1 != nullptr) ? list1 : list2;
        
        ListNode* new_head = dummy->next;
        delete dummy;
        
        return new_head;
    }
}

// 递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
