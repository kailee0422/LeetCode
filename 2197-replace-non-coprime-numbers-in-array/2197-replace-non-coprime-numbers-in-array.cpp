class Solution {
public:
	int GCD(int num1, int num2)
	{
		if (num2 == 0)
		{
			return num1;
		}

		return GCD(num2, num1 % num2);
	}

	int LCM(int num1, int num2)
	{
		long long g = GCD(num1, num2);
		long long lcm = 1LL * num1 * (num2 / g);
		return (int)lcm;
	}
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> noncoprime;
        vector<int>result;
		for (int i = 0; i < nums.size(); i++)
		{
			if (noncoprime.empty()|| GCD(noncoprime.top(),nums[i])==1)
			{
				noncoprime.push(nums[i]);
			}
			else
			{
				int temp = noncoprime.top();
				int insert = nums[i];
				while (!noncoprime.empty() && GCD(noncoprime.top(), insert) != 1) {
					insert = LCM(noncoprime.top(), insert);
					noncoprime.pop();
				}
				noncoprime.push(insert);
			}
		}
		while (!noncoprime.empty()) {
			result.push_back(noncoprime.top());
			noncoprime.pop();
		}
		reverse(result.begin(), result.end());
		return result;
    }
};