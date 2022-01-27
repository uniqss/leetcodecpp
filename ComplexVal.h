#pragma once

enum EComplexValType {
    EComplexValType_Invalid = -1,
    EComplexValType_nullptr,
    EComplexValType_int,
    EComplexValType_bool,
    EComplexValType_string,
};

class ComplexVal {
   public:
    EComplexValType valtype;  // 0:nullptr 1:int 2:bool 3:string
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
