class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s(nums.begin(), nums.end());
        int ans=0;
        for(int i=0; i<nums.size(); i++) {
            if(s.count(nums[i]-1))
            continue;
            int count = 1;
            int current = nums[i];
            while(s.count(current+1)) {
                count++;
                current++;
            }
            ans=max(ans, count);
        }
        return ans;   
    }
};
