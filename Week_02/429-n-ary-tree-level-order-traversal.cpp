/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;

        if (root == NULL) return res;

        queue<pair<Node*, int>> Q;
        int idx = 0;

        Q.push(make_pair(root, 1));
        res.push_back(vector<int>{root->val});

        while (!Q.empty())
        {
            root = Q.front().first;
            idx = Q.front().second;
            Q.pop();

            if (root->children.empty()) continue;
            if (idx == res.size()) res.push_back(vector<int>{});

            for (Node *node : root->children)
            {
                if (node)
                {
                    Q.push(make_pair(node, idx+1));
                    res[idx].push_back(node->val);
                }
            }
        }

        return res;
    }
};