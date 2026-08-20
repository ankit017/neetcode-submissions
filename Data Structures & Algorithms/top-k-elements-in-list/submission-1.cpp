class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }

        using Entry = pair<int,int>;
        priority_queue<Entry, vector<Entry>, greater<Entry>>   minHeap;

        for(auto it=mp.begin(); it!=mp.end(); it++) {
            minHeap.push({it->second, it->first});

            if(minHeap.size()>k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        result.reserve(k);

        while(!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;

    }
};
