class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> cncon;
		for (int i = 0; i < friendships.size(); i++)
		{
			int a = friendships[i][0];
			int b= friendships[i][1];
			vector<int> a_language = languages[a - 1];
			vector<int> b_language = languages[b - 1];
			vector<int> temp;
            bool canCommunicate = false;
            for (int j = 0; j < a_language.size(); j++) {
                for (int k = 0; k < b_language.size(); k++) {
                    if (a_language[j] == b_language[k]) {
                        canCommunicate = true;
                        break;
                    }
                }
                if (canCommunicate) {
                    break;
                }
            }
            if (canCommunicate==false)
            {
                cncon.insert(a);
                cncon.insert(b);
            }
		}
        vector<int> cover(n+1,0);
        for (int i:cncon)
        {
            vector<int> temp = languages[i - 1];
            for (int j = 0; j < temp.size(); j++)
            {
                cover[temp[j]]++;
            }
        }
        int max = cover[0];
        for (int i = 1; i < cover.size(); i++)
        {
            if (cover[i]>max)
            {
                max = cover[i];
            }
        }
        return cncon.size() - max;
    }
};