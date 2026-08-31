class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
            maintain count of characters in s1, length of s1 becomes 
            sliding window length. Maintain this sliding window in S2 
            and check if the character count matches as that of S1
            If Yes, return true at last return false
        */

        array<int, 26> freq1{};
        array<int, 26> freq2{};
        for(int i=0; i<s1.size(); i++) {
            freq1[s1[i]-'a']++;
        }
        int k = s1.size();
        int n = s2.size();
        int l=0, r=0;
        while(r<n) {
            if(r-l+1 > k) {
                freq2[s2[l]-'a']--;
                l++;
            }  
            freq2[s2[r]-'a']++;
            if(r-l+1 == k) {
                if(freq1 == freq2) {
                    return true;
                }
            }
            r++;
        }
        return false;
        
    }
};
