class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();
        int left;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for(int i=0;i<n;i++) {
            pq.push({nums[i], i});
            left = i-k+1;

            while(!pq.empty() && pq.top().second<left) {
                pq.pop();
            }

            if(i>=k-1) {
                ans.push_back(pq.top().first);
            }

        }
        
        return ans;
       
    }
};
