#include <iostream>
#include "IP.hpp"
using namespace std;

int main() {
    //GUI initialization
    BitComponent a;
    a = Parse("8.8.8.8/27");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++)
            cout << a[j + 8*i];
        cout << endl;
    }
    return 0;
}
