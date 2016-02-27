//
//  IP.hpp
//  WebHelper
//
//  Created by Исаак Калинкин  on 27.02.16.
//  Copyright © 2016 EduAppHelpeer. All rights reserved.
//

#ifndef IP_hpp
#define IP_hpp

#include <stdio.h>
class IP
{
    int bitIP;
    IP();
    IP(int input);
    IP(const IP& ip);
};
IP Parse(int input);
int Convert10to2(int input);
int Convert2to10(int input);
#endif /* IP_hpp */
