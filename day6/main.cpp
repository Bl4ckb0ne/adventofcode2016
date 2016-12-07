#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

std::vector<std::pair<char, int>> frequency(std::vector<std::string>& list, size_t pos)
{
    std::map<char, int> m;
    for(auto &it : list)
    {
        m[it[pos]] += 1;
    }

    std::vector<std::pair<char, int>> v;
    for(auto &it : m)
    {
        v.push_back(std::make_pair(it.first, it.second));
    }

    std::stable_sort(v.begin(), v.end(), [](auto& left, auto& right){ return left.second > right.second; });
	
    return v;
}

int main(int argc, char* argv[])
{
    std::vector<std::string> data;

    do
    {
        std::string line;
        std::getline(std::cin, line);   
    
        if(line.size() == 0)
            break;

        data.push_back(line);

    } while (std::cin.good());

    std::cout << "Most : ";
    for(size_t i = 0; i < 8; i++)
    {
        std::cout << frequency(data, i)[0].first;
    }
    std::cout << '\n';

    std::cout << "Least : ";
    for(size_t i = 0; i < 8; i++)
    {
        std::cout << frequency(data, i).back().first;
    }

    std::cout << '\n';
   
    return 0;
}
