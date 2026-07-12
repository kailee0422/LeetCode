class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>vec;
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            vec.push_back(arr[i]);
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        unordered_map<int,int> ranktable;
        int rank=1;
        for(int i=0;i<vec.size();i++){
            ranktable[vec[i]]=rank++;
        }
        for(int i=0;i<arr.size();i++){
            ans[i]=ranktable[arr[i]];
        }
        return ans;
    }
};