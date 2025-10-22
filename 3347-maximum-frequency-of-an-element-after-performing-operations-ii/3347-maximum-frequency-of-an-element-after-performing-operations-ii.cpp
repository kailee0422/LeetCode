class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> originalCount;
        int ans = 0;
        for (int num : nums) {
            originalCount[num]++;
            ans = max(ans, originalCount[num]);
        }

        set<long long> allCandidates;
        for (int num : nums) {
            allCandidates.insert(num);
            allCandidates.insert((long long)num - k);
            allCandidates.insert((long long)num + k);
        }

        for (long long target : allCandidates) {
            auto left = lower_bound(nums.begin(), nums.end(), (int)(target - k));
            auto right = upper_bound(nums.begin(), nums.end(), (int)(target + k));
            
            int canReach = right - left;
            int original = originalCount[(int)target];
            
            int freq = min(original + numOperations, canReach);
            ans = max(ans, freq);
        }

        return ans;
    }
};
