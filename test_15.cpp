#include "stl.h"
#include "15_3sum2.inl"

int main(){
    vector<int> vi = {-1,0,1,2,-1,-4};
    Solution s;
    auto ret = s.threeSum(vi);
    pvvi(ret);
    return 0;
}
