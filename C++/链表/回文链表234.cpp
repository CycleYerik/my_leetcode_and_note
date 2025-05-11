// 回文链表
// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

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

// 栈做法
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> stack_value;
        ListNode * all_node = head;
        int length = 0;
        while(all_node != nullptr)
        {
            length ++;
            all_node = all_node->next;
        }
        if(length == 1)
        {
            return true;
        }
        ListNode * stack_node = head;
        if(length%2 == 0)
        {
            for(int count = 0; count < length/2; count++)
            {
                stack_value.push_back(stack_node->val);
                stack_node = stack_node->next;
            }
            while(stack_node != nullptr)
            {
                int temp = stack_value.back();
                stack_value.pop_back();
                if(temp != stack_node->val)
                {
                    return false;
                }
                stack_node = stack_node->next;
            }
            return true;
        }
        else
        {
            for(int count = 0; count < length/2; count++)
            {
                stack_value.push_back(stack_node->val);
                stack_node = stack_node->next;
            }
            stack_node = stack_node->next;
            while(stack_node != nullptr)
            {
                int temp = stack_value.back();
                stack_value.pop_back();
                if(temp != stack_node->val)
                {
                    return false;
                }
                stack_node = stack_node->next;
            }
            return true;
        } 
        
    }
};

// 栈做法简化版
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stack;
        ListNode* p = head;
        while (p != nullptr) {
            stack.push(p->val);
            p = p->next;
        }
        p = head;
        while (p != nullptr) {
            if (p->val != stack.top())
                return false;
            stack.pop();
            p = p->next;
        }
        return true;
    }
};


// 还可以直接把链表的值复制到数组中，然后用双指针法
// 双指针法
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        ListNode* p = head;
        while (p != nullptr) {
            values.push_back(p->val);
            p = p->next;
        }
        int left = 0;
        int right = values.size() - 1;
        while (left < right) {
            if (values[left] != values[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};


// 还有递归做法：
class Solution {
public:
    ListNode* frontPointer;
    bool recursivelyCheck(ListNode* currentNode) {
        if (currentNode != nullptr) {
            if (!recursivelyCheck(currentNode->next)) {
                return false;
            }
            if (currentNode->val != frontPointer->val) {
                return false;
            }
            frontPointer = frontPointer->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
};

// 双指针法
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        // 找到前半部分链表的尾节点并反转后半部分链表
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        // 判断是否回文
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }        

        // 还原链表并返回结果
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

