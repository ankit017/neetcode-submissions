class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        stack<pair<int,int>> st;
        int maxArea = 0;

        for(int i=0; i<n; i++) {
            int startIndex = i;
            while(!st.empty() && heights[i]<st.top().second) {
                startIndex = st.top().first;
                int width = i - startIndex;
                maxArea = max(maxArea, st.top().second*width);
                st.pop();
            }
            st.push({startIndex, heights[i]});
        }

        while(!st.empty()) {
            int width = n - st.top().first;
            maxArea = max(maxArea, st.top().second * width);
            st.pop();
        }
        return maxArea;       
    }
};
