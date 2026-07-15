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

// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。】


//所以其实反转链表的核心就是从head开始往后的反转，但是head的next指向了pre，但是不会直接把head->next的next直接指回head，而是在后续进行处理


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


//递归做法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* last = reverseList(head->next); //相当于目前后面的这些都反转好了，返回的是最后一个节点，也就是反转后的头节点
        head->next->next = head; // 把当前节点接在反转后的链表的末尾
        head->next = nullptr;
        return last;
    }
};



class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if(head->next == null)
            {
                return head;
            }
            ListNode* last_node = NULL;
            while(head -> next != NULL)
            {
                ListNode* temp_next = head->next;
                head->next = last_node;
                last_node = head;
                head = temp_next;
            }
            return head;
    
    
        }
    };

