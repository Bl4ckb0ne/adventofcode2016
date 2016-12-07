#include <iostream>
#include <algorithm>
#include <string>
#include <limits>

#include "md5.h"

int main()
{
    std::string code = "########";
    //std::string key = "abc";
    std::string key = "ffykfhsq";

    int left = 8;

    std::cout << "First code \n";
    for(size_t i = 0;i < std::numeric_limits<size_t>::max(); ++i)
    {
        std::string hashed = md5(key + std::to_string(i));
        if(hashed.substr(0, 5) == "00000")
        {
            size_t at = 8 - left;
            if (code[at] == '#' && at < 8)
            {
                code[at] = hashed[5];
                std::cout << code << '\n';

                if (--left == 0)
                    break;
            }
        }
    }

    left = 8;
    code = "########";

    std::cout << "Second code \n";
    for(size_t i = 0;i < std::numeric_limits<size_t>::max(); ++i)
    {
        std::string hashed = md5(key + std::to_string(i));
        if(hashed.substr(0, 5) == "00000")
        {
            size_t at = static_cast<size_t>(hashed[5]) - '0';
            if (code[at] == '#' && at < 8)
            {
                code[at] = hashed[6];
                std::cout << code << '\n';

                if (--left == 0)
                    break;
            }
        }
    }


    std::cout << std::endl;
}
