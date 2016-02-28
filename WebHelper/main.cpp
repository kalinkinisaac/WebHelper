#include <iostream>
#include "IP.hpp"
using namespace std;

int main() {
    //GUI initialization
    bool* a;
    a = Convert10to2(17);
    for(int i = 0; i < 8; i++)
        cout << a[i] << " ";
    return 0;
}
