#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>

std::vector<std::string> passWord;
int passwordLength, wait;

void inputPasswordLength()
{
    std::cout << "Enter the lenght of your password: ";
    std::cin >> passwordLength;
}

int main()
{
    std::srand(std::time(0));
    inputPasswordLength();
    passWord.resize(passwordLength);

    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();

    std::ofstream outputFile("passwords/passwordlist.txt");
    for (int i = 0; i < passwordLength; i++)
    {
        int random = 33 + std::rand() % 94;
        //std::cout << random << " ";
        char randomChar = random;

        passWord[i] = randomChar;
        //std::cout << randomChar << std::endl;
        // outputFile << random << " : ";
        outputFile << randomChar;
    }
    outputFile.close();

    // Stop the timer
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Execution time: " << elapsed.count() << " seconds\n";

    std::cin >> wait;
    return 0;
}