#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <cassert>
#include <cstdlib>   
#include <cmath>  

int main(int argc, char* argv[])
{
    std::cout << "Beginning at " << atoi(argv[1]) << " " << atoi(argv[2]) << '\n';

    std::pair<int, int> p(atoi(argv[1]), atoi(argv[2])); // first = x, second = y
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

    bool visited_twice = false;
    std::vector<std::pair<int, int>> visited;

    for(auto &it : path)
    {
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

        for(int i = 1; i <= length; i++)
        {
            if(d == 0)
                p.first++;
            else if(d == 90)
                p.second++;
            else if(d == -90)
                p.second--;
            else if(d == -180 || d == 180)
                p.first--;

            if(!visited_twice)
            {        
                if(std::find(visited.begin(), visited.end(), std::make_pair(p.first, p.second)) != visited.end())
                {
                    std::cout << p.first << "," << p.second << " visited twice\n";
                    visited_twice = true;
                }
                else
                {
                    visited.push_back(std::make_pair(p.first, p.second));
                }
            }
        }
    }

    std::cout << "Final position : (" << p.first << "," << p.second << ")\n";    
    std::cout << (std::abs(p.first) + std::abs(p.second)) << '\n';

    return 0;
}
