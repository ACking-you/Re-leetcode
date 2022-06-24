//
// Created by Alone on 2022-6-24.
//
#include<StringUtil.h>
#include<bits/stdc++.h>

using namespace std;

// 解此题的滑窗前提：所有单词长度一致。
//进阶的点：1.以整个单词字符串为窗口的滑动单位。2.需要枚举不同的滑窗起点。

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        if (words.empty() || s.empty())return {};
        //数据初始化
        unordered_map<string, int> need;
        for (auto &&c: words) {
            ++need[c];
        }
        unordered_map<string, int> window;
        vector<int> ret;

        //for循环枚举开始滑动的位置
        int wordLen = words[0].size();
        int wordsNum = words.size();
        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i, valid = 0;
            while (right < s.size()) {
                //以单词为单位进行滑动
                auto word = s.substr(right, wordLen);
                //更新窗口内信息（只放有用信息进窗口
                if (need.count(word)) {
                    if (++window[word] == need[word]) {
                        valid++;
                    }
                }
                //窗口右移
                right += wordLen;
                //缩小窗口并更新答案
                while (left < right && valid == need.size()) {
                    //在窗口内包含所有所需单词的情况下，窗口的大小恰好等于所有单词的大小，则为答案
                    if (right - left == wordLen * wordsNum) {
                        ret.push_back(left);
                    }
                    //缩小窗口
                    auto pword = s.substr(left, wordLen);
                    left += wordLen;
                    //更新窗口内信息
                    if (need.count(pword)) {
                        if (--window[pword] < need[pword]) {
                            valid--;
                        }
                    }
                }
            }
            window.clear();
        }
        return ret;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        auto str = StringUtil::stringToString(line);
        getline(cin, line);
        auto stringList = StringUtil::stringToStringVector(line);
        auto ret = Solution().findSubstring(str, stringList);
        cout << StringUtil::integerVectorToString(ret) << endl;
    }
}