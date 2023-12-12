#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

int numberOfNames, wait;

std::vector<std::string> fileNames;
std::vector<std::string> contentNames;

void inputNumberOfNames()
{
    std::cout << "Enter the number of names: ";
    std::cin >> numberOfNames;
}

void inputNames()
{
    std::cout << "Enter the names, one at a time: ";
    for (int i = 0; i < numberOfNames; ++i)
    {
        std::string name;
        std::cin >> name;
        fileNames.push_back(name);
    }
}

int main()
{
    std::srand(std::time(0));

    inputNumberOfNames();
    inputNames();
    contentNames = fileNames;
    int remainingNames = numberOfNames;
    
    for (int i = 0; i < numberOfNames; ++i)
    {
        int randomIndex = std::rand() % (remainingNames);

        std::ofstream outputFile(fileNames[0] + ".txt");

        while (fileNames[0] == contentNames[randomIndex])
        {
            randomIndex = std::rand() % (remainingNames);
        }
        outputFile << contentNames[randomIndex] << std::endl;
        contentNames.erase(contentNames.begin() + (randomIndex));

        std::cout << "File " << fileNames[0] << ".txt created." << std::endl;
        fileNames.erase(fileNames.begin() + 0);

        remainingNames--;
    }
    std::cin >> wait;

    return 0;
}
