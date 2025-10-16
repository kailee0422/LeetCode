class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
		unordered_map<int, int> hashmap;
		for (int i :nums)
		{
			i = ((i % value) + value) % value;
			hashmap[i]++;
		}
		int integer = 0;
		while (true) {
			int temp = integer % value;
			if (hashmap[temp] == 0) {
				return integer;

			}
			hashmap[temp]--;
			integer++;
		}
		
		return -1;
    }
};