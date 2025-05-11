// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
// 暴力求解
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * heada = headA;
        while(heada->next != NULL)
        {
            ListNode * headb = headB;
            while(headb != NULL)
            {
                if(headb == heada)
                {
                    return heada;
                }
                else
                {
                    headb = headb->next;
                }
            }
            heada = heada->next;
        }
        return NULL;
    }
};

// 还可以双指针一直走，A走完就走B，B走完就走A，如果有相同的节点，那么就是交点，如果都走到了NULL，那么就是没有交点， 复杂度为m+n， 空间复杂度为1

// 还可以哈希表，把A都存到哈希表里，然后遍历B，如果有相同的节点，那么就是交点， 复杂度为m+n， 空间复杂度为m

// 长的链表先走，然后两个链表一起走，如果有相同的节点，那么就是交点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length_a = 0 ,length_b = 0;
        ListNode *heada = headA;
        ListNode *headb = headB;
        while(heada != NULL)
        {
            length_a ++;
            heada = heada->next;
        }
        while(headb != NULL)
        {
            length_b ++;
            headb = headb->next;
        }
        ListNode *head_listA = headA;
        ListNode *head_listB = headB;
        int a_move = 0, b_move = 0;
        if(length_a >= length_b)
        {
            a_move = length_a -length_b;
        }
        else
        {
            b_move = length_b - length_a;
        }
        for(int i = a_move; i >0; i--)
        {
            head_listA = head_listA->next;
        }
        for(int i = b_move; i >0; i--)
        {
            head_listB = head_listB->next;
        }
        while(head_listA != NULL && head_listB != NULL)
        {
            if(head_listA == head_listB)
            {
                return head_listA;
            }
            else
            {
                head_listA = head_listA->next;
                head_listB= head_listB->next;
            }
        }
        return NULL;
    }
};