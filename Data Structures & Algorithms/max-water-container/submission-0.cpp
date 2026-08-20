class Solution {
public:
    int maxArea(vector<int>& heights) {

        /*
            start from left and right
            check which height is less, compute ans by min(leftHeight, rightHeight) * width
            discard the height which is smaller
            if both heights are equal, calculate ans and you can move both the pointers



        */

        const int n = heights.size();
        int left=0, right=n-1;
        int ans = INT_MIN;

        while(left<right)
        {
            int currArea;
            if(heights[left] == heights[right])
            {
                currArea= heights[left] * (right-left);
                left++;
                right--;
            }
            else if(heights[left] < heights[right])
            {
                currArea = heights[left] * (right-left);
                left++;
            }
            else
            {
                currArea=heights[right] * (right-left);
                right--;
            }
            ans=max(ans, currArea);
        }
        return ans;
        
    }
};
