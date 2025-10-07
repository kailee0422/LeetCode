class Solution {
public:
	vector<int> avoidFlood(vector<int>& rains) {
		vector<int>result(rains.size(),1);
		set<int> dryDays;//Dry day
		unordered_map<int,int> lastRain;//lake->last day it rain
		for (int i = 0; i < rains.size(); i++)
		{
			if (rains[i]==0)
			{
				dryDays.insert(i);
				result[i] = 1;
			}
			else
			{
				int lake = rains[i];
				result[i] = -1;
				if (lastRain.count(lake))//lake rain before
				{
					auto it = dryDays.upper_bound(lastRain[lake]);//Find Dry day to give to raining lake day
					if (it== dryDays.end())//can't find any time to satisfy raining lake day
					{
						return {};
					}
					result[*it] = lake;
					dryDays.erase(it);
				}
				lastRain[lake] = i;

			}
		}
		return result;
	}
};