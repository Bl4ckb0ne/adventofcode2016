#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cassert>
#include <cstdlib>   
#include <cmath>  

int main()
{
    std::pair<int, int> p; // first = x, second = y
    int d = 0;

    std::vector<std::string> path;

    std::string raw;

    do
    {
        std::cin >> raw;
        
        if(raw.back() == ',')
            raw.pop_back();
    
        path.push_back(raw);
    } while (std::cin.good());

    path.pop_back();

    for(auto &it : path)
    {
        std::cout << it << '\n';
    
        char direct = it.at(0);
        int length = atoi(it.substr(1).c_str());
       
        if(direct == 'L')
        {
            if(d == -180)
                d = 180;
            
            d -= 90;
        }
        else if(direct == 'R')
        {
            if(d == 180)
                d = -180;

            d += 90;
        } 

        assert(d <= 180 && "d > 180");
        assert(d >= -180 && "d < -180");        

        if(d == 0)
            p.first += length;
        else if(d == 90)
            p.second += length;
        else if(d == -90)
            p.second -= length;
        else if(d == -180 || d == 180)
            p.first -= length;
    }
    
    std::cout << (std::abs(p.first) + std::abs(p.second)) << '\n';

    return 0;
}
