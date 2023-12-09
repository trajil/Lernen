#include <iostream>
#include <cstdlib>
#include <time.h>

void fill_map();
void spawn_ship_A();
void spawn_ship_B();
void sink_ship_A();
void sink_ship_B();
void display_map();
void count_remaining_ships();

int const columns = 20;
int const rows = 20;
int counting_a = 0;
int counting_b = 0;
double spawnrate = 0.05;

char map[rows][columns];

char const water = '.';
char const spawned_ship_A = 'a';
char const spawned_ship_B = 'b';
char const symbol_sunken_ship_A = 'A';
char const symbol_sunken_ship_B = 'B';

int main()
{
    srand(time(NULL));
    fill_map();

    spawn_ship_A();
    spawn_ship_B();

    // sink_ship_A();
    // sink_ship_B();

    display_map();

    count_remaining_ships();
    return 0;
}

void spawn_ship_A()
{
    int erwartungswert_a = rows * columns * spawnrate;
    do
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                bool spawn = false;
                rand() % (100) <= (spawnrate * 100) ? spawn = true : spawn = false;

                if (map[i][j] != spawned_ship_B && spawn)
                {
                    map[i][j] = spawned_ship_A;
                    counting_a++;
                }
                if (counting_a >= erwartungswert_a * 1.3)
                {
                    return;
                }
            }
        }
    } while (counting_a < erwartungswert_a * 0.7);
}

void spawn_ship_B()
{
    int erwartungswert_b = rows * columns * spawnrate;
    do
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                bool spawn = false;
                rand() % (100) <= (spawnrate * 100) ? spawn = true : spawn = false;

                if (map[i][j] != spawned_ship_A && spawn)
                {
                    map[i][j] = spawned_ship_B;
                    counting_b++;
                }
                if (counting_b >= erwartungswert_b * 1.3)
                {
                    return;
                }
            }
        }
    } while (counting_a < erwartungswert_b * 0.7);
}

void sink_ship_A()
{
    map[4][4] = symbol_sunken_ship_A;
}

void sink_ship_B()
{
    map[2][6] = symbol_sunken_ship_B;
}

void fill_map()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            map[i][j] = water;
        }
    }
}

void display_map()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            switch (map[i][j])
            {
            case water:
                std::cout << water;
                break;
            case symbol_sunken_ship_A:
                std::cout << symbol_sunken_ship_A;
                break;
            case symbol_sunken_ship_B:
                std::cout << symbol_sunken_ship_B;
                break;
            case spawned_ship_A:
                std::cout << spawned_ship_A;
                break;
            case spawned_ship_B:
                std::cout << spawned_ship_B;
                break;

            default:
                std::cout << water;
                break;
            };
        }
        std::cout << "\n";
    }
}

void count_remaining_ships()
{
    double counting_ships_A = 0;
    double counting_ships_B = 0;
    double counting_water = rows * columns;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (map[i][j] == spawned_ship_A)
            {
                counting_ships_A++;
            }
            else if (map[i][j] == spawned_ship_B)
            {
                counting_ships_B++;
            }
        }
    }
    std::cout << "Ships of type A :" << counting_ships_A << " ( " << (counting_ships_A / counting_water) * 100 << "% )" << std::endl;
    std::cout << "Ships of type B :" << counting_ships_B << " ( " << (counting_ships_B / counting_water) * 100 << "% )" << std::endl;
    std::cout << "Water in the sea: " << counting_water << std::endl;
}