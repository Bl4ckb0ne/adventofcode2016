#include <iostream>
#include <vector>
#include <string>

struct Node
{
    Node(char value) : v(value) {}
    char v;
    Node* up = nullptr;
    Node* down = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
};

int main(int argc, char* argv[])
{
    // Init the pad
    Node* one = new Node('1');
    Node* two = new Node('2');
    Node* three = new Node('3');
    Node* four = new Node('4');
    Node* five = new Node('5');
    Node* six = new Node('6');
    Node* seven = new Node('7');
    Node* eight = new Node('8');
    Node* nine = new Node('9');
    Node* a = new Node('A');
    Node* b = new Node('B');
    Node* c = new Node('C');
    Node* d = new Node('D');

    // Relation
    one->down = three;
    two->down = six;
    two->right = three;
    three->up = one;
    three->down = seven;
    three->left = two;
    three->right = four;
    four->left = three;
    four->down = eight;
    five->right = six;
    six->up = two;
    six->down = a;
    six->left = five;
    six->right = seven;
    seven->up = three;
    seven->down = b;
    seven->left = six;
    seven->right = eight;
    eight->up = four;
    eight->down = c;
    eight->left = seven;
    eight->right = nine;
    nine->left = eight;
    a->up = six;
    a->right = b;
    b->up = seven;
    b->down = d;
    b->left = a;
    b->right = c;
    c->up = eight;
    c->left = b;
    d->up = b;

    Node* current = five;
   
    for(int i = 0; i < 5; i++)
    {
        std::string line;
    
        std::cin >> line;

        for(auto &it : line)
        {
            switch(it)
            {
                case 'R':
                    if(current->right != nullptr)
                    {   
                        current = current->right;
                    }
                    
                    break;
                case 'L':
                    if(current->left != nullptr)
                    {   
                        current = current->left;
                    }
                    
                    break;
                case 'D':
                    if(current->down != nullptr)
                    {   
                        current = current->down;
                    }
                    
                    break;
                case 'U':
                    if(current->up != nullptr)
                    {   
                        current = current->up;
                    }
                    
                    break;
                default:
                    break;
            };
        }

        std::cout << current->v;    
   
    }


    return 0;
}
