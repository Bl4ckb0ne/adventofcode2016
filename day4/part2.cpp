#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

std::string rot(int shift, std::string& data)
{
	std::string s; 
	for(auto& c : data)
	{
        if(c == '-')
            s.push_back(' ');
        else if(c == '[' || c == ']')
            s.push_back(c);
        else if(isdigit(c))
            s.push_back(c);
		else if(c + shift <= 'z')
			s.push_back((char) c + shift);
		else
			s.push_back((char) c + shift - 26);
	}
        
    return s;
}

int main()
{
	int i = 0;
    do
    {
        std::string line;
        std::getline(std::cin, line);   
    
        if(line.size() == 0)
            break;

		i++;
		
		int sectorID = atoi(line.substr(line.find('[') - 3, 3).c_str());

		line = rot(sectorID % 26, line);
    
        if (line.find("north") != std::string::npos)
            std::cout << line << '\n';

    } while (std::cin.good());
  
    return 0;
}
