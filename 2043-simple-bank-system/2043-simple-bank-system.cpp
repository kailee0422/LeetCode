class Bank {
private:
    vector<long long> currbalance;
    int n;
public:
    Bank(vector<long long>& balance) {
        for (int i = 0; i < balance.size(); i++)
        {
            currbalance.push_back(balance[i]);
        }
        n = balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > n || account2 < 1 || account2 > n){
            return false;
        }
        if (currbalance[account1-1]< money)
        {
            return false;
        }
        else
        {
            currbalance[account1 - 1] -= money;
            currbalance[account2 - 1] += money;
        }
        return true;
    }

    bool deposit(int account, long long money) {
        if (account < 1 || account > n ){
            return false;
        }
        currbalance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
         if (account < 1 || account > n ){
            return false;
        }
        if (currbalance[account - 1] < money)
        {
            return false;
        }
        else
        {
            currbalance[account - 1] -= money;
        }
        return true;
    }
};