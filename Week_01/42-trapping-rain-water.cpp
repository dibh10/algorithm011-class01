class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int i = 0, top = 0, h = 0, len = 0, res = 0;
        stack<int> st;

        for (i = 0; i < height.size(); i++)
        {
            while (!st.empty() && height[i] > height[st.top()])
            {
                top = st.top();
                st.pop();

                if (st.empty()) break;

                len = i - st.top() - 1;
                h = min(height[i], height[st.top()]) - height[top];
                res += h * len;
            }
            st.push(i);
        }

        return res;
    }
};