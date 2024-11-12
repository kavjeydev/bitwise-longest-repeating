class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        __int128 state = 0b0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
        int longest = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            int idx = int(s[j]) - 1;
            __int128 ret = state & (__int128(1) << idx);
            if (!ret) {
                state ^= __int128(1) << idx;
                longest = max(longest, j - i + 1);
            } 
            else {
                while (ret) {
                    state ^= __int128(1) << ((int(s[i]) - 1));
                    ret = state & (__int128(1) << idx);
                    i++;
                }
                state ^= __int128(1) << idx;
            }
        }

        return longest;
    }
};
