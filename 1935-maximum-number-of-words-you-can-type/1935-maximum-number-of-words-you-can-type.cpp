class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int result = 0;
        stringstream ss(text); 
        string t;
        char del = ' ';
        bool found = false;
        while (getline(ss, t, del)) {
            for (int i = 0; i < t.size(); i++)
            {
                for (int j = 0; j < brokenLetters.size(); j++)
                {
                    if (t[i]== brokenLetters[j])
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    break;
                }
            }if (!found)
            {
                result++;
            }
            found = false;
        }
        return result;
    }
};