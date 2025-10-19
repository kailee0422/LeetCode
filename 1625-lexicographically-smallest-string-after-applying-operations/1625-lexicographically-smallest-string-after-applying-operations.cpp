class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        string result = s;
        while (!q.empty()) {
            string temp = q.front();
            q.pop();
            if (temp<result)
            {
                result = temp;
            }
            if (!visited.count(addOperation(temp, a))) {
                visited.insert(addOperation(temp, a));
                q.push(addOperation(temp, a));
            }
            if (!visited.count(rotateOperation(temp, b))) {
                visited.insert(rotateOperation(temp, b));
                q.push(rotateOperation(temp, b));
            }
        }
        return result;


    }
private:
    string addOperation(string s, int a) {
        for (int i = 1; i < s.length(); i += 2) {
            s[i] = '0' + (s[i] - '0' + a) % 10;
        }
        return s;
    }

    string rotateOperation(string s, int b) {
        b = b % s.length();
        string first= s.substr(s.length() -b);
        string second = s.substr(0, s.length() - b);

        return first+second;
    }
};
