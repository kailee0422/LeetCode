class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++) {
            hashmap[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int find_t = target - nums[i];
            if (hashmap.find(find_t) != hashmap.end() && hashmap[find_t] != i) {
                return {i, hashmap[find_t]};
            }
        }
        return {};
    }
};