class Solution {
public:
    int countOdds(int low, int high) {
        int range = high - low + 1;
        int ans = range / 2;
        
        if(low % 2 != 0 && high % 2 != 0){
            ans++;
        }
        return ans;
    }
};

// 2 3 4 5 6  - 5  range / 2;
    
// 1 2 3 4 5 6 - 6 range / 2;

// 2 3 4 5 6 7 - 6 range / 2;

// 1 2 3 4 5 6 7 -> 7 range / 2 + 1
