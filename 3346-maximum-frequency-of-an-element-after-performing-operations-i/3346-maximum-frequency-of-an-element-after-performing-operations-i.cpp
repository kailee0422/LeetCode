class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // 统计原始频率
        unordered_map<int, int> originalCount;
        int ans = 0;
        for (int num : nums) {
            originalCount[num]++;
            ans = max(ans, originalCount[num]);
        }
        
        // 收集所有候选目标值
        set<int> allCandidates;
        for (int num : nums) {
            allCandidates.insert(num);
            allCandidates.insert(num - k);
            allCandidates.insert(num + k);
        }
        
        // 对每个候选值，用二分查找计算范围内的元素数量
        for (int target : allCandidates) {
            // 找到 [target-k, target+k] 范围内的元素数量
            auto left = lower_bound(nums.begin(), nums.end(), target - k);
            auto right = upper_bound(nums.begin(), nums.end(), target + k);
            
            int canReach = right - left;  // 能变成target的元素数量
            int original = originalCount[target];  // 原本就是target的数量
            
            // 最大频率：保留original个 + 操作最多numOperations个
            int freq = min(original + numOperations, canReach);
            ans = max(ans, freq);
        }
        
        return ans;
    }
};