#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[])
{
    int x = 0;
    int y = 0;
   
    for(int i = 0; i < 5; i++)
    {
        std::string line;
    
        std::cin >> line;

        for(auto &it : line)
        {
            switch(it)
            {
                case 'R':
                    if(x < 1)
                        x++;
                    
                    break;
                case 'L':
                    if(x > -1)
                        x--;
                    
                    break;
                case 'D':
                    if(y > -1)
                        y--;
                    
                    break;
                case 'U':
                    if(y < 1)
                        y++;
                    
                    break;
                default:
                    break;
            };
        }
        
        if(x == -1 && y == 1)
            std::cout << 1;
        else if(x == 0 && y == 1) 
            std::cout << 2;
        else if(x == 1 && y == 1) 
            std::cout << 3;
        else if(x == -1 && y == 0)
            std::cout << 4;
        else if(x == 0 && y == 0) 
            std::cout << 5;
        else if(x == 1 && y == 0) 
            std::cout << 6;
        else if(x == -1 && y == -1) 
            std::cout << 7;
        else if(x == 0 && y == -1) 
            std::cout << 8;
        else if(x == 1 && y == -1) 
            std::cout << 9;
    }


    return 0;
}
