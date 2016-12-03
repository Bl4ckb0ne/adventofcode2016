#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    std::string line;
    int total = 0;

    do
    {
        std::getline(std::cin, line);   
        std::istringstream iss(line);
        
        int a, b, c = 0;
        iss >> a;
        iss >> b;
        iss >> c;

        if((a + b > c) && (a + c > b) && (c + b > a))
            total++;
 
    } while (std::cin.good());

    std::cout << total << '\n';

    return 0;
}
