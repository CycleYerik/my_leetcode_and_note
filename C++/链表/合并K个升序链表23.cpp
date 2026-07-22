//! 直接转化为合并两个链表，多次进行
 class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            int n = lists.size();
            if(n == 0)
            {
                return nullptr;
            }
            if(n < 2)
            {
                return lists[0];
            }
            ListNode* dummy = lists[0];
            for(int i = 1 ; i < n ; i++)
            {
                dummy = merge_two_lists(dummy,lists[i]);
            }
            return dummy;
        }
    
        ListNode* merge_two_lists(ListNode* lists1 ,ListNode* lists2)
        {
            ListNode* dummy = new ListNode(0);
            ListNode* temp = dummy;
            while(lists1 != nullptr && lists2 != nullptr)
            {
                if(lists1->val <= lists2->val)
                {
                    temp->next = lists1;
                    lists1 = lists1->next;
                }
                else
                {
                    temp->next = lists2;
                    lists2 = lists2->next;
                }
                temp = temp->next;
            }
            temp->next = (lists1 != nullptr) ? lists1 : lists2;
            ListNode * new_head = dummy->next;
            delete dummy;
            return new_head;
    
        }
    };


//! 最小堆
 class Solution {
    public:
    
        struct Cmp {
            bool operator()(ListNode* a, ListNode* b) const {
                return a->val > b->val;   // 最小堆：val 小的 priority 高
            }
        };
        
    
    
    
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<ListNode*, vector<ListNode*>, Cmp> p_queue;
            int n = lists.size();
            if(n == 0)
            {
                return nullptr;
            }
            if(n < 2)
            {
                return lists[0];
            }
    
            //全部入队
            for(int i = 0 ; i < n ; i++)
            {
                if(lists[i])
                {
                    p_queue.push(lists[i]);
                }
            }
    
            ListNode* head = new ListNode(0);
            ListNode* tail = head;
    
            while(!p_queue.empty())
            {
                tail->next = p_queue.top();
                p_queue.pop();
                tail = tail->next;
                if(tail->next)
                {
                    p_queue.push(tail->next);
                }
            }
            return head->next;
    
        }
    
        
    };


//! 分治（归并）：O(N log k) 时间，O(log k) 递归栈
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            int n = lists.size();
            if (n == 0) {
                return nullptr;
            }
            return merge_range(lists, 0, n - 1);
        }

    private:
        ListNode* merge_range(vector<ListNode*>& lists, int left, int right) {
            if (left == right) {
                return lists[left];
            }
            int mid = left + (right - left) / 2;
            ListNode* l_head = merge_range(lists, left, mid);
            ListNode* r_head = merge_range(lists, mid + 1, right);
            return merge_two_lists(l_head, r_head);
        }

        ListNode* merge_two_lists(ListNode* lists1, ListNode* lists2) {
            ListNode* dummy = new ListNode(0);
            ListNode* temp = dummy;
            while (lists1 != nullptr && lists2 != nullptr) {
                if (lists1->val <= lists2->val) {
                    temp->next = lists1;
                    lists1 = lists1->next;
                } else {
                    temp->next = lists2;
                    lists2 = lists2->next;
                }
                temp = temp->next;
            }
            temp->next = (lists1 != nullptr) ? lists1 : lists2;
            ListNode* new_head = dummy->next;
            delete dummy;
            return new_head;
        }
    };
