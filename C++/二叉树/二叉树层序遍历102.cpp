class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> my_node_queue;
        vector<vector<int>>result;
        //先判断根节点的情况
        if(root != NULL)
        {
            my_node_queue.push(root);
        }

        //对队列中的每个节点进行遍历
        while(my_node_queue.empty() != 1)
        {
            int queue_size = my_node_queue.size(); //每一层的节点数量
            vector<int> temp_result;
            for(int i = 0 ; i < queue_size; i ++) // 用固定的size，而不是my_node_queue.size()，因为my_node_queue.size()是变化的
            {
                TreeNode* temp_node = my_node_queue.front();
                my_node_queue.pop();
                temp_result.push_back(temp_node->val);
                if(temp_node->left != NULL)
                {
                    my_node_queue.push(temp_node->left);
                }
                if(temp_node->right != NULL)
                {
                    my_node_queue.push(temp_node->right);
                }
            }
            result.push_back(temp_result);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        reverse(result.begin(), result.end()); // 在这里反转一下数组即可
        return result;

    }
};