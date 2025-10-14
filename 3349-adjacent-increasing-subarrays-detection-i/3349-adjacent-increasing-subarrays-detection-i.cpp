class Solution {
public:
    bool is_increasing(vector<int>& nums,int start,int end) {
        for (int i = start; i < end; i++)
        {
            if (nums[i + 1] <= nums[i]) {
                return false;
            }
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int head = 0;//0~k-1 k~2k-1
        while ((head + 2*k - 1) < n) {
            if (is_increasing(nums,head,head+k-1)==true&& is_increasing(nums, head+k, head + 2*k - 1) == true)
            {
                return true;
            }
            head++;
        }
        return false; 
    }
};