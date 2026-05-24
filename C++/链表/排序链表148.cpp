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

//! 快排,但是超时，因为比较的节点选的不好
 class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            return quick_sort(head).first;
        }
    
        pair<ListNode* ,ListNode*> quick_sort(ListNode* head)
        {
            if(head == NULL || head->next == NULL)
            {
                return {head,head};
            }
    
            ListNode less_dummy(0);
            ListNode equal_dummy(0);
            ListNode more_dummy(0);
    
            ListNode* less_tail = &less_dummy;
            ListNode* equal_tail = &equal_dummy;
            ListNode* more_tail = &more_dummy;
    
            ListNode * temp = head;
            while(temp)
            {
                if(temp->val > head->val)
                {
                    more_tail->next = temp;
                    more_tail = more_tail->next;
                }
                else if(temp->val < head->val)
                {
                    less_tail->next = temp;
                    less_tail = less_tail->next;
                }
                else // temp->val == head->val
                {
                    equal_tail->next = temp;
                    equal_tail = equal_tail->next;
                }
                temp = temp->next;
            }
    
            // 遍历结束后断开末尾，同样使用 _tail 指针
            more_tail->next = nullptr;
            equal_tail->next = nullptr;
            less_tail->next = nullptr;
    
            auto left_result = quick_sort(less_dummy.next);
            auto right_result = quick_sort(more_dummy.next);
    
            ListNode* final_head = nullptr;
            ListNode* final_tail = nullptr;
    
            // 1. 拼接左边和中间
            if (left_result.first)
            {
                final_head = left_result.first;
                left_result.second->next = equal_dummy.next; // 左边排好序的尾 连上 中间的头
            }
            else
            {
                final_head = equal_dummy.next; // 左边为空，总头就是中间的头
            }
    
            // 2. 拼接中间和右边
            equal_tail->next = right_result.first; // 中间的尾 连上 右边排好序的头
    
            // 3. 确定总尾
            if (right_result.second)
            {
                final_tail = right_result.second;
            }
            else
            {
                final_tail = equal_tail; // 右边为空，总尾就是中间的尾
            }
    
            return {final_head, final_tail};
    
        }
    };




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



//! 归并排序 
class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            
            if(!head || !head->next)
            {
                return head;
            }
    
            ListNode* mid = cult_half(head);
    
            ListNode* left = sortList(head);
            ListNode* right = sortList(mid);
    
            return merge(left,right);
    
    
    
        }
    
        ListNode* cult_half(ListNode* head)
        {
            ListNode* slow = head;
            ListNode* fast = head->next;
    
            while(fast && fast->next)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
    
            ListNode* right_head = slow->next;
            slow->next = NULL;
            return right_head;
            
        }
    
        ListNode* merge(ListNode* head1, ListNode* head2)
        {
            ListNode dummy(0);
            ListNode* tail = &dummy;
    
            while(head1 && head2)
            {
                if(head1->val >= head2->val)
                {
                    tail->next = head2;
                    tail = tail->next;
                    head2 = head2->next;
                }
                else
                {
                    tail->next = head1;
                    tail = tail->next;
                    head1 = head1->next;
                }
            }
            if(head1)
            {
                tail ->next = head1;
            }
            if(head2)
            {
                tail ->next =   head2;
            }
            return dummy.next;
        }
    
    
    
        
    };