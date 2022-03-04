#include "../inc.h"

int split_str(const char *str, int str_len, char delim, vector<Slice> &ret, int max_part_num) {
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

// test:test_desc s32:param1 s32:param2 (s32:arr_param1 s32:arr_param2)[]
int split_str_complex(const char *str, int str_len, char delim, char delim_left, char delim_right, vector<Slice> &ret, int max_part_num) {
    int cur_part_num = 0;
    bool in_arr = false;

    for (int i = 0; i < str_len; ++i) {
        if (str[i] == delim) continue;
        if (str[i] == delim_left) {
            in_arr = true;
        }

        if (cur_part_num >= max_part_num) {
            return -1;
        }

        int end = i + 1;
        for (; end < str_len; ++end) {
            if (in_arr && str[end] == delim_right) {
                break;
            }
            if (!in_arr && str[end] == delim) {
                --end;
                break;
            }
        }

        ret.push_back({str + i, end - i + 1});
        ++cur_part_num;

        i = end;
    }

    return 0;
}

// test:test_desc s32:param1 s32:param2 (s32:arr_param1 s32:arr_param2)[]
int split_str_pair_arr(const char *str, int str_len, vector<pair<vector<Slice>, bool>> &ret, int max_part_num) {
    std::vector<Slice> params;
    char delim = ' ';
    char delim_left = '(';
    char delim_right = ']';
    split_str_complex(str, str_len, delim, delim_left, delim_right, params, 1024);

    auto retsize = ret.size();
    ret.resize(ret.size() + params.size());
    for (size_t i = 0; i < params.size(); ++i) {
        auto &reti = ret[retsize + i];
        const Slice &param = params[i];
        if (*param.str == delim_left) {
            reti.second = true;
            if (param.len < 7) return -1;
            vector<Slice> arr_params;
            split_str(param.str + 1, param.len - 4, delim, arr_params, 1024);
            for (auto arr_param : arr_params) {
                split_str(arr_param.str, arr_param.len, ':', reti.first, 1024);
            }
        } else {
            reti.second = false;
            split_str(param.str, param.len, ':', reti.first, 2);
        }
    }

    return 0;
}

void test1(const char *str) {
    int str_len = strlen(str);

    std::vector<Slice> ret;
    split_str_complex(str, str_len, ' ', '(', ']', ret, 1024);

    cout << str << endl;

    for (const auto &slice : ret) {
        cout << "{";
        string s = slice.str;
        s = s.substr(0, slice.len);
        cout << s;
        cout << "}";
    }

    cout << endl;
}

void test2(const char *str) {
    vector<pair<vector<Slice>, bool>> ret;
    int str_len = strlen(str);
    split_str_pair_arr(str, str_len, ret, 1024);

    cout << str << endl;

    for (const auto &it : ret) {
        cout << "{";
        if (it.second) {
            cout << "[";
        }
        for (const auto &slice : it.first) {
            string s = slice.str;
            s = s.substr(0, slice.len);
            cout << s << "|";
        }
        if (it.second) {
            cout << "]";
        }
        cout << "}";
    }
    cout << endl;

    for (const auto &it : ret) {
        cout << "{" << it.first.size() << "|" << it.second << "}";
    }
    cout << endl;
}

int main() {
    const char *str = "test:test_desc s32:param1 s32:param2 (s32:arr_param1 s32:arr_param2)[]";
    test1(str);

    test2(str);

    return 0;
}