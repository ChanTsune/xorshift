#include "xorshift.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace xorshift;
    using namespace std;
    xorshift128Plus x128;

    x128.seed(100,200);

    size_t loop = 1000;

    while (loop--)
        cout << x128() << endl;


    return 0;
}
