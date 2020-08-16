class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int len1 = arr1.size(), len2 = arr2.size();
        int i = 0, j = 0;

        int map[1001] = {0};
        for (i = 0; i < len1; i++)
        {
            map[arr1[i]]++;
        }
        for (i = 0; i < len2; i++)
        {
            while (map[arr2[i]] > 0)
            {
                arr1[j++] = arr2[i];
                map[arr2[i]]--;
            }
        }
        for (i = 0; i < 1001; i++)
        {
            while (map[i] > 0)
            {
                arr1[j++] = i;
                map[i]--;
            }
        }

        return arr1;
    }
};