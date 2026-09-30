class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int ans=0, count=0;
    unordered_set<int> s;
    for(int n: nums) {
        if(!s.count(n)) {
            s.insert(n);
        }
    }
    for(int n: nums){
        count=1;
        if(s.count(n-1))
        continue;
        int x = n+1;
        while(s.count(x)) {
            count++;
            x++;
        }
        if(count>ans) {
            ans=count;
        }
    }
    return ans;
        
    }
};
