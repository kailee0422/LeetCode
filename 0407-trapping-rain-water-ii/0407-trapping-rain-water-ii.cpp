#include<vector>
#include<queue>
#include<tuple>
using namespace std;

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		int m = heightMap.size();
		if (m == 0) return 0;
		int n = heightMap[0].size();
		if (n == 0) return 0;
		priority_queue<
			tuple<int, int, int>,
			vector<tuple<int, int, int>>,
			greater<tuple<int, int, int>>
		> minHeap;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			minHeap.push(make_tuple(heightMap[i][0], i, 0));
			minHeap.push(make_tuple(heightMap[i][n - 1], i, n - 1));
			visited[i][0] = true;
			visited[i][n - 1] = true;
		}
		for (int j = 0; j < n; j++) {
			minHeap.push(make_tuple(heightMap[0][j], 0, j));
			minHeap.push(make_tuple(heightMap[m - 1][j], m - 1, j));
			visited[0][j] = true;
			visited[m - 1][j] = true;
		}
		int result = 0;
		while (!minHeap.empty()) {
			auto temp = minHeap.top();
			minHeap.pop();
			int h = get<0>(temp);
			int x = get<1>(temp);
			int y = get<2>(temp);
			//up
			if (y - 1 >= 0 && !visited[x][y - 1])
			{
				visited[x][y - 1] = true;
				if (heightMap[x][y - 1] < h) {
					result += h - heightMap[x][y - 1];
				}
				minHeap.push(make_tuple(max(heightMap[x][y - 1], h), x, y - 1));
			}
			//down
			if (y + 1 < n && !visited[x][y + 1])
			{
				visited[x][y + 1] = true;
				if (heightMap[x][y + 1] < h) {
					result += h - heightMap[x][y + 1];
				}
				minHeap.push(make_tuple(max(heightMap[x][y + 1], h), x, y + 1));
			}
			//left
			if (x - 1 >= 0 && !visited[x - 1][y])
			{
				visited[x - 1][y] = true;
				if (heightMap[x - 1][y] < h) {
					result += h - heightMap[x - 1][y];
				}
				minHeap.push(make_tuple(max(heightMap[x - 1][y], h), x - 1, y));
			}
			//right
			if (x + 1 < m && !visited[x + 1][y])
			{
				visited[x + 1][y] = true;
				if (heightMap[x + 1][y] < h) {
					result += h - heightMap[x + 1][y];
				}
				minHeap.push(make_tuple(max(heightMap[x + 1][y], h), x + 1, y));
			}
		}
		return result;
	}
};