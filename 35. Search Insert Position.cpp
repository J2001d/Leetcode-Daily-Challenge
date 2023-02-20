#define ll long long int

class Solution {
public:
    int searchInsert(vector<int>& a, int target) {
        int n = a.size();
        ll L = 0;
        ll H = n-1;
        
        ll ans = -1;
        
        while(L <= H){
            
            ll mid = (L + H) / 2; 
            
            if(a[mid] < target){
                ans = mid;
                L = mid + 1;
            }else{
                H = mid - 1;
            }
            
        }
        
        
        return ans+1;
        
        
    }
};
