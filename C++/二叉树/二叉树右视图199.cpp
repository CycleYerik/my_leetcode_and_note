class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> my_node_queue;
        vector<int>result;

        if(root != NULL)
        {
            my_node_queue.push(root);
        }
        while(my_node_queue.empty() != 1)
        {
            int size = my_node_queue.size();
            for(int i = 0 ; i < size; i ++)
            {
                TreeNode* temp_node = my_node_queue.front();
                my_node_queue.pop();
                if( i ==( size -1))
                {
                    result.push_back(temp_node->val);
                }
                if(temp_node->left)
                {
                    my_node_queue.push(temp_node->left);
                }
                if(temp_node->right)
                {
                    my_node_queue.push(temp_node->right);
                }
            }
        }
        return result;
    }
};
