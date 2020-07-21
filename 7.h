#pragma once
#include "stl.h"

class Solution {
public:
    int reverse(int x) {
        if (x == 0)
        {
            return 0;
        }
        int max1 = 214748364;
        int min1 = -214748364;
        int xmod = 0;
        int ret = 0;
        while (x != 0)
        {
            xmod = x % 10;
            x = x / 10;
            if (ret > max1 || (ret >= max1 && xmod > 7))
            {
                return 0;
            }
            if (ret < min1 || (ret <= min1 && xmod < -8))
            {
                return 0;
            }
            ret *= 10;
            ret += xmod;
        }
        return ret;
    }
};