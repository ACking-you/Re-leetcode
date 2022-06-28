#include<bits/stdc++.h>
#include<StringUtil.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            //这一堆代码，经典的单调队列模板——如果该值插入队列后不符合单调则进行pop
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            //关键判断：如果最大的数不是在窗口内，则不断pop_front
            while (q.front() <= i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

int main(){
    string line;
    while(getline(cin,line)){
        int v;
        cin>>v;
        char x;
        cin.get(x);
        auto vec = StringUtil::stringToIntegerVector(line);
        cout<<StringUtil::integerVectorToString(Solution().maxSlidingWindow(vec,v))<< endl;
    }
}