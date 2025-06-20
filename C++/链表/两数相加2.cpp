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