//find nums[i] > nums[i-1] && nums[i] > nums[i+1]
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;  // 右半邊有 peak
            else
                right = mid;     // 左半邊可能有 peak
        }
        return left;
    }
};
