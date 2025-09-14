class Solution {
public:
    string toLowerCase(string s) {
        for (char& c : s) {
            c = tolower(c);
        }
        return s;
    }
    
    string toVowelPattern(string s) {
        s = toLowerCase(s);
        for (char& c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return s;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> output(queries.size(), ""); 
        
        unordered_map<string, vector<int>> umap1; 
        unordered_map<string, vector<int>> umap2; 
        
        for (int i = 0; i < wordlist.size(); i++) {
            umap1[toLowerCase(wordlist[i])].push_back(i);
            umap2[toVowelPattern(wordlist[i])].push_back(i);
        }
        
        for (int j = 0; j < queries.size(); j++) {
            string query = queries[j];
            
            bool found = false;
            for (int i = 0; i < wordlist.size() && !found; i++) {
                if (wordlist[i] == query) {
                    output[j] = query;
                    found = true;
                }
            }
            
            if (!found) {
                string lowerQuery = toLowerCase(query);
                if (umap1.find(lowerQuery) != umap1.end()) {
                    output[j] = wordlist[umap1[lowerQuery][0]];
                    found = true;
                }
            }
            
            if (!found) {
                string patternQuery = toVowelPattern(query);
                if (umap2.find(patternQuery) != umap2.end()) {
                    output[j] = wordlist[umap2[patternQuery][0]];
                }
            }
        }
        
        return output;
    }
};