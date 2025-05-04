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
        vector<int> rightSideView(TreeNode* root) {
            vector<int> result;
            queue<TreeNode*> myQueue;
    
            if (root != nullptr)
                myQueue.push(root);
            
            while (!myQueue.empty()) {
                int length = myQueue.size();
                for (int i = 0; i < length; i++) {
                    TreeNode* cur = myQueue.front();
                    myQueue.pop();
                    if (i == 0)
                        result.push_back(cur->val);
    
                    if (cur->right != nullptr)
                        myQueue.push(cur->right);   
                    if (cur->left != nullptr)
                        myQueue.push(cur->left);   
                }
            }
    
            return result;
        }
    };
    