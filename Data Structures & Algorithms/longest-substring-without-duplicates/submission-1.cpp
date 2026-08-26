class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0,r=0,ans=0,count=0;
        unordered_map<char, int> mp;

        while(r<n) {
            char c = s[r];
            if(mp.contains(c)) {
                l=max(l,mp[c] + 1);
            }
            mp[c] = r;
            count = max(count, r-l+1);
            r++;
        }
        return count;       
    }
};
