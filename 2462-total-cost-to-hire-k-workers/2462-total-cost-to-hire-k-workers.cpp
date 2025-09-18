#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> headcostpq;
        priority_queue<int, vector<int>, greater<int>> endcostpq;
        int n = costs.size();
        int left = 0, right = n - 1;
        for (int i = 0; i < candidates && left <= right; i++) {
            headcostpq.push(costs[left++]);
        }
        for (int i = 0; i < candidates && left <= right; i++) {
            endcostpq.push(costs[right--]);
        }
        long long result = 0;
        for (int i = 0; i < k; i++)
        {
            if (endcostpq.empty()||(!headcostpq.empty() && headcostpq.top() <= endcostpq.top()))
            {
                result += (long long)headcostpq.top();
                headcostpq.pop();
                if (left<=right)
                {
                    headcostpq.push(costs[left++]);
                }
            }
            else
            {
                result += (long long)endcostpq.top();
                endcostpq.pop();
                if (left <= right)
                {
                    endcostpq.push(costs[right--]);
                }
            }
        }
        return result;
    }
};