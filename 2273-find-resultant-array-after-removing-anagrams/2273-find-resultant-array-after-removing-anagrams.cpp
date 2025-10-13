class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string temp = "";
        for (string target: words)
        {
            string targets = target;
            sort(targets.begin(), targets.end());
            sort(temp.begin(), temp.end());
            if (targets != temp)
            {
                result.push_back(target);
                temp = target;
            }
        }
        return result;
    }
};