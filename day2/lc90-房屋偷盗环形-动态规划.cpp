#include<bits/stdc++.h>
#include <StringUtil.h>
using namespace std;
//与朴素版不同在于，需要考虑三种情况：
//1.首尾房屋都不取
//2.取第一个房子，不取最后一个房子
//3.取最后一个房子，不取第一个房子
//2、3情况任何一个都是把1的范围包含了的。。。故只需考虑2，3情况
class Solution {
public:
    enum{
        MAX = 0x3f3f3f3f
    };

    //普适性的范围查询答案
    int robByRange(vector<int>&nums,int start ,int end){
        int dp[nums.size()+2];
        memset(dp,0,sizeof(dp));

        for(int i=start+2;i<=end+1;i++){
            dp[i] = max(dp[i-2]+nums[i-2],dp[i-1]);
        }

        return dp[end+1];
    }
    int rob(vector<int>&nums){
        if(nums.size()<3)return 0;
        return max(robByRange(nums,1,nums.size()), robByRange(nums,0,nums.size()-1));
    }
};

int main(){
    string line;
    while(getline(cin,line)){
        auto coins = StringUtil::stringToIntegerVector(line);
        auto ret = Solution().rob(coins);
        cout<<ret<<endl;
    }
}