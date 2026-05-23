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



class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {

            ListNode* result = new ListNode(0);
            result -> next = head;

            if(head == NULL)
            {
                return NULL;
            }
            if(head->next == NULL)
            {
                return head;
            }

            ListNode* p = result;
            ListNode* c = head;
            ListNode* n = head->next;

            while(c != NULL && n != NULL)
            {
                ListNode* temp = n->next;
                p->next = n;
                n->next = c;
                c->next = temp;


                p = c;
                c = c->next;
                if(c != NULL)
                {
                    n = c->next;
                }
                else
                {
                    n = NULL;
                }
        


            }
            return result->next;

        }
    };


//递归实现 - 使用辅助函数
class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if(head == NULL || head->next == NULL)
            {
                return head;
            }
            // 直接调用辅助函数交换第一对节点
            return my_swap(head, head->next);
        }

        ListNode* my_swap(ListNode* cur, ListNode* net)
        {
            // 如果第二个节点为空，返回第一个节点
            if(net == NULL)
            {
                return cur;
            }
            
            // 保存下一对节点的起始位置
            ListNode* nextPair = net->next;
            
            // 交换当前两个节点：net 指向 cur
            net->next = cur;
            
            // 递归处理后面的节点对
            if(nextPair != NULL && nextPair->next != NULL)
            {
                // 如果后面还有成对的节点，递归交换
                cur->next = my_swap(nextPair, nextPair->next);
            }
            else
            {
                // 如果后面没有成对的节点，直接连接剩余节点
                cur->next = nextPair;
            }
            
            // 返回交换后的头节点（原来的第二个节点）
            return net;
        }
    };