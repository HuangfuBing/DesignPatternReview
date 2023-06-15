/*  设一个模板具有参数T，在不同的情况下，T会取不同的类型，
    我们需要了解更多关于T的消息
    简单的sizeof等方法具有局限性
    使用类型分类技术提供T的信息；
    被指的或被引用的类型为baseT；
    最终涉及的C++基本类型为bottomT；
    int**中，baseT为int*，bottomT为int；
*/

//Like a poem, right?
//Code by HuangfuBing

#include <iostream>
#include <stddef.h>

using namespace std;

template<typename T>
class TypeInfo{
    public:
    enum{IsPtrT = 0, IsRefT = 0, IsArrayT = 0};
    typedef T baseT;
    typedef T bottomT;
};

template<typename T>
class TypeInfo<T*>{
    public:
    enum{IsPtrT = 1, IsRefT = 0, IsArrayT = 0};
    typedef T baseT;
    typedef typename TypeInfo<T>::bottom T bottomT;//This line is Key.
};

template<typename T>
class TypeInfo<T&>{
    public:
    enum{IsPtrT = 0, IsRefT = 1, IsArrayT = 0};
    typedef T baseT;
    typedef typename TypeInfo<T>::bottom T bottomT;//This line is Key.
};

template<typename T, size_t N>
class TypeInfo<T[N]>{
    public:
    enum{IsPtrT = 0, IsRefT = 0, IsArrayT = 1};
    typedef T baseT;
    typedef typename TypeInfo<T>::bottom T bottomT;//This line is Key.
};
