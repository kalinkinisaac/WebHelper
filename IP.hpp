//
//  IP.hpp
//  WebHelper
//
//  Created by Исаак Калинкин  on 27.02.16.
//  Copyright © 2016 EduAppHelpeer. All rights reserved.
//

#ifndef IP_hpp
#define IP_hpp

#include <iostream>
using namespace std;
class BitComponent
{
protected:
        bool *bit;
public:

    BitComponent();
    BitComponent(bool *new_bit);
    BitComponent operator*=(BitComponent& rhs);
    bool &operator[](int index);
    //bool* GetBit();
};
BitComponent operator*(BitComponent& lhs, BitComponent& rhs);

class Mask : BitComponent
{
protected:
    int reservedBits;
public:

    Mask();
    Mask(int new_reservedBits);
    Mask(string new_reservedBits);
    void SetReservedBits(int new_reservedBits);
};
class IP : public BitComponent
{
protected:
    Mask mask;
public:
    IP(string input);
    IP(const IP& ip);
    void SetBitIP(BitComponent new_bit_ip);
    void SetIP(string IP);
    void SetMask(Mask new_mask);
    void Manager(string h_input);
    string GetIP();
    string GetNetID();
    string GetHostNum();
    int GetCapacity();
};
bool InputChecker(string input);
BitComponent Parse(string input);
bool *Convert10to2(int input);
int Convert2to10(bool *input);
#endif /* IP_hpp */
