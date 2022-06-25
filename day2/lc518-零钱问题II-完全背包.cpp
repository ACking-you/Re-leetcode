//
// Created by Alone on 2022-6-26.
//
#include<bits/stdc++.h>
#include <StringUtil.h>
using namespace std;
//完全背包问题，求出凑齐需要的最少物品数
class Solution {
public:
    //二维版本
    int change(int amount,vector<int>&coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1));
        for(int i=0;i<=coins.size();i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(j>=coins[i-1]){
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[coins.size()][amount];
    }
    //一维滚动数组优化版本
    int changeByOptimize(vector<int>& coins, int amount){
        vector<int>dp(amount+1);
        dp[0] = 1;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};

int main(){
    string line;
    int amount;
    while(cin>>amount){
        char l;
        cin.get(l);
        getline(cin,line);
        auto coins = StringUtil::stringToIntegerVector(line);

        auto ret = Solution().change(amount,coins);
        cout<<ret<<endl;
    }
}