class Solution {
public:
    unordered_map<int, int> map;
    int climbStairs(int n) {
        if (n < 1) return 0;

        map[1] = 1;
        map[2] = 2;

        return climb(n);
    }
    int climb(int n){
        if (map.count(n) == 0)
        {
            int data = climbStairs(n-1) + climbStairs(n-2);
            map[n] = data;
            return data;
        }
        else
        {
            return map[n];
        }
    }
};
