#include <iostream>
#include <map>

// Enum for different cases
enum Essen
{
    Milch,
    Kaffee,
    Zucker
};

int main()
{
    // Get user input as a string
    std::string userInput;
    std::cout << "Enter your product: ";
    std::cin >> userInput;
    
    // Convert the string to int
    int selectedCase = std::stoi(userInput);

    // Switch based on the enum
    switch (selectedCase)
    {
    case Milch:
        std::cout << "You selected Milch\n";
        break;
    case Kaffee:
        std::cout << "You selected Kaffee\n";
        break;
    case Zucker:
        std::cout << "You selected Zucker\n";
        break;
    default:
        std::cout << "Invalid input\n";
        break;
    }

    return 0;
}
