class Solution {
public:
    string smallestPalindrome(string s) {
        int length=s.size();
        string result(length,0);
        if(length==1){
            return s;
        }
        else{
            if(length%2==0){
                string front = s.substr(0, length/2);
                sort(front.begin(), front.end(), std::less<char>());
                string tail = s.substr(length/2, length/2);
                sort(tail.begin(), tail.end(), std::greater<char>());
                result=front+tail;
            }
            else{
                string front = s.substr(0, length/2);
                sort(front.begin(), front.end(), std::less<char>());
                string tail = s.substr(length/2+1, length/2);
                sort(tail.begin(), tail.end(), std::greater<char>());
                result=front+s[length/2]+tail;
            }
        }
        return result;
        }
};