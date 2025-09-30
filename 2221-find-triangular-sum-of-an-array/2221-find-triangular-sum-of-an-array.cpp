
//Solution1 Combination(error caused by calculating combination)
// class Solution {
// public:
// 	long long Combination(int n, int r) {
// 		if (r>n-r)
// 		{
// 			r = n - r;
// 		}
// 		long long ans = 1;
// 		for (int i = 0; i < r; i++)
// 		{
// 			ans = ans * (n - i) / (i+1);
// 		}
// 		return ans;
// 	}
//     int triangularSum(vector<int>& nums) {
// 		long long ans = 0;
// 		for (int i = 0; i < nums.size(); i++)
// 		{
// 			long long C = Combination(nums.size()-1, i);
// 			ans = (ans + C * nums[i]) % 10;
// 		}
// 		return ans % 10;
//     }
// };
class Solution {
public:
    int triangularSum(vector<int>& nums) {

		while(nums.size()>1)
		{
			vector<int> new_nums;
			for (int i = 0; i < nums.size()-1; i++)
			{
				new_nums.push_back((nums[i] + nums[i + 1])%10);
			}
			nums = move(new_nums);
		}
		return nums[0] % 10;
    }
};