class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k = nums.size()-1;
        int count = 0;
        for (int i = k; i >= 2; i--)
        {
            int begin = 0; int end = i - 1;
            while (begin <= end) {
                if (nums[begin]+ nums[end]>nums[i])
                {
                    count+=end-begin;
                    end--;
                }
                else
                {
                    begin++;
                }
            }

        }
        return count;
    }
};