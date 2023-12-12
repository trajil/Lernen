#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <ctime>

int numberOfNames;

std::vector<std::string> names;

void inputNumberOfNames()
{
    std::cout << "Enter the number of names: ";
    std::cin >> numberOfNames;
}

void inputNames()
{
    std::cout << "Enter the names, one at a time:" << std::endl;
    for (int i = 0; i < numberOfNames; ++i)
    {
        std::string name;
        std::cin >> name;
        names.push_back(name);
    }
}

int main()
{

    inputNumberOfNames();
    inputNames();

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Shuffle the names
    std::random_shuffle(names.begin(), names.end());

    // Output the shuffled names to individual text files
    for (int i = 0; i < numberOfNames; ++i)
    {
        // Create a file for each name
        std::ofstream outputFile(names[i] + ".txt");
        if (!outputFile)
        {
            std::cerr << "Error opening file for writing. Exiting program." << std::endl;
            return 1;
        }

        // Shuffle the names excluding the current one
        std::vector<std::string> otherNames = names;
        otherNames.erase(otherNames.begin() + i);
        std::random_shuffle(otherNames.begin(), otherNames.end());

        // Write one shuffled name to the file
        outputFile << otherNames[std::rand() % (numberOfNames - 1)] << std::endl;

        std::cout << "File " << names[i] << ".txt created." << std::endl;
    }

    return 0;
}
