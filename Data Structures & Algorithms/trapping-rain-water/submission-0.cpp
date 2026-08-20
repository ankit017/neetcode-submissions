class Solution {
public:
    int trap(vector<int>& height) {
    /*
    For any bar answer is max(0, min(maxLeftHeight, maxRightHeight)-height[i])
    We calculate leftmax and rightmax as two separate arrays and then use them in the answer

    leftmax[i] = max height of bars strictly lesser than ith index
    rightmax[i] = max height of bars strictly greater than ith index

    leftmax[0]=rightmax[n-1] =0 since there are no bars to the boundary indices
    */

    const int n = height.size();
    vector<int> leftMax(n), rightMax(n);
    int ans = 0;
    leftMax[0]=rightMax[n-1]=0;
    for(int i=1; i<n; i++) {
        leftMax[i] = max(leftMax[i-1], height[i-1]);
    }
    
    for(int i=n-2; i>=0; i--) {
        rightMax[i] = max(rightMax[i+1], height[i+1]);
    }

    for(int i=0; i<n; i++) {
        int currTrapped = max(0, min(leftMax[i], rightMax[i]) - height[i]);
        ans+=currTrapped;
    }
    return ans;
        
    }
};
