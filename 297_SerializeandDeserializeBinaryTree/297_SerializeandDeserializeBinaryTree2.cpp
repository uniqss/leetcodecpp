#include "../stl.h"

// 还是bfs思路，稍微简洁了那么一丝丝
class Codec {
   public:
    string serialize(TreeNode* root) {
        if (root == nullptr) return "[]";
        queue<TreeNode*> q;
        q.emplace(root);
        stringstream ss;
        size_t null_end_count = 0;
        bool have_valid = true;
        while (have_valid) {
            auto qsize = q.size();
            have_valid = false;
            while (qsize-- != 0) {
                root = q.front();
                q.pop();
                if (ss.rdbuf()->in_avail() > 0) {
                    ss << ",";
                    ++null_end_count;
                }
                if (root == nullptr) {
                    ss << "null";
                    null_end_count += 4;
                } else {
                    ss << root->val;
                    q.emplace(root->left);
                    q.emplace(root->right);
                    null_end_count = 0;
                    have_valid = true;
                }
            }
        }
        return "[" + ss.str().substr(0, ss.str().size() - null_end_count) + "]";
    }
    void strSplit(std::string& str, size_t istart, size_t ilen, char delim, vector<pair<const char*, size_t>>& ret) {
        const char* cstr = str.c_str();
        size_t iend = 0;
        for (; iend < str.size() && iend < istart + ilen; ++iend) {
            if (str[iend] == delim) {
                if (istart < iend) {
                    ret.push_back({cstr + istart, iend - istart});
                }
                istart = iend + 1;
            }
        }
        if (istart < iend) {
            ret.push_back({cstr + istart, iend - istart});
        }
    }
    inline bool getSlinceValInt(pair<const char*, size_t>& slice, int& reti) {
        if (strncmp(slice.first, "null", 4) == 0) {
            return false;
        }
        char szTmp[10];
        strncpy(szTmp, slice.first, slice.second);
        szTmp[slice.second] = '\0';
        reti = atoi(szTmp);
        return true;
    }
    TreeNode* deserialize(string data) {
        vector<pair<const char*, size_t>> nodes;
        strSplit(data, 1, data.size() - 2, ',', nodes);
        int nTmp = 0;
        if (data == "[]" || data == "[null]" || nodes.empty() || !getSlinceValInt(nodes[0], nTmp)) return nullptr;
        TreeNode* root = new TreeNode(nTmp);
        queue<TreeNode*> q;
        q.emplace(root);
        size_t nidx = 0;
        TreeNode* curr = nullptr;
        TreeNode* child = nullptr;
        while (!q.empty()) {
            auto qsize = q.size();
            while (qsize-- != 0) {
                curr = q.front();
                q.pop();
                if (++nidx >= nodes.size()) return root;
                if (getSlinceValInt(nodes[nidx], nTmp)) {
                    child = new TreeNode(nTmp);
                    curr->left = child;
                    q.emplace(child);
                }
                if (++nidx >= nodes.size()) return root;
                if (getSlinceValInt(nodes[nidx], nTmp)) {
                    child = new TreeNode(nTmp);
                    curr->right = child;
                    q.emplace(child);
                }
            }
        }

        return root;
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
        pTree(root);
        pnewline();
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
