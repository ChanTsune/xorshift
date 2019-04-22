# xorshift
An implementation of xorshift that provides an interface similar to the c++ std::random  

## How to use
Basically the same as std::radrom.  
The difference is the number of seed values needed during initialization.  

## xorshift32  

```cpp
#include "xorshift.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace xorshift;
    using namespace std;
    xorshift32 x32;

    x32.seed(100);

    size_t loop = 1000;

    while (loop--)
        cout << x32() << endl;

    return 0;
}
```
