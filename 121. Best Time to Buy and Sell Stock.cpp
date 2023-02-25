class Solution {
public:
    
        int dp[100005][3][5];
    
    int helper(vector<int> &prices,int ind,int canBuy,int transCnt){
        
        if(ind >= prices.size() || transCnt <= 0){
            return 0;
        }
        
        
        int profit = 0;
        if(dp[ind][canBuy][transCnt] != -1){
            return dp[ind][canBuy][transCnt];
        }
        
        if(canBuy){
            
            int leave = helper(prices,ind+1,canBuy,transCnt);
            int bought = -prices[ind] + helper(prices,ind+1,0,transCnt);
            
            
            profit = max(profit,max(leave,bought));
            
        }else{
            
            int leave = helper(prices,ind+1,canBuy,transCnt);
            int sell = +prices[ind] + helper(prices,ind+1,1,transCnt-1);
            profit = max(profit,max(leave,sell));
        }
        
        return dp[ind][canBuy][transCnt] = profit;
        
    }
    
    
    
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return helper(prices,0,1,1);
    }
};
