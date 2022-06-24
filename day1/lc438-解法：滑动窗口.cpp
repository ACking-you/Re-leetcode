//
// Created by Alone on 2022-6-23.
//
#include<StringUtil.h>
#include<unordered_map>
#include<unordered_set>
#include<iostream>

using namespace std;

//题目链接：https://leetcode.cn/problems/find-all-anagrams-in-a-string/
// 滑窗的关键步骤：1.准备好need map和window map。2.右移窗口并更新有用的窗口信息。3.收缩窗口的时候更新答案。
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for (auto &&ch: p)need[ch]++;
        vector<int> ret;
        int left = 0, right = 0, valid = 0;
        int sz = s.size();
        while (right < sz) {
            char ch = s[right];
            right++; // 窗口右移
            //窗口内只更新有用的信息
            if (need.count(ch)) {
                window[ch]++;
                if (window[ch] == need[ch]) {
                    valid++;
                }
            }
            //判断是否需要收缩窗口
            while (left < right && valid == need.size()) {
                //窗口内包含所有所需字符，且长度要一致
                if (right - left == p.size()) {
                    ret.push_back(left);
                }
                //窗口往左移动
                char x = s[left];
                left++;
                if (need.count(x)) {
                    if (need[x] == window[x])
                        valid--;
                    window[x]--;
                }
            }
        }
        return ret;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        string s = StringUtil::stringToString(line);
        getline(cin, line);
        string p = StringUtil::stringToString(line);
        vector<int> ret = Solution().findAnagrams(s, p);

        string out = StringUtil::integerVectorToString(ret);
        cout << out << endl;
    }
}