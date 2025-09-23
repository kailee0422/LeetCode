class Solution {
public:
	int compareVersion(string version1, string version2) {
		string current1 = "";
		string current2 = "";
		int index1 = 0;
		int index2 = 0;
		while (index1 < version1.size() || index2 < version2.size()) {
			if (index1 >= version1.size())
			{
				current1 = "0";
			}
			else
			{
				while (index1 < version1.size() && version1[index1] != '.') {

					current1 += version1[index1++];

				}
			}

			if (index2 >= version2.size())
			{
				current2 = "0";

			}
			else
			{
				while (index2 < version2.size() && version2[index2] != '.') {

					current2 += version2[index2++];

				}
			}

			int num1 = stoi(current1);
			int num2 = stoi(current2);
			current1 = "";
			current2 = "";
			if (index1 < version1.size()) index1++;
			if (index2 < version2.size()) index2++;
			if (num1 > num2)
			{
				return 1;
			}
			else if (num2 > num1)
			{
				return -1;
			}
			else
			{
				
				continue;
			}

		}
		return 0;
	}
};