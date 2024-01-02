#include <iostream>

std::string passwordSaved = "lommel";
std::string outputRight = "Passwort Korrekt! Danke!";
std::string outputWrong = "Passwort Falsch!";
std::string passwordUser;

void checkPassword(std::string passwordUser)
{
    if (passwordUser == passwordSaved)
    {
        std::cout << outputRight;
    }
    else
    {
        std::cout << outputWrong;
    }
    

};

int main()
{
    std::cout << "Please enter your password: ";
    std::cin >> passwordUser;
    checkPassword(passwordUser);


    return 0;
}