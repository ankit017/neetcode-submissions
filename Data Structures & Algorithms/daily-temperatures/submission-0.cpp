class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        const int n = temperatures.size();
        vector<int> ans(n,0);

        for(int i=0;i<n;i++) {

            while(!st.empty() && temperatures[i]>temperatures[st.top()]) {
                int previousIndex = st.top();
                ans[previousIndex] = i-previousIndex;
                st.pop();
            }

            st.push(i);
        }
        return ans;
    }
};
