class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int,int> g;
        for(auto x:nums)
             g[x]++;
        for(auto x:g){
            if(x.second == 1)
                return x. first;
        }

        return INT_MAX;
    }
};
