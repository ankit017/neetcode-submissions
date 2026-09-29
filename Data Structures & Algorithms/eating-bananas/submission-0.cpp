class Solution {
public:
    int findTotalHours(int k, vector<int> a) {
        int total=0;
        for(int n: a) {
            if(n%k == 0)
            total+=n/k;
            else
            total+=n/k+1;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        const int n = piles.size();
        int max_num = 0;
        for(int n: piles) {
            max_num = max(max_num, n);
        }

        int low=1, high = max_num, mid=0, ans=0;

        while(low<=high) {
            mid = low+(high-low)/2;
            int hours_taken = findTotalHours(mid, piles);
            if(hours_taken<=h) {
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }

        }
        return ans;        
    }
};
