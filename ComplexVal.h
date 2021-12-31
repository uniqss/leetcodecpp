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
    int valtype;  // 0:nullptr 1:int 2:bool 3:string
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
};

bool operator==(const ComplexVal& lhs, const ComplexVal& rhs) {
    if (lhs.valtype != rhs.valtype) return false;
    switch (lhs.valtype) {
        case 0:
            return true;
        case 1:
            return lhs.vali == rhs.vali;
        case 2:
            return lhs.valb == rhs.valb;
        case 3:
            return lhs.vals == rhs.vals;
        case -1:
            return true;

        default:
            return false;
    }
    return false;
}
