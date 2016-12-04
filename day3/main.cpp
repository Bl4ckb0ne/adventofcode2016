#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <tuple>

int main(int argc, char* argv[])
{
    std::vector<std::tuple<int, int, int>> triangles;

    do
    {
        std::string line;
        std::getline(std::cin, line);   
    
        if(line.size() == 0)
            break;

        std::istringstream iss(line);        
        int a, b, c;
        iss >> a >> b >> c;
        triangles.push_back(std::make_tuple(a, b, c));
    
    } while (std::cin.good());

    // part 1
    int total1 = 0;
    for(auto &it : triangles)
    {
        int a = std::get<0>(it);
        int b = std::get<1>(it);
        int c = std::get<2>(it);
        
        if((a + b > c) && (c + b > a) && (a + c > b))
            total1++;
    }
    std::cout << "Part 1 : " << total1 << " triangles\n";

    // part 2
    int total2 = 0;
    for(size_t i = 0; i < triangles.size();)
    {
        int a1 = std::get<0>(triangles[i]);
        int b1 = std::get<1>(triangles[i]);
        int c1 = std::get<2>(triangles[i]);

        i++;
        
        int a2 = std::get<0>(triangles[i]);
        int b2 = std::get<1>(triangles[i]);
        int c2 = std::get<2>(triangles[i]);

        i++;
        
        int a3 = std::get<0>(triangles[i]);
        int b3 = std::get<1>(triangles[i]);
        int c3 = std::get<2>(triangles[i]);
        
        i++;
               
        if((a1 + a2 > a3) && (a3 + a1 > a2) && (a2 + a3 > a1))
            total2++;
               
        if((b1 + b2 > b3) && (b3 + b1 > b2) && (b2 + b3 > b1))
            total2++;
               
        if((c1 + c2 > c3) && (c3 + c1 > c2) && (c2 + c3 > c1))
            total2++;
    }
    std::cout << "Part 2 : " << total2 << " triangles\n";

    return 0;
}
