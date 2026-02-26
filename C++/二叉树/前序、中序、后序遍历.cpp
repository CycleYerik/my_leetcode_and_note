// 默认用递归很简单
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 迭代法前序遍历
// 这里处理较为简单，因为刚好要处理的数据和节点是对应的，每次处理的数据就是当前节点的值，所以直接处理就行了
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return result;
    }
};



// 迭代法中序遍历
// 思路：用指针 cur 一路向左走到最底（左），弹栈时“中”处理并记录，再转向右子树（右）。栈空且 cur 为空时结束。
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {           // 一路向左访问到底
                st.push(cur);
                cur = cur->left;         // 左
            } else {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);  // 中
                cur = cur->right;            // 右
            }
        }
        return result;
    }
};


// 迭代法后序遍历
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
            if (node->right) st.push(node->right); // 空节点不入栈
        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
};


//! 统一迭代的写法：

// 中序，则右先进，自己再进，左最后进，出来的时候，左先出，自己再出，右最后出
// 前序，则右先进，左再进，自己最后进，出来的时候，右先出，左再出，自己最后出
// 后序，则自己先进，右再进，左最后进，出来的时候，左先出，右再出，自己最后出

//boolean 标记法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<pair<TreeNode*, bool>> st; // 储存节点及其访问状态
        if (root != nullptr)
            st.push(make_pair(root, false)); // 多加一个参数，false 为默认值，含义见下文注释

        while (!st.empty()) {
            auto node = st.top().first;
            auto visited = st.top().second; //多加一个 visited 参数，使“迭代统一写法”成为一件简单的事
            st.pop();

            if (visited) { // visited 为 True，表示该节点和两个儿子位次之前已经安排过了，现在可以收割节点了
                result.push_back(node->val);
                continue;
            }

            // visited 当前为 false, 表示初次访问本节点，此次访问的目的是“把自己和两个儿子在栈中安排好位次”。
            
            // 中序遍历是'左中右'，右儿子最先入栈，最后出栈。
            if (node->right)
                st.push(make_pair(node->right, false));
            
            // 把自己加回到栈中，位置居中。
            // 同时，设置 visited 为 true，表示下次再访问本节点时，允许收割。
            st.push(make_pair(node, true));

            if (node->left)
                st.push(make_pair(node->left, false)); // 左儿子最后入栈，最先出栈
        }
        
        return result;
    }
};