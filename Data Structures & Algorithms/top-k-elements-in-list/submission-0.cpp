class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<pair<int,int>> ans;
        vector<int> result;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }

        for(auto it=mp.begin(); it!=mp.end(); it++) {
            ans.push_back({it->first, it->second});
        }

        sort(ans.begin(), ans.end(),
     [](const auto& a, const auto& b) {
         return a.second > b.second;
     });

        for(int i=0; i<k; i++) {
            result.push_back(ans[i].first);
        }
        return result;
    }
};
