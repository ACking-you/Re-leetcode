//
// Created by Alone on 2022-6-28.
//
#include<bits/stdc++.h>
#include<StringUtil.h>

using namespace std;

class Solution {
public:
    //用index - value kv映射，由于原本的index是从0开始，而我们需要的value是从1开始，
    //故可以将需要映射的值-1形成对应的index进行映射。
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int64_t index = (int64_t)nums[i]-1; //计算这个值可能会溢出，故提升
            while(index>=0&&index<nums.size()&&nums[index]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
                index = nums[i]-1;
            }
        }

        for(int i=0;i<nums.size();i++){
            int64_t index = (int64_t)nums[i]-1;
            if(index!=i){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};

int main(){
    string line;
    while(getline(cin,line)){
        auto vec = StringUtil::stringToIntegerVector(line);
        auto res = Solution().firstMissingPositive(vec);
        cout<<res<<endl;
    }
}