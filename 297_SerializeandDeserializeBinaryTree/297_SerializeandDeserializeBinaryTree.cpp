#include "../stl.h"

class Codec {
   public:
    string serialize(TreeNode* root) {
        if (root == nullptr) return "[]";
        string ret = "[";
        queue<TreeNode*> q;
        vector<TreeNode*> nodes;
        q.emplace(root);
        while (!q.empty()) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                root = q.front();
                q.pop();
                if (root != nullptr) {
                    q.emplace(root->left);
                    q.emplace(root->right);
                }
                nodes.emplace_back(root);
            }
        }
        std::size_t end = nodes.size() - 1;
        while (nodes[end] == nullptr) --end;
        for (size_t i = 0; i <= end; ++i) {
            if (nodes[i] == nullptr) {
                ret += "null,";
            } else {
                ret += std::to_string(nodes[i]->val) + ",";
            }
        }

        ret[ret.size() - 1] = ']';
        return ret;
    }
    void strSplice(const string& str, char delim, std::size_t istart, std::size_t ilen, vector<pair<const char*, std::size_t>>& ret) {
        const char* cstr = str.c_str();
        size_t iend = 0;
        for (; iend < str.size() && iend < istart + ilen; ++iend) {
            if (str[iend] == delim) {
                if (istart < iend) {
                    ret.emplace_back(make_pair(cstr + istart, iend - istart));
                }
                istart = iend + 1;
            }
        }
        if (istart < iend) {
            ret.emplace_back(make_pair(cstr + istart, iend - istart));
        }
    }
    bool spliceValInt(int& val, const char* pszVal, std::size_t len) {
        if (strncmp(pszVal, "null", 4) == 0) return false;
        char szTmp[32];
        strncpy(szTmp, pszVal, len);
        val = atoi(szTmp);
        return true;
    }
    bool spliceValInt(int& val, const std::pair<const char*, std::size_t>& vpair) { return spliceValInt(val, vpair.first, vpair.second); }

    TreeNode* deserialize(string data) {
        if (data == "[]" || data == "[null]") return nullptr;
        vector<pair<const char*, std::size_t>> nodevals;
        strSplice(data, ',', 1, data.size() - 2, nodevals);

        TreeNode* root = new TreeNode();
        if (nodevals.empty() || !spliceValInt(root->val, nodevals[0])) return nullptr;
        queue<TreeNode*> q;
        q.emplace(root);
        auto trimed = q.size();
        int tmpVal = 0;
        TreeNode* tmpNode = nullptr;
        while (!q.empty() && trimed < nodevals.size()) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize && trimed < nodevals.size(); ++i) {
                tmpNode = q.front();
                q.pop();
                if (tmpNode != nullptr && trimed < nodevals.size()) {
                    if (spliceValInt(tmpVal, nodevals[trimed])) {
                        tmpNode->left = new TreeNode(tmpVal);
                        q.emplace(tmpNode->left);
                    } else {
                        q.emplace(nullptr);
                    }
                    ++trimed;
                }
                if (tmpNode != nullptr && trimed < nodevals.size()) {
                    if (spliceValInt(tmpVal, nodevals[trimed])) {
                        tmpNode->right = new TreeNode(tmpVal);
                        q.emplace(tmpNode->right);
                    } else {
                        q.emplace(nullptr);
                    }
                    ++trimed;
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
        pTreeLevelOrder(root);
        pnewline();
    }
}

int main() {
    test({1, 3, null, null, 4}, "[1,3,null,null,4]");
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
