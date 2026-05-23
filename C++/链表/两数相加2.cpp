

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode(0); // 虚拟头节点
            ListNode* curr = dummy;
            int carry = 0; // 进位
    
            // 只要 l1 没走完，或者 l2 没走完，或者还有进位，就继续循环
            while (l1 != NULL || l2 != NULL || carry != 0) {
                int sum = carry; // 先加上进位
                
                if (l1 != NULL) {
                    sum += l1->val;
                    l1 = l1->next;
                }
                if (l2 != NULL) {
                    sum += l2->val;
                    l2 = l2->next;
                }
    
                carry = sum / 10; // 计算新进位
                curr->next = new ListNode(sum % 10); // 创建新节点存放个位数
                curr = curr->next;
            }
    
            return dummy->next;
        }
    };

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *head = nullptr, *tail = nullptr;
            int carry = 0;
            while (l1 || l2) {
                int n1 = l1 ? l1->val: 0;
                int n2 = l2 ? l2->val: 0;
                int sum = n1 + n2 + carry;
                if (!head) {
                    head = tail = new ListNode(sum % 10);
                } else {
                    tail->next = new ListNode(sum % 10);
                    tail = tail->next;
                }
                carry = sum / 10;
                if (l1) {
                    l1 = l1->next;
                }
                if (l2) {
                    l2 = l2->next;
                }
            }
            if (carry > 0) {
                tail->next = new ListNode(carry);
            }
            return head;
        }
    };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum_low = 0, sum_high = 0;
        ListNode* node_1_head = new ListNode(0);
        ListNode* node_2_head = new ListNode(0);
        ListNode* result_head = new ListNode(0);
        ListNode * result = result_head;
        node_1_head->next = l1;
        node_2_head->next = l2;
        node_1_head = node_1_head->next;
        node_2_head = node_2_head->next;

        while(node_1_head != NULL || node_2_head != NULL)
        {
            
            int n1_num = node_1_head? node_1_head->val:0;
            int n2_num = node_2_head? node_2_head->val:0;

            if(n1_num+ n2_num + sum_high >= 10 )
            {
                sum_low = n1_num+ n2_num + sum_high -10;
                sum_high = 1;
            }
            else
            {
                sum_low = n1_num+ n2_num +sum_high ;
                sum_high = 0;
            }
            ListNode* new_head = new ListNode(sum_low);
            result_head->next = new_head;
            result_head = result_head->next;

            if(node_1_head)
            {
                node_1_head = node_1_head->next;
            }
            if(node_2_head)
            {
                node_2_head = node_2_head->next;
            }
            
        }
        if(sum_high != 0)
        {
            ListNode* temp_node = new ListNode(sum_high);
            result_head->next = temp_node;
        }
        

        return result->next;

    }
};