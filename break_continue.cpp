/*basicly, "continue" and "break" are just two "goto"s: 
    -"break" jumps to the very next '}' 
    -"continue" jumps to the previous '{'
*/
#include <iostream>

int main()
{
    int target = 20;
    // using break to cancel the outer loop
    std::cout << "Break in loop: \n";
    for (int i = 0; i < target; i++)
    {
        if (i == 13)
        {
            break;
        }

        std::cout << i << "\n";
    }
    // using continue to skip an iteration
    std::cout << "Break in loop: \n";
    for (int i = 0; i < target; i++)
    {
        if (i == 13)
        {
            continue;
            ;
        }

        std::cout << i << "\n";
    }

    return 0;
}