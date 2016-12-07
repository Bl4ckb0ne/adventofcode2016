#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

std::vector<std::pair<char, int>> rle(std::vector<std::string> &tokens)
{
    std::map<char, int> m;
    for(auto &it : tokens)
    {
        for(auto &c : it)
        {
            m[c] += 1;
        }
    }

    std::vector<std::pair<char, int>> v;
    for(auto &it : m)
    {
        v.push_back(std::make_pair(it.first, it.second));
    }

    std::stable_sort(v.begin(), v.end(), [](auto& left, auto& right){ return left.second > right.second; });
	
    return v;
}

bool validate_checksum(std::vector<std::pair<char, int>>& data, std::string& checksum)
{
    for(size_t i = 0; i < checksum.size(); i++)
    {
        if(checksum[i] != data[i].first)
            return false;
    }

    return true;
}


int main()
{
    int total = 0;
	int i = 0;
    do
    {
        std::string line;
        std::getline(std::cin, line);   
    
        if(line.size() == 0)
            break;

		i++;
        
		std::string room = line.substr(0, line.find_first_of("["));
        std::string checksum = line.substr(line.find_first_of("[") + 1, line.find_last_of("]"));
        checksum.pop_back();

        std::vector<std::string> name; 
        
        size_t pos = 0;
        std::string token;
        while ((pos = room.find("-")) != std::string::npos) {
            token = room.substr(0, pos);
            name.push_back(token);
            room.erase(0, pos + 1);
        }
        int sumID = atoi(room.c_str());
        std::vector<std::pair<char, int>> compressed = rle(name);

        if(validate_checksum(compressed, checksum))
        {   
            total += sumID;
        }
    
    } while (std::cin.good());
  
    std::cout << "total : " << total << '\n';
 
    return 0;
}
