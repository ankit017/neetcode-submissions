class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> needs;
        unordered_map<char, int> have;

        for(int i=0; i<t.size(); i++){
            needs[t[i]]++;
        }

        for(auto it=needs.begin(); it!=needs.end(); it++) {
            have[it->first] = 0;
        }

        int count = needs.size();
        int dc = 0;
        int minLen = INT_MAX;
        string ans = "";

        int l=0, r=0;
        for(int r=0; r<s.size(); r++) {
            if(needs.contains(s[r])) {
                if(have[s[r]] >= needs[s[r]]) {
                    have[s[r]]++;
                }
                else {
                    have[s[r]]++;
                    if(have[s[r]] == needs[s[r]]) {
                        dc++;
                    }
                }
                if(dc == count) {

                    while(l<=r) {
                        if(needs.contains(s[l])) {
                            if(have[s[l]] == needs[s[l]]) {
                                if(r-l+1 < minLen) {
                                    minLen = r-l+1;
                                    ans= s.substr(l,r-l+1);
                                }
                                have[s[l]]--;
                                dc--;
                                l++;
                                break;
                            }
                            else {
                                have[s[l]]--;
                                l++;
                            } 
                        }
                        else {
                            l++;
                        }
                        
                    }
                    
                }

            }
        }
        return ans;  
    }
};
