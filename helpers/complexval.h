#pragma once

#include "StringHelper.h"
#include <cassert>

enum EComplexValType {
    EComplexValType_Invalid = -1,
    EComplexValType_nullptr,
    EComplexValType_int,
    EComplexValType_int64,
    EComplexValType_double,
    EComplexValType_bool,
    EComplexValType_char,
    EComplexValType_string,
    EComplexValType_pairint,
};

class ComplexVal {
   public:
    EComplexValType valtype;
    int vali;
    int64_t vali64;
    double vald;
    bool valb;
    char valc;
    string vals;
    pair<int, int> valpint;
    // ptr must be nullptr
    ComplexVal() : valtype(EComplexValType_Invalid) {}
    ComplexVal(void* ptr) : valtype(EComplexValType_nullptr) {}
    ComplexVal(int val) : valtype(EComplexValType_int), vali(val) {}
    ComplexVal(int64_t val) : valtype(EComplexValType_int64), vali64(val) {}
    ComplexVal(double val) : valtype(EComplexValType_double), vald(val) {}
    ComplexVal(bool val) : valtype(EComplexValType_bool), valb(val) {}
    ComplexVal(char c) : valtype(EComplexValType_char), valc(c) {}
    ComplexVal(const string& str) : valtype(EComplexValType_string), vals(str) {}
    ComplexVal(const std::pair<int, int>& pii) : valtype(EComplexValType_pairint), valpint(pii) {}
    ComplexVal(const std::initializer_list<int>& pii) : valtype(EComplexValType_pairint) {
        assert(pii.size() == 2);
        valpint.first = *pii.begin();
        valpint.second = *(pii.begin() + 1);
    }
    ComplexVal(const vector<int>& vi) : valtype(EComplexValType_pairint) {
        assert(vi.size() == 2);
        valpint.first = *vi.begin();
        valpint.second = *(vi.begin() + 1);
    }

    bool IsNullptr() const { return valtype == EComplexValType_nullptr; }
    std::string ToString() const {
        switch (valtype) {
            case EComplexValType_nullptr:
                return "null";
            case EComplexValType_int:
                return std::to_string(vali);
            case EComplexValType_int64:
                return std::to_string(vali64);
            case EComplexValType_double:
                return std::to_string(vald);
            case EComplexValType_bool:
                return valb ? "true" : "false";
            case EComplexValType_char:
                return std::string(1, valc);
            case EComplexValType_string:
                return vals;
            case EComplexValType_Invalid:
                return "invalid";
            case EComplexValType_pairint:
                return std::to_string(valpint.first) + "|" + std::to_string(valpint.second);

            default:
                break;
        }
        return "unknown";
    }
    void FromString(const std::string& s) {
        if (s == "null") {
            valtype = EComplexValType_nullptr;
            return;
        }

        auto pos = s.find("|");
        if (pos == string::npos) {
            // todo@uniqs 这里没处理好double
            valtype = EComplexValType_int;
            vali = atoi(s.c_str());
        } else {
            valtype = EComplexValType_pairint;
            valpint.first = atoi(s.substr(0, pos).c_str());
            valpint.second = atoi(s.substr(pos + 1).c_str());
        }
    }
};

bool operator==(const ComplexVal& lhs, const ComplexVal& rhs) {
    if (lhs.valtype != rhs.valtype) return false;
    switch (lhs.valtype) {
        case EComplexValType_nullptr:
            return true;
        case EComplexValType_int:
            return lhs.vali == rhs.vali;
        case EComplexValType_int64:
            return lhs.vali64 == rhs.vali64;
        case EComplexValType_double:
            return lhs.vald == rhs.vald;
        case EComplexValType_bool:
            return lhs.valb == rhs.valb;
        case EComplexValType_string:
            return lhs.vals == rhs.vals;
        case EComplexValType_char:
            return lhs.valc == rhs.valc;
        case EComplexValType_Invalid:
            return true;
        case EComplexValType_pairint:
            return lhs.valpint.first == rhs.valpint.first && lhs.valpint.second == rhs.valpint.second;

        default:
            return false;
    }
    return false;
}

ostream& operator<<(ostream& os, const ComplexVal& cv) {
    os << cv.ToString();
    return os;
}

void vcomplexToString(string& ret, const vector<ComplexVal>& vals) {
    ret = "[";
    for (size_t i = 0; i < vals.size(); ++i) {
        const ComplexVal& val = vals[i];
        if (i > 0) ret += ",";
        ret += val.ToString();
    }
    ret += "]";
}

void vcomplexFilterInt(const vector<ComplexVal>& vals, vector<int>& ret) {
    for (auto val : vals) {
        if (val.IsNullptr()) continue;
        ret.emplace_back(val.vali);
    }
}

void vcomplexFromString(vector<ComplexVal>& vals, const std::string& str) {
    std::vector<Slice> vstrs;
    splitStr(str.c_str() + 1, str.size() - 2, ',', vstrs, INT_MAX);

    vals.resize(vstrs.size());
    for (size_t i = 0; i < vstrs.size(); ++i) {
        const Slice& vstr = vstrs[i];
        string s = vstr.str;
        s = s.substr(0, vstr.len);
        vals[i].FromString(s);
    }
}
