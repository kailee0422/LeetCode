class Solution {
public:
    
    string fractionToDecimal(int numerator, int denominator) {
        string result = "";
        if (numerator==0)
        {
            return "0";
        }
        if ((numerator ^ denominator) < 0)//handle negative
        {
            result = "-";
        }
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        long long integer = num / den;
        long long remainder = num % den;
        result += to_string(integer);

        if (remainder == 0)
        {
            return result;
        }

        unordered_map<long long, int> hashmap;
        int currentIndex = 0;
        string fraction = "";
        while (remainder != 0) {
            if (hashmap.find(remainder) != hashmap.end())//Already appear
            {
                fraction.insert(hashmap[remainder], "(");
                fraction += ")";
                break;

            }
            hashmap[remainder] = currentIndex++;
            remainder *= 10;
            fraction += to_string(remainder / den);
            remainder %= den;
        }
        result = result + '.' + fraction;
        return result;
    }
};