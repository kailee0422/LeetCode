class Solution {
public:
	bool doesAliceWin(string s) {
		int count = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				count++;
			}
		}
		if (count == 0)
		{
			return false;
		}
		if (count % 2 == 1)
		{
			return true;
		}
		int temp = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				temp++;
			}
			if (temp == count - 1)
			{
				if (s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u')
				{
					return true;
				}
			}
		}return false;
	}
};