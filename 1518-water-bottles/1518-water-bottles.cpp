class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        while (numBottles / numExchange >= 1) {
            result += numBottles / numExchange;
            numBottles = numBottles / numExchange+(numBottles- (numBottles / numExchange)* numExchange);
        }
        return result;
    }
};