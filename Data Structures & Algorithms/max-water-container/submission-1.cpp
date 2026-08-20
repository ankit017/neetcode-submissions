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
        int max_area = 0;

        while(left<right)
        {
            int width = right - left;
            int height = min(heights[left], heights[right]);
            max_area = max(max_area, width*height);
            if(heights[left]<heights[right]) {
                left++;
            }
            else if(heights[left]>heights[right]) {
                right--;
            }
            else {
                left++;
                right--;
            }
            
        }
        return max_area;
    }
};
