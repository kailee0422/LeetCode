class Solution {
public:
    int maxArea(vector<int>& height) {
        int head = 0;int tail = height.size() - 1;int max = 0;
        while (head < tail) {
            int temp = abs((tail - head) * min(height[tail], height[head]));
            if (temp>max)
            {
                max = temp;
            }
            if (height[tail]>height[head])
            {
                head++;
            }
            else
            {
                tail--;
            }
        }
        return max;
    }
};