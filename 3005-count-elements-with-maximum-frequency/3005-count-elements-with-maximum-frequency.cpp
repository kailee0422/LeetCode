class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
		unordered_map<int, int>umap;
		int max = 0;
		vector<int> index;
		for (int i = 0; i < nums.size(); i++)
		{
			umap[nums[i]]++;
			if (max< umap[nums[i]])
			{
				max = umap[nums[i]];
			}
		}
		int result=0;
		for (int i = 0; i < umap.size(); i++)
		{
			if (umap[i] == max) {
				result += max;
			}
		}
		return result;
    }
};