//
// Created by Alone on 2022-6-23.
//

#ifndef RE_LEETCODE_STRINGUTIL_H
#define RE_LEETCODE_STRINGUTIL_H
#include<string>
#include<vector>
#include<queue>
#include<sstream>
#include<cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class StringUtil {
public:
    static void trimLeftTrailingSpaces(std::string &input) {
        input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
            return !isspace(ch);
        }));
    }
    static void trimRightTrailingSpaces(std::string &input) {
        input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
            return !isspace(ch);
        }).base(), input.end());
    }
    static int stringToInteger(std::string const& input) {
        return stoi(input);
    }

    static std::string stringToString(std::string input) {
        assert(input.length() >= 2);
        std::string result;
        for (int i = 1; i < input.length() -1; i++) {
            char currentChar = input[i];
            if (input[i] == '\\') {
                char nextChar = input[i+1];
                switch (nextChar) {
                    case '\"': result.push_back('\"'); break;
                    case '/' : result.push_back('/'); break;
                    case '\\': result.push_back('\\'); break;
                    case 'b' : result.push_back('\b'); break;
                    case 'f' : result.push_back('\f'); break;
                    case 'r' : result.push_back('\r'); break;
                    case 'n' : result.push_back('\n'); break;
                    case 't' : result.push_back('\t'); break;
                    default: break;
                }
                i++;
            } else {
                result.push_back(currentChar);
            }
        }
        return result;
    }

    static std::vector<std::string> stringToStringVector(std::string input){
        std::vector<std::string>output;
        trimLeftTrailingSpaces(input);
        trimRightTrailingSpaces(input);
        input = input.substr(1,input.length()-2);
        std::stringstream ss;
        ss.str(input);
        std::string item;
        while(getline(ss,item,',')){
            trimLeftTrailingSpaces(item);
            trimRightTrailingSpaces(item);
            output.push_back(stringToString(item));
        }
        return output;
    }

    static std::string stringVectorToString(std::vector<std::string> list, int length = -1) {
        if (length == -1) {
            length = list.size();
        }

        if (length == 0) {
            return "[]";
        }

        std::string result;
        for(int index = 0; index < length; index++) {
            auto str = list[index];
            result += "\""+str+"\"" + ", ";
        }
        return "[" + result.substr(0, result.length() - 2) + "]";
    }

    static std::vector<int> stringToIntegerVector(std::string input) {
        std::vector<int> output;
        trimLeftTrailingSpaces(input);
        trimRightTrailingSpaces(input);
        input = input.substr(1, input.length() - 2);
        std::stringstream ss;
        ss.str(input);
        std::string item;
        char delim = ',';
        while (getline(ss, item, delim)) {
            output.push_back(stoi(item));
        }
        return output;
    }

    static std::string integerVectorToString(std::vector<int> list, int length = -1) {
        if (length == -1) {
            length = list.size();
        }

        if (length == 0) {
            return "[]";
        }

        std::string result;
        for(int index = 0; index < length; index++) {
            int number = list[index];
            result += std::to_string(number) + ", ";
        }
        return "[" + result.substr(0, result.length() - 2) + "]";
    }

    static ListNode* stringToListNode(std::string input) {
        // Generate list from the input
        std::vector<int> list = stringToIntegerVector(input);

        // Now convert that list into linked list
        ListNode* dummyRoot = new ListNode(0);
        ListNode* ptr = dummyRoot;
        for(int item : list) {
            ptr->next = new ListNode(item);
            ptr = ptr->next;
        }
        ptr = dummyRoot->next;
        delete dummyRoot;
        return ptr;
    }

    static std::string listNodeToString(ListNode* node) {
        if (node == nullptr) {
            return "[]";
        }

        std::string result;
        while (node) {
            result += std::to_string(node->val) + ", ";
            node = node->next;
        }
        return "[" + result.substr(0, result.length() - 2) + "]";
    }

    static TreeNode* stringToTreeNode(std::string input) {
        trimLeftTrailingSpaces(input);
        trimRightTrailingSpaces(input);
        input = input.substr(1, input.length() - 2);
        if (!input.size()) {
            return nullptr;
        }

        std::string item;
        std::stringstream ss;
        ss.str(input);

        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (true) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            if (!getline(ss, item, ',')) {
                break;
            }

            trimLeftTrailingSpaces(item);
            if (item != "null") {
                int leftNumber = stoi(item);
                node->left = new TreeNode(leftNumber);
                nodeQueue.push(node->left);
            }

            if (!getline(ss, item, ',')) {
                break;
            }

            trimLeftTrailingSpaces(item);
            if (item != "null") {
                int rightNumber = stoi(item);
                node->right = new TreeNode(rightNumber);
                nodeQueue.push(node->right);
            }
        }
        return root;
    }
    static std::string treeNodeToString(TreeNode* root) {
        if (root == nullptr) {
            return "[]";
        }

        std::string output = "";
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                output += "null, ";
                continue;
            }

            output += std::to_string(node->val) + ", ";
            q.push(node->left);
            q.push(node->right);
        }
        return "[" + output.substr(0, output.length() - 2) + "]";
    }
};


#endif //RE_LEETCODE_STRINGUTIL_H
