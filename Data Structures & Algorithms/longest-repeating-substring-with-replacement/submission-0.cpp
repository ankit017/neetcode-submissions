class Solution {
public:
    int characterReplacement(string s, int k) {

        /*left = 0, right=0
        while(left<=right && right<n) {
            calculate freq of char
            calculate max freq
            while(r-l+1 - top freq > k) {
            left++;
            recalculate freq;
            }
            update ans;
        }
        */
        int n= s.size();
        int l = 0, r=0;
        int freq[26] = {0};
        int ans=1,maxfreq=1;

        while(l<=r && r<n) {
            freq[s[r] - 'A']++;
            for(int i=0; i<26; i++) {
                maxfreq = max(maxfreq, freq[i]);
            }
            while((r-l+1) - maxfreq > k) {
                freq[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;        
    }
};
