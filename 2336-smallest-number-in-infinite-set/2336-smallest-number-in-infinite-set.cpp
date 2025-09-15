class SmallestInfiniteSet {
private:
	int currentnum;
	priority_queue<int, vector<int>, greater<int> > addback;
	unordered_set<int> inAddback;
public:
	SmallestInfiniteSet() {
		currentnum = 1;
	}

	int popSmallest() {
		if (!addback.empty())
		{
			int temp = addback.top();
			addback.pop();
			inAddback.erase(temp);
			return temp;
		}
		else
		{
			return currentnum++;
		}
	}

	void addBack(int num) {
		if (num < currentnum&& inAddback.find(num) == inAddback.end()) {
			addback.push(num);
			inAddback.insert(num);
		}
	}
};