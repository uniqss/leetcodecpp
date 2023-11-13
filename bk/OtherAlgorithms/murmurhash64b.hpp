#pragma once

#include <string>
#include <cstdint>

namespace utility {
static inline unsigned long long MurmurHash64B(const void *key, int len, unsigned int seed = 0xee6b27eb) {
    const unsigned int m = 0x5bd1e995;
    const int r = 24;

    unsigned int h1 = seed ^ len;
    unsigned int h2 = 0;

    const unsigned int *data = (const unsigned int *)key;

    while (len >= 8) {
        unsigned int k1 = *data++;
        k1 *= m;
        k1 ^= k1 >> r;
        k1 *= m;
        h1 *= m;
        h1 ^= k1;
        len -= 4;

        unsigned int k2 = *data++;
        k2 *= m;
        k2 ^= k2 >> r;
        k2 *= m;
        h2 *= m;
        h2 ^= k2;
        len -= 4;
    }

    if (len >= 4) {
        unsigned int k1 = *data++;
        k1 *= m;
        k1 ^= k1 >> r;
        k1 *= m;
        h1 *= m;
        h1 ^= k1;
        len -= 4;
    }

    switch (len) {
        case 3:
            h2 ^= ((unsigned char *)data)[2] << 16;
        case 2:
            h2 ^= ((unsigned char *)data)[1] << 8;
        case 1:
            h2 ^= ((unsigned char *)data)[0];
            h2 *= m;
    };

    h1 ^= h2 >> 18;
    h1 *= m;
    h2 ^= h1 >> 22;
    h2 *= m;
    h1 ^= h2 >> 17;
    h1 *= m;
    h2 ^= h1 >> 19;
    h2 *= m;

    unsigned long long h = h1;

    h = (h << 32) | h2;

    return h;
}

static inline unsigned long long Murmurhash64bStr(const std::string &str) {
    return MurmurHash64B(str.c_str(), (int)str.size());
}
template <typename T1, typename T2>
static inline unsigned long long __murmurhash64b84(T1 v1, T2 v2) {
    char szTmp[12];
    *((T1 *)(char *)szTmp) = v1;
    *((T2 *)((char *)szTmp + 8)) = v2;
    return MurmurHash64B(szTmp, 12);
}
template <typename T1, typename T2>
static inline unsigned long long __murmurhash64b88(T1 v1, T2 v2) {
    char szTmp[16];
    *((T1 *)(char *)szTmp) = v1;
    *((T2 *)((char *)szTmp + 8)) = v2;
    return MurmurHash64B(szTmp, 16);
}
static inline unsigned long long Murmurhash64bII(int64_t i1, int i2) {
    return __murmurhash64b84(i1, i2);
}
static inline unsigned long long Murmurhash64bII(uint64_t i1, int i2) {
    return __murmurhash64b84(i1, i2);
}
static inline unsigned long long Murmurhash64bII(int64_t i1, uint32_t i2) {
    return __murmurhash64b84(i1, i2);
}
static inline unsigned long long Murmurhash64bII(uint64_t i1, uint32_t i2) {
    return __murmurhash64b84(i1, i2);
}
static inline unsigned long long Murmurhash64bII(int64_t i1, int64_t i2) {
    return __murmurhash64b88(i1, i2);
}
static inline unsigned long long Murmurhash64bII(int64_t i1, uint64_t i2) {
    return __murmurhash64b88(i1, i2);
}
static inline unsigned long long Murmurhash64bII(uint64_t i1, int64_t i2) {
    return __murmurhash64b88(i1, i2);
}
static inline unsigned long long Murmurhash64bII(uint64_t i1, uint64_t i2) {
    return __murmurhash64b88(i1, i2);
}

}  // namespace utility
