class Solution {
public:
	int guessNumber(int n) {
		int left = 1;int right = n;int mid = left + (right - left) / 2;//Prevent overflow
		while (guess(mid) != 0) {
			if (guess(mid)==1)// 1 if num is lower than the picked number
			{
				left = mid+1;
				right = right;
				mid = left + (right - left) / 2;
			}
			else {
				left = left;
				right = mid-1;
				mid = left + (right - left) / 2;
			}
		}
		return mid;
	}
};