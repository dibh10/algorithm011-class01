class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {

        generate(n, n, "");

        return res;
    }
    void generate(int left, int right, string str)
    {
        if (left == 0 && right == 0)
        {
            res.push_back(str);
            return;
        }

        if (left > 0)
            generate(left-1, right, str+'(');

        if (right > left)
            generate(left, right-1, str+')');
    }
};