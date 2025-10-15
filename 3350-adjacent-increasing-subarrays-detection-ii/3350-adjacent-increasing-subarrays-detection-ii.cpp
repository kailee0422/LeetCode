class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int len = 1, prev = 0, k = 0;
        //len:curent length of tracking string
        //prev:previous length of tracking string
        //k:previous best k
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1]) {
                len++;
            }
            else {
                // when run ends, check the max k from prev and len runs
                k = max({ k, len / 2, min(prev, len) });
                prev = len;
                len = 1;
            }
        }
        k = max({ k, len / 2, min(prev, len) });
        return k;
    }
};