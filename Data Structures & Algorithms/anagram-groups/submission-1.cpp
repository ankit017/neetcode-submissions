class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for(string s: strs){
            int freq[26]={0};
            for(char ch: s) {
                freq[ch-'a']++;
            }
            string key;
            for(int count: freq) {
                key+='#';
                key+=to_string(count);
            }
            
            mp[key].push_back(s);
        }

        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};
