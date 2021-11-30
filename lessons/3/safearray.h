#include <stddef.h>
#include <vector>
#include <cstring>
template<class T>
class SafeArray : public std::vector<T>
{
    T _null;
public:
    SafeArray(){
        memset(&_null, 0, sizeof(T));
    }
    T operator[](size_t idx)
    {
        if (idx >= this->size())
        {
            // warn here
            // throw std::logic_error("array index out of range");
            return _null;
        }
        return this->at(idx);
    }
};