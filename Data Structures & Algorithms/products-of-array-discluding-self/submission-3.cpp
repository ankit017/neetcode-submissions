class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        // vector<int> left(n,0);
        // vector<int> right(n,0);
        vector<int> ans(n,0);

        ans[0]=1;
        for(int i=1; i<n; i++) {
            ans[i] = ans[i-1]*nums[i-1];
        }
        int rightProduct = 1;

        for(int i=n-1; i>=0; i--) {
            ans[i] = rightProduct*ans[i];
            rightProduct*=nums[i];
        }
        return ans;

    }
};
