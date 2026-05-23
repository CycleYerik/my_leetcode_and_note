/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) return t2; // 如果t1为空，合并之后就应该是t2
        if (t2 == NULL) return t1; // 如果t2为空，合并之后就应该是t1
        // 修改了t1的数值和结构
        t1->val += t2->val;                             // 中
        t1->left = mergeTrees(t1->left, t2->left);      // 左
        t1->right = mergeTrees(t1->right, t2->right);   // 右
        return t1;
    }
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;

        queue<TreeNode*> my_queue;

        my_queue.push(root1);
        my_queue.push(root2);

        while(my_queue.empty() != 1)
        {
            TreeNode* temp1 = my_queue.front();
            my_queue.pop();
            TreeNode* temp2 = my_queue.front();
            my_queue.pop();

            temp1->val += temp2->val;

            if(temp1->left && temp2->left)
            {
                my_queue.push(temp1->left);
                my_queue.push(temp2->left);
            }

            if(temp1->right && temp2->right)
            {
                my_queue.push(temp1->right);
                my_queue.push(temp2->right);
            }

            if(temp1->left == NULL && temp2->left != NULL)
            {
                temp1->left = temp2->left;
            }

            if(temp1->right == NULL && temp2->right != NULL)
            {
                temp1->right = temp2->right;
            }



        }
        return root1;


    }
};