#include<bits/stdc++.h>
#include <StringUtil.h>
using namespace std;
//完全背包问题，求出凑齐需要的最少物品数
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,INT_MAX/2));
        for(int i=0;i<coins.size()+1;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(j>=coins[i-1]){
                    dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[coins.size()][amount]==INT_MAX/2?-1:dp[coins.size()][amount];
    }
    int coinChangeByOptimize(vector<int>& coins, int amount){
        vector<int>dp(amount+1,INT_MAX/2);
        dp[0] = 0;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j] = min(dp[j],dp[j-coins[i]]+1);
            }
        }
        return dp[amount]==INT_MAX/2?-1:dp[amount];
    }
};

int main(){
    string line;
    while(getline(cin,line)){
        auto coins = StringUtil::stringToIntegerVector(line);
        int amount; cin>>amount;
        char l;
        cin.get(l);
        auto ret = Solution().coinChange(coins,amount);
        cout<<ret<<endl;
    }
}