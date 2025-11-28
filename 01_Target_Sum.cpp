class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // Check if the target sum is feasible
        if (totalSum < S || (S + totalSum) % 2 != 0) {
            return 0;
        }
        
        // The target for subset sum problem
        int target = (S + totalSum) / 2;
        
        // Edge case: target is negative
        if (target < 0) return 0;
        
        // Initialize the DP array
        vector<int> dp(target + 1, 0);
        dp[0] = 1;  // There's one way to make sum 0: take no elements
        
        // Process each number in the array
        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }
        
        return dp[target];
    }
};
