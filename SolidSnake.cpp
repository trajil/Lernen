#include <iostream>
#include <unistd.h>
#include <ctime>

using namespace std;

// Function prototypes
void moveUp(int &rowIndex, int &colIndex, int mapRows, char **grid, char player);
void moveDown(int &rowIndex, int &colIndex, int mapRows, char **grid, char player);
void moveLeft(int &rowIndex, int &colIndex, int mapColums, char **grid, char player);
void moveRight(int &rowIndex, int &colIndex, int mapColums, char **grid, char player);
int countTargets(char **grid, int mapRows, int mapColums);

int main()
{
    int height, width;
    cout << "Please specify the dimensions of the map!\n";
    cout << "Height: ";
    cin >> height;
    cout << "Width: ";
    cin >> width;

    int snakeSize = 1;
    int rowIndex = 0;
    int colIndex = 0;
    int randomNum;
    int initialTargets = 0;
    int currentTargetsNumber;
    int tries = 100;
    char player = 'X';
    char direction;

    char **grid = new char *[height];
    for (int i = 0; i < height; ++i)
        grid[i] = new char[width];

    char mapBlocks[] = {'*', 'F', '*', '*', '*', '*', '*', '*'};

    srand(time(NULL));
    // Randomly filling the map with blocks
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            randomNum = (rand() % 8);
            grid[i][j] = mapBlocks[randomNum];
        }
    }
    grid[0][0] = player; // Initial position of the player

    // Counting the initial number of targets
    initialTargets = countTargets(grid, height, width);

    while (tries > 0)
    {
        currentTargetsNumber = countTargets(grid, height, width);

        // Printing the map
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cout << grid[i][j];
            }
            cout << '\n';
        }

        // Calculating the size of the snake
        snakeSize = (initialTargets - currentTargetsNumber) + 1;

        cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout << "Targets left: " << currentTargetsNumber << '\n';
        cout << "Tries left: " << tries << '\n';
        cout << "Snake size: " << snakeSize << '\n';

        cout << "Enter direction (WASD, e-end):\n";
        cin >> direction;
        tries--;

        if (direction == 'e')
            break;

        switch (direction)
        {
        case 'w':
            moveUp(rowIndex, colIndex, height, grid, player);
            break;
        case 's':
            moveDown(rowIndex, colIndex, height, grid, player);
            break;
        case 'a':
            moveLeft(rowIndex, colIndex, width, grid, player);
            break;
        case 'd':
            moveRight(rowIndex, colIndex, width, grid, player);
            break;
        }
    }
    cout << "Thanks for playing\n";

    // Cleaning up dynamically allocated memory
    for (int i = 0; i < height; ++i)
        delete[] grid[i];
    delete[] grid;

    return 0;
}

// Function implementations
void moveUp(int &rowIndex, int &colIndex, int mapRows, char **grid, char player)
{
    if (rowIndex > 0)
    {
        grid[rowIndex][colIndex] = '*';
        rowIndex--;
        grid[rowIndex][colIndex] = player;
    }
    else if (rowIndex == 0)
    {
        grid[rowIndex][colIndex] = '*';
        rowIndex = mapRows - 1;
        grid[rowIndex][colIndex] = player;
    }
}

void moveDown(int &rowIndex, int &colIndex, int mapRows, char **grid, char player)
{
    if (rowIndex < mapRows - 1)
    {
        grid[rowIndex][colIndex] = '*';
        rowIndex++;
        grid[rowIndex][colIndex] = player;
    }
    else if (rowIndex == mapRows - 1)
    {
        grid[rowIndex][colIndex] = '*';
        rowIndex = 0;
        grid[rowIndex][colIndex] = player;
    }
}

void moveLeft(int &rowIndex, int &colIndex, int mapColums, char **grid, char player)
{
    if (colIndex > 0)
    {
        grid[rowIndex][colIndex] = '*';
        colIndex--;
        grid[rowIndex][colIndex] = player;
    }
    else if (colIndex == 0)
    {
        grid[rowIndex][colIndex] = '*';
        colIndex = mapColums - 1;
        grid[rowIndex][colIndex] = player;
    }
}

void moveRight(int &rowIndex, int &colIndex, int mapColums, char **grid, char player)
{
    if (colIndex < mapColums - 1)
    {
        grid[rowIndex][colIndex] = '*';
        colIndex++;
        grid[rowIndex][colIndex] = player;
    }
    else if (colIndex == mapColums - 1)
    {
        grid[rowIndex][colIndex] = '*';
        colIndex = 0;
        grid[rowIndex][colIndex] = player;
    }
}

int countTargets(char **grid, int mapRows, int mapColums)
{
    int count = 0;
    for (int i = 0; i < mapRows; i++)
    {
        for (int j = 0; j < mapColums; j++)
        {
            if (grid[i][j] == 'F')
                count++;
        }
    }
    return count;
}
