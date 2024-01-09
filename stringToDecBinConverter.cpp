#include <iostream>
#include <bitset>
#include <fstream>
#include <vector>

int wait;
std::string input;

void InputString()
{
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
};

void TranslateToBinDec()
{
    std::ofstream outputFile("string_to_binDec_output.txt");
    for (char c : input)
    {
        std::bitset<8> binary(c);
        std::cout << "Character: " << c << "\n";
        std::cout << "Decimal: " << static_cast<int>(c) << "\n";
        std::cout << "Binary: " << binary << "\n\n";

        outputFile << "Character: " << c ;
        outputFile << " Decimal: " << static_cast<int>(c);
        outputFile << " Binary: " << binary << "\n\n";
    };
};
int main()
{
    InputString();
    TranslateToBinDec();

    std::cout << "File >string_to_binDec_output.txt< created." << std::endl;
    std::cin >> wait;
    return 0;
}