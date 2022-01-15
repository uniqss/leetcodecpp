#include "../stl.h"

class Codec {
   public:
    int split_str(const char* str, int str_len, char delim, vector<pair<const char*, int>>& ret, int max_part_num) {
        int cur_part_num = 0;

        for (int i = 0; i < str_len; ++i) {
            if (str[i] == delim) continue;

            if (cur_part_num >= max_part_num) {
                return -1;
            }

            int end = i + 1;
            for (; end < str_len; ++end) {
                if (str[end] == delim) {
                    --end;
                    break;
                }
            }

            if (end == str_len) {
                ret.push_back({str + i, end - i});
            } else {
                ret.push_back({str + i, end - i + 1});
            }
            ++cur_part_num;

            i = end;
        }

        return 0;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "[]";
        string ret = "[";
        queue<TreeNode*> q;
        q.emplace(root);
        bool first = true;
        while (!q.empty()) {
            bool have_valid = false;
            auto qsize = q.size();
            while (qsize-- > 0) {
                root = q.front();
                q.pop();
                if (!first) ret += ",";
                first = false;
                if (root == nullptr) {
                    ret += "null";
                    q.emplace(nullptr);
                    q.emplace(nullptr);
                } else {
                    have_valid = root->left != nullptr || root->right != nullptr;
                    ret += std::to_string(root->val);
                    q.emplace(root->left);
                    q.emplace(root->right);
                }
            }
            if (!have_valid) break;
        }
        ret += "]";

        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::vector<std::pair<const char*, int>> vals;
        split_str(data.c_str() + 1, data.size() - 2, ',', vals, 100000);
        if (vals.empty() || vals[0].first == "null") {
            return nullptr;
        }
        TreeNode* root = nullptr;
        queue<TreeNode*> q;

        return nullptr;
    }
};

void test(const vector<ComplexVal>& vals, const string& expect) {
    string str;
    vcomplexToString(str, vals);
    Codec co;
    TreeNode* root = co.deserialize(str);
    TreeAutoReleaser _(root);
    string ret = co.serialize(root);
    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvcomplex(vals);
        praw(expect);
        praw(ret);
    }
}

int main() {
    test({1, 2, 3, null, null, 4, 5}, "[1,2,3,null,null,4,5]");
    test({}, "[]");
    return 0;
}

/*
[1,2,3,null,null,4,5]
[]
*/
