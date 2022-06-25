#include<bits/stdc++.h>
#include <StringUtil.h>
using namespace std;
//动态规划问题
class Solution {
public:
    enum{
        MAX = 0x3f3f3f3f
    };
    int robByRecursive(vector<int>& nums) {
        auto dfs = [&](auto&&dfs,int pos){
            if(pos<0)
                return 0;
            int ret = 0;
            ret = max(dfs(dfs,pos-1),dfs(dfs,pos-2)+nums[pos]);
            return ret;
        };
        return dfs(dfs,nums.size()-1);
    }
    int robByMemo(vector<int>&nums){
        int memo[101];
        memset(memo,0x3f,sizeof(memo));
        auto dfs = [&](auto&&dfs,int pos){
            if(pos<0)
                return 0;
            if(memo[pos]!=MAX)return memo[pos];
            return memo[pos] = max(dfs(dfs,pos-1),dfs(dfs,pos-2)+nums[pos]);
        };
        return dfs(dfs,nums.size()-1);
    }

    int robByDp(vector<int>&nums){
        int dp[nums.size()+2];
        memset(dp,0,sizeof(dp));

        for(int i=2;i<=nums.size()+1;i++){
            dp[i] = max(dp[i-2]+nums[i-2],dp[i-1]);
        }

        return dp[nums.size()+1];
    }
};

int main(){
    string line;
    while(getline(cin,line)){
        auto coins = StringUtil::stringToIntegerVector(line);
        auto ret = Solution().robByDp(coins);
        cout<<ret<<endl;
    }
}