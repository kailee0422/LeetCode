class Solution {
public:
    int totalMoney(int n) {
        int result=0;int cur=28;int iteration=0;
        while(n>0){
            if(n>=7){
                result+=cur;
                cur+=7;
                iteration++;
                n=n-7;
            }
            else{
                for(int i=1;i<=n;i++)
                {
                    result+=iteration+i;
                }
                break;
            }
        }
        return result;

    }
};