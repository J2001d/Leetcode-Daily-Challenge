class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // count sort;
        map<int,int> g;
        for(auto x:nums){
            g[x]++;
        }
        vector<int> ans;
        for(auto x:g){
            while(x.second--){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};
