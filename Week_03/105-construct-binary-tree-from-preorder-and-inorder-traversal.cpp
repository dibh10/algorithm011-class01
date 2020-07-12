/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }

        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& preorder, int preleft, int preright, vector<int>& inorder, int inleft, int inright)
    {
        if (preleft > preright || inleft > inright) return NULL;

        int pivot = preorder[preleft];
        int pivotidx = map[pivot];
        int leftlen = pivotidx - inleft;

        TreeNode* root = new TreeNode(pivot);

        root->left = buildTree(preorder, preleft + 1, preleft + leftlen, inorder, inleft, pivotidx - 1);
        root->right = buildTree(preorder, preleft + leftlen + 1, preright, inorder, pivotidx + 1, inright);

        return root;
    }
};
