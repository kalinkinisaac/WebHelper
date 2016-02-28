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
    this->bit = new bool[32];
    for(int i = 0; i < 32; i++)
        this->bit[i] = false;
}
BitComponent::BitComponent(bool* new_bit)
{
    this->bit = new bool[32];
    for(int i = 0; i < 32; i++)
        this->bit[i] = new_bit[i];
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
/*bool* BitComponent::GetBit()
{
    return bit;
}*/

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
        this->bit[i] = true;
    this->reservedBits = new_reservedBits;
}

IP::IP(string input)
{
    SetBitIP(Parse(input));
}
void IP::SetBitIP(BitComponent new_bit_ip)
{
    this->bit = new bool[32];
    for(int i = 0; i < 32; i++)
        this->bit[i] = new_bit_ip[i];
}
void IP::Manager(string h_input)
{
    string ip, r_bits;
    for(int i = 0, a = 0; i < h_input.length(); i++)
    {
        if(h_input[i] == '/')
        {
            a = 1;
            continue;
        }
        if(!a)
            ip += h_input[i];
        else
            r_bits += h_input[i];
    }
    SetBitIP(Parse(ip));
    mask = *new Mask(r_bits);
}
BitComponent Parse(string input)
{
    BitComponent result;
    int buffer = 0;
    for(int i = 0, c = 0; i < 4; i++, c++)
    {
        while((input[c] != '.') && (c < input.length())){
                buffer = 10*buffer + (int)input[c] - '0';
            c++;
        }
        bool *quad_result = Convert10to2(buffer);
        for(int a = 0; a < 8; a++)
            result[8*i + a] = quad_result[a];
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
    for(int i = 0; i < Bin.length(); i++)
        result[i + 8 - Bin.length()] = Bin[i] - '0';
    return result;
}
