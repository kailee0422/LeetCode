class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lastUsed = INT_MIN;
        int count = 0;

        for (int num : nums) {
            int left = num - k;
            int right = num + k;

            int curr = max(left, lastUsed + 1);

            if (curr <= right) {
                lastUsed = curr;
                count++;
            }
        }

        return count;
    }
};