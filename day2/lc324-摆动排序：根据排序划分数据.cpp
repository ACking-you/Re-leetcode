//
// Created by Alone on 2022-6-28.
//
#include<bits/stdc++.h>
#include<StringUtil.h>

using namespace std;

//整体思路：由于要求中间的总比两边的大，所以可以先排序把数的相对大小确定
//由于题目中必然存在答案，所以重复相等的数不可能超过 (n+1)//2 ，否则就不可能排出来了。
//最终思路：我们可以先把最大的数依次放到中间，然后依次把最小的放入另一个区间。
//这个过程由于最大值是确定的，故可以利用桶排序，减少时间复杂度。
//注意：
//需要先从左往右由大到小填入中间。
//需要从左往右由大到小填入两边（此时的大是相对于当前的小值而言。
//这样避免了相邻数据之间重复的可能。

class Solution {
public:
    enum{
        MAXSIZE = 5005
    };
    void wiggleSort(vector<int>& nums) {
        int cnt[MAXSIZE]{};
        for(auto n:nums)cnt[n]++;

        int value_index = MAXSIZE-1;
        //从大到小填入中间
        for(int i=1;i<nums.size();i+=2){
            while(cnt[value_index]==0)value_index--;
            --cnt[value_index];
            nums[i] = value_index;
        }

        //从把小的填入两边（注意为了避免和之前的大值放在一起可能产生的重复，我们需要从头开始填入。
        for(int i=0;i<nums.size();i+=2){
            while(cnt[value_index]==0)value_index--;
            --cnt[value_index];
            nums[i] = value_index;
        }
    }
};

int main(){
    string line;
    while(getline(cin,line)){
        auto vec = StringUtil::stringToIntegerVector(line);
        Solution().wiggleSort(vec);
        cout<<StringUtil::integerVectorToString(vec)<<endl;
    }
}