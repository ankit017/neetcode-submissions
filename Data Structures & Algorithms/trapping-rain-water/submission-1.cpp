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
    int left=0,right=n-1;
    int leftMax = height[left];
    int rightMax = height[right];
    int ans=0;

    while(left<right) {
        leftMax=max(leftMax, height[left]);
        rightMax=max(rightMax, height[right]);
        if(leftMax<=rightMax) {
            ans+= leftMax-height[left];
            left++;
        }
        else {
            ans+=rightMax-height[right];
            right--;
        }
    }
    return ans;
        
    }
};
