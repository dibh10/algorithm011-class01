class Solution {
public:
    bool isPowerOfTwo(int n) {
        long x = n;
        return x != 0 && (x & (x-1)) == 0;
    }
};