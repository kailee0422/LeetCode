class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
		sort(potions.begin(), potions.end());//O(nlogn)
		for (int i = 0; i < spells.size(); i++)
		{
			long long threshold = ceil((double)success / spells[i]);
			auto left = lower_bound(potions.begin(), potions.end(), threshold);
            if (left == potions.end()) {
                result.push_back(0);
            }
            else {
                int index = left - potions.begin();
                result.push_back(potions.size()-index);
            }
        }
        return result;
    }
};