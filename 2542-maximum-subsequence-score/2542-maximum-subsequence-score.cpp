#include<vector>
#include <queue>
#include<algorithm>
using namespace std;
class Solution {
public:
	long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
		vector <pair<int, int>> pairs;
		int n = nums1.size();
		for (int i = 0; i < n; i++) {
			pairs.push_back({ nums1[i], nums2[i] });
		}
		sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
			return a.second > b.second;
			});
		priority_queue<int, vector<int>, greater<int>> pq; 
		long long sumofnum1 = 0;
		for (int i = 0; i < k; i++) {
			pq.push(pairs[i].first);
			sumofnum1 += (long long)pairs[i].first;
		}
		long long localminnum2 = pairs[k - 1].second;
		long long max = localminnum2* sumofnum1;
		for (int i = k; i < n; i++)
		{
			auto temp = pq.top();
			sumofnum1 -= temp;
			pq.pop();
			pq.push(pairs[i].first);
			sumofnum1 += pairs[i].first;
			localminnum2 = pairs[i].second;

			long long score = sumofnum1*localminnum2;
			if (max < score) {
				max = score;
			}
		}
		return max;
	};
};
