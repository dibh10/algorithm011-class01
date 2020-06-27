class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;

        vector<int> num(m, 0);
        int i = 0, j = 0, idx = 0;

        for (i = 0; i < m; i++)
        {
            num[i] = nums1[i];
        }

        i = 0;
        while (i < m && j < n)
        {
            if (num[i] < nums2[j])
            {
                nums1[idx++] = num[i];
                i++;
            }
            else
            {
                nums1[idx++] = nums2[j];
                j++;
            }
        }

        while (i < m)
        {
            nums1[idx++] = num[i];
            i++;
        }
        while (j < n)
        {
            nums1[idx++] = nums2[j];
            j++;
        }
    }
};