//
//  IP.cpp
//  WebHelper
//
//  Created by Исаак Калинкин  on 27.02.16.
//  Copyright © 2016 EduAppHelpeer. All rights reserved.
//

#include "IP.hpp"
BitComponent::BitComponent()
{
    for(int i = 0; i < 32; i++)
        bit[i] = false;
}
BitComponent::BitComponent(bool* new_bit)
{
    for(int i = 0; i < 32; i++)
        bit[i] = new_bit[i];
}
BitComponent BitComponent::operator*=(BitComponent& rhs)
{
    *this = *this * rhs;
    return *this;
}
BitComponent operator*(BitComponent& lhs, BitComponent& rhs)
{
    BitComponent result;
    for(int i = 0; i < 32; i++)
    {
        result[i] = lhs[i] && rhs[i];
    }
    return result;
}
bool &BitComponent::operator[](int index)
{
    return this->bit[index];
}
bool* BitComponent::GetBit()
{
    return bit;
}
bool* BitComponent::GetQuadrant(int id)
{
    return bit + 8 * id;
}
//==-Mask-====================================

Mask::Mask()
{
    SetReservedBits(32);
}
Mask::Mask(int reservedBits)
{
    SetReservedBits(reservedBits);
}
void Mask::SetReservedBits(int new_reservedBits)
{
    for(int i = 0; i < new_reservedBits; i++)
        bit[i] = true;
    this->reservedBits = new_reservedBits;
}

IP::IP(string input)
{
    }
void IP::SetBitIP(BitComponent new_bit_ip)
{
    *this->bit = *new_bit_ip.GetBit();
}
BitComponent Parse(string input)
{
    BitComponent result;
    int buffer = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
            if(input[i + j] == '.')
                break;
            else
                buffer = 10*buffer + (int)input[i + j] - '0';
        bool *quad_result = Convert10to2(buffer);
        for(int a = 0; a < 8; a++)
            result.GetBit()[8*i + a] = quad_result[a];
        buffer = 0;
    }
    return result;
}
//==-
bool *Convert10to2(int input)
{
    bool* result = new bool[8];
    string Bin = "";
    while(input > 0)
    {
        if(input%2)
            Bin+='1';
        else
            Bin+='0';
        input/=2;
    }
    std::reverse(Bin.begin(), Bin.end());
    for(int i = 0; i < 8 - Bin.length(); i++)
        result[i] = false;
    for(int i = 8 - (int)Bin.length(); i < 8; i++)
        result[i] = (bool)((int)Bin[i] - '0');
    return result;
}
