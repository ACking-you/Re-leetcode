//
// Created by Alone on 2022-6-23.
//
#include"StringUtil.h"
#include<iostream>
using namespace std;
class Solution {
public:
    struct mynode{
        TreeNode* node;
        uint64_t pos;
    };
    int widthOfBinaryTree(TreeNode* root) {
        queue<mynode>q;
        q.push({root,0});
        int ret = 1;
        while(!q.empty()){
            uint64_t start,end;
            int sz = q.size();
            for(int i=sz;i>0;i--){
                auto item = q.front();
                q.pop();
                if(i==sz){
                    start = item.pos;
                }
                if(i==1){
                    end = item.pos;
                }
                if(item.node->left){
                    q.push({item.node->left,item.pos*2});
                }
                if(item.node->right){
                    q.push({item.node->right,item.pos*2+1});
                }
            }
            ret = max(ret,(int)(end-start+1));
        }
        return ret;
    }
};

int main(){
    string line;
    while (getline(cin, line)) {
        TreeNode* root = StringUtil::stringToTreeNode(line);

        int ret = Solution().widthOfBinaryTree(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}