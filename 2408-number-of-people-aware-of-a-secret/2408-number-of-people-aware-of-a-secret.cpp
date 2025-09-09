class Solution {
public:
	int peopleAwareOfSecret(int n, int delay, int forget) {
		vector<long long> dp(n + 1, 0);//matrix to record how many people still remenber in i days
		int modulo = pow(10, 9) + 7;
		dp[1] = 1;
		for (int i = 1; i < n + 1; i++)
		{
			if (dp[i] > 0) {
				int start = i + delay;
				int end = i + forget - 1;
				for (int j = start; j <= end; j++)
				{
					if (j <= n) {
						dp[j] = (dp[j]+dp[i]) % modulo;
					}
				}
			}
		}
		int bounder = max(1, n - forget + 1);
		long long result = 0;
		for (int i = bounder; i < n + 1; i++)
		{
			result = (result + dp[i]) % modulo;
		}
		return (int)result;
	}
};