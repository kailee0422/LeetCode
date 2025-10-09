// example 3 visualize: skill = [1,2,3,4], mana = [1,2]
// potion 0: \U0001f7e5
// potion 1: \U0001f7e9
// waiting: ⬛
// W0 \U0001f7e5\U0001f7e9\U0001f7e9⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛
// W1 ⬛\U0001f7e5\U0001f7e5\U0001f7e9\U0001f7e9\U0001f7e9\U0001f7e9⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛
// W2 ⬛⬛⬛\U0001f7e5\U0001f7e5\U0001f7e5⬛\U0001f7e9\U0001f7e9\U0001f7e9\U0001f7e9\U0001f7e9\U0001f7e9⬛⬛⬛⬛⬛⬛⬛⬛
// W3 ⬛⬛⬛⬛⬛⬛\U0001f7e5\U0001f7e5\U0001f7e5\U0001f7e5⬛⬛⬛\U0001f7e9\U0001f7e9\U0001f7e9\U0001f7e9\U0001f7e9\U0001f7e9\U0001f7e9\U0001f7e9
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int m = skill.size();int n = mana.size();
        vector<long long> times(m);
        for (int i = 0; i < n; i++)
        {
            long long cur_time = 0;
            for (int j = 0; j < m; j++) {
                cur_time = max(cur_time, times[j]) + skill[j] * mana[i];
            }
            times[m-1]= cur_time;
            for (int j = m-2; j >= 0; j--)
            {
                times[j] = times[j + 1] - skill[j+1] * mana[i];
            }
        }
        return times[m - 1];
    }
};