class Solution {
public:
    int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<int> power(n);
        power[0] = 1;
        for(int i=1; i<n; i++) {
            power[i] = (power[i-1] * 2) % mod;
        }

        int l = 0, r = n-1;
        int result = 0;

        while(l <= r) {

            if(nums[l] + nums[r] <= target) {
                int diff = r - l;
                result = (result % mod + power[diff]) ;
                l++; 
            } else {
                r--;
            }
        }
        return result;
    }
};