#include <iostream>
#include <string>
int main()
{

    // char Gruß[20] = "Hallo Welt!"; // Character mit 20 Stellen -1 für das NULL Zeichen am Ende
    //
    // std::cout << Gruß << std::endl;

    std::string hello("Hello World!\n");

    std::cout << hello;

    return 0;
}