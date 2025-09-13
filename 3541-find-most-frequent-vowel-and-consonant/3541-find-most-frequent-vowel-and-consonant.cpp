class Solution {
public:
    int maxFreqSum(string s) {
        std::unordered_map<char, int> umap;
		for (char element:s)
		{
			umap[element]++;
		}
		int vowels = max({ umap['a'], umap['e'], umap['i'], umap['o'], umap['u'] });
		int consonants = 0;
		for (const auto& n : umap) {
			if (n.first!='a'&& n.first != 'e'&& n.first != 'i'&& n.first != 'o'&& n.first != 'u')
			{
				if (n.second> consonants)
				{
					consonants = n.second;
				}
			}
		}
		return vowels + consonants;
    }
};