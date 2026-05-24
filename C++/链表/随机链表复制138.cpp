/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//! 映射
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        // 核心思路：通过“位置索引”作为中介，建立旧链表与新链表之间的定位通路。
        // oldNodeToIndex: 记录原链表中每个节点地址与其对应的 0 进制索引位置。
        //                 这样当遇到 random 指针时，能通过其指向的旧节点地址，直接查出目标位置。
        // indexToNewNode: 记录每个位置索引对应的新节点地址。
        //                 有了目标位置后，可以通过 O(1) 的 vector 随机访问直接定位到相应的新节点。
        std::unordered_map<Node*, int> oldNodeToIndex;
        std::vector<Node*> indexToNewNode;

        // 使用哨兵节点（Dummy Node）可以统一新链表节点的创建和拼接逻辑，
        // 避免了在循环中对“头节点是否为空”进行特殊的条件判断，让代码更加简洁健壮。
        Node* dummy = new Node(0);
        Node* newTail = dummy;

        Node* oldCurr = head;
        int currentIndex = 0;

        // 【第一遍遍历】：复制基础链表骨架（next 指针），并建立所有的双重索引关系
        while (oldCurr != nullptr) {
            Node* newNode = new Node(oldCurr->val);
            newTail->next = newNode;

            // 登记“旧节点地址 -> 位置索引”
            oldNodeToIndex[oldCurr] = currentIndex;
            // 登记“位置索引 -> 新节点地址”
            indexToNewNode.push_back(newNode);

            newTail = newTail->next;
            oldCurr = oldCurr->next;
            currentIndex++;
        }

        Node* newHead = dummy->next;

        // 堆上申请的哨兵节点在链表构建完成后已完成使命，
        // 在返回前必须手动 delete 释放，防止产生内存泄漏。
        delete dummy;

        // 【第二遍遍历】：填充新链表中的 random 指针关系
        oldCurr = head;
        Node* newCurr = newHead;

        while (oldCurr != nullptr) {
            if (oldCurr->random == nullptr) {
                newCurr->random = nullptr;
            } else {
                // 利用双重映射通路：旧 random 目标节点 -> 目标索引位置 -> 新 random 目标节点
                int targetIndex = oldNodeToIndex[oldCurr->random];
                newCurr->random = indexToNewNode[targetIndex];
            }

            oldCurr = oldCurr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};
