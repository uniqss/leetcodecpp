#include "../inc.h"

// bfs 其实很简单，也不用递归。就是代码有点长
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
            size_t tail_null_idx = qsize;
            for (size_t i = 0; i < qsize; ++i) {
                root = q.front();
                q.pop();
                if (!first) ret += ",";
                first = false;
                if (root == nullptr) {
                    ret += "null";
                    tail_null_idx = min(tail_null_idx, i);
                } else {
                    have_valid |= root->left != nullptr || root->right != nullptr;
                    ret += std::to_string(root->val);
                    q.emplace(root->left);
                    q.emplace(root->right);
                    tail_null_idx = i + 1;
                }
            }
            if (!have_valid && tail_null_idx < qsize) ret = ret.substr(0, ret.size() - (qsize - tail_null_idx) * 5);
            if (!have_valid) break;
        }
        ret += "]";

        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::vector<std::pair<const char*, int>> vals;
        split_str(data.c_str() + 1, data.size() - 2, ',', vals, 100000);
        if (vals.empty() || strncmp(vals[0].first, "null", 4) == 0) {
            return nullptr;
        }

        char szTmp[6];
        size_t i = 0;

        TreeNode* root = nullptr;
        queue<TreeNode*> q;
        TreeNode* curr = nullptr;
        TreeNode* child = nullptr;

        strncpy(szTmp, vals[i].first, vals[i].second);
        szTmp[vals[i].second] = '\0';
        root = new TreeNode(atoi(szTmp));
        q.push(root);
        if (++i >= vals.size()) return root;

        while (i < vals.size()) {
            auto qsize = q.size();
            for (size_t qidx = 0; qidx < qsize; ++qidx) {
                curr = q.front();
                q.pop();
                if (curr != nullptr) {
                    if (strncmp(vals[i].first, "null", 4) == 0) {
                        q.push(nullptr);
                    } else {
                        strncpy(szTmp, vals[i].first, vals[i].second);
                        szTmp[vals[i].second] = '\0';
                        child = new TreeNode(atoi(szTmp));
                        q.push(child);
                        curr->left = child;
                    }
                    if (++i >= vals.size()) return root;

                    if (strncmp(vals[i].first, "null", 4) == 0) {
                        q.push(nullptr);
                    } else {
                        strncpy(szTmp, vals[i].first, vals[i].second);
                        szTmp[vals[i].second] = '\0';
                        child = new TreeNode(atoi(szTmp));
                        q.push(child);
                        curr->right = child;
                    }
                    if (++i >= vals.size()) return root;
                }
            }
        }

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
        print("ok.");
    } else {
        print("not ok.");
        print(vals);
        print(expect);
        print(ret);
        pTree(root);
        print();
    }
}

int main() {
    test({1, 2, 3, null, null, 4, 5}, "[1,2,3,null,null,4,5]");
    test({1, 2, 3, null, null, 4, 5, 6, 7}, "[1,2,3,null,null,4,5,6,7]");
    test({4, -7, -3, null, null, -9, -3, 9, -7, -4, null, 6, null, -6, -6, null, null, 0, 6, 5, null, 9, null, null, -1, -4, null, null, null, -2},
         "[4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]");
    test({}, "[]");
    return 0;
}

/*
[1,2,3,null,null,4,5]
[]
[1,2,3,null,null,4,5,6,7]
[4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]

*/
