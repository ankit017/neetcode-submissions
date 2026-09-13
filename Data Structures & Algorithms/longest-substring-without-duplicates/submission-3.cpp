class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,l=0;
        unordered_map<char, int> m;
        for(int r=0; r<s.size();r++) {
            if(m.count(s[r])) {
                l=max(l, m[s[r]]+1);
                
            }
            m[s[r]] = r;
            ans=max(ans,r-l+1);

        }
        return ans;
        
    }
};
