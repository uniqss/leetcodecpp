#pragma once

#include "StringHelper.h"

enum EComplexValType {
    EComplexValType_Invalid = -1,
    EComplexValType_nullptr,
    EComplexValType_int,
    EComplexValType_bool,
    EComplexValType_string,
};

class ComplexVal {
   public:
    EComplexValType valtype;
    int vali;
    bool valb;
    string vals;
    // ptr must be nullptr
    ComplexVal() : valtype(EComplexValType_Invalid) {}
    ComplexVal(void* ptr) : valtype(EComplexValType_nullptr) {}
    ComplexVal(int val) : valtype(EComplexValType_int), vali(val) {}
    ComplexVal(bool val) : valtype(EComplexValType_bool), valb(val) {}
    ComplexVal(const string& str) : valtype(EComplexValType_string), vals(str) {}

    bool IsNullptr() const { return valtype == EComplexValType_nullptr; }
    std::string ToString() const {
        switch (valtype) {
            case EComplexValType_nullptr:
                return "null";
            case EComplexValType_int:
                return std::to_string(vali);
            case EComplexValType_bool:
                return std::to_string(valb);
            case EComplexValType_string:
                return vals;
            case EComplexValType_Invalid:
                return "invalid";

            default:
                break;
        }
        return "unknown";
    }
    void FromString(const std::string& s) {
        if (s == "null") {
            valtype = EComplexValType_nullptr;
        } else {
            // 目前只有int
            valtype = EComplexValType_int;
            vali = atoi(s.c_str());
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
        case EComplexValType_bool:
            return lhs.valb == rhs.valb;
        case EComplexValType_string:
            return lhs.vals == rhs.vals;
        case EComplexValType_Invalid:
            return true;

        default:
            return false;
    }
    return false;
}


ofstream& operator<<(ofstream& ofs, const ComplexVal& cv) {
    switch (cv.valtype) {
        case EComplexValType_nullptr:
            cout << "null";
            break;
        case EComplexValType_int:
            cout << cv.vali;
            break;
        case EComplexValType_bool:
            if (cv.valb)
                cout << "true";
            else
                cout << "false";
            break;
        case EComplexValType_string:
            cout << cv.vals;
            break;

        default:
            cout << "not initialized";
            break;
    }
    return ofs;
}

void print(const vector<ComplexVal>& vc) {
    std::for_each(vc.begin(), vc.end(), [](const ComplexVal& cv) {
        switch (cv.valtype) {
            case EComplexValType_nullptr:
                cout << "null";
                break;
            case EComplexValType_int:
                cout << cv.vali;
                break;
            case EComplexValType_bool:
                if (cv.valb)
                    cout << "true";
                else
                    cout << "false";
                break;
            case EComplexValType_string:
                cout << cv.vals;
                break;

            default:
                cout << "not initialized";
                break;
        }
        cout << " ";
    });
    cout << endl;
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
