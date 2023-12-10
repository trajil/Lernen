#include <iostream>
#include <cstdlib>
#include <time.h>

void load_banner(char banner);
void fill_map();
void spawn_ship_A();
void spawn_ship_B();
void target_control_A(int c, int r);
void target_control_B(int c, int r);
void display_map();
void count_remaining_ships();
void turn(char player);
void check_for_loser();

int const columns = 8;
int const rows = 8;
int counting_a = 0;
int counting_b = 0;
double spawnrate = 0.1;

char map[rows][columns];

char const water = '.';
char const spawned_ship_A = 'p';
char const spawned_ship_B = 'n';
char const symbol_sunken_ship_A = 'P';
char const symbol_sunken_ship_B = 'N';

bool game_not_over;

int main()
{

    srand(time(NULL));
    fill_map();
    spawn_ship_A();
    spawn_ship_B();
    load_banner('S');
    std::cout << "Ahoi, this will be a fierce battle for the Bermuda triangle! Who will win - pirates or the royal fleet? \n\n";

    do
    {
        display_map();
        turn('A');
        turn('B');
        check_for_loser();
    } while (game_not_over);
    std::cout << std::endl;

    count_remaining_ships();
    return 0;
}

void check_for_loser()
{
    if (counting_a > 0 && counting_b > 0)
    {
        game_not_over = true;
        return;
    }
    else if (counting_a == 0 && counting_b > 0)
    {
        game_not_over = false;
        load_banner('R');
        std::cout << "Hail to the Queen, we did it, Sire! This pirate pest is gone for ever. Jolly good!\n";
        return;
    }
    else if (counting_b == 0 && counting_a > 0)
    {
        game_not_over = false;
        load_banner('P');
        std::cout << "O Captain, my captain! After a long fight the seas be ours! Rum for everyone!!!\n";
        return;
    }
    else
    {
        game_not_over = false;
        load_banner('E');
        std::cout << "Aggression only leads to destruction. Neither the pirates nor the royal fleet could prevail after this long enduring battle...\nMaybe this serves as a lesson for the ones to come, who knows?\n";
        return;
    }
}

void spawn_ship_A()
{
    int erwartungswert_a = rows * columns * spawnrate;
    do
    {
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < columns; j++)
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
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < columns; j++)
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

void target_control_A(int c, int r)
{
    switch (map[c][r])
    {
    case spawned_ship_B:
        map[c][r] = symbol_sunken_ship_B;
        counting_b--;
        std::cout << "Got that one!\n";
        break;
    case symbol_sunken_ship_B:
        std::cout << "Drunkin' bastard, we already hit that one!\n";
        break;
    case spawned_ship_A:
        std::cout << "Muteny...that's one of our guys!\n";
        break;
    case symbol_sunken_ship_A:
        std::cout << "Dammit - that poor bastard 's already drowin'!\n";
        break;
    default:
        std::cout << "Arrr!!! A miss...\n";
        break;
    }
}

void target_control_B(int c, int r)
{
    switch (map[c][r])
    {
    case spawned_ship_A:
        map[c][r] = symbol_sunken_ship_A;
        std::cout << "Got that one!\n";
        counting_a--;
        break;
    case symbol_sunken_ship_A:
        std::cout << "Sir, this target is already eliminated.\n";
        break;
    case spawned_ship_B:
        std::cout << "With all due respect, Sir, but this one belongs to us.\n";
        break;
    case symbol_sunken_ship_B:
        std::cout << "Sir, we need to help those men - not shoot them!\n";
        break;
    default:
        std::cout << "We didn't hit anything, Sir.\n";
        break;
    }
}

void turn(char player)
{
    int target_row, target_column;
    if (player == 'A')
    {
        std::cout << "Pirate, send 'em to hell!\nColumn: ";
        std::cin >> target_column;
        std::cout << "\nRow: ";
        std::cin >> target_row;
        std::cout << std::endl;
        target_control_A(target_row, target_column);
        std::cout << "Royal fleet left: " << counting_b << "\n\n\n";
    }
    else if (player == 'B')
    {
        std::cout << "Admiral, we need your fire coordinance!\nColumn: ";
        std::cin >> target_column;
        std::cout << "\nRow: ";
        std::cin >> target_row;
        std::cout << std::endl;
        target_control_B(target_row, target_column);
        std::cout << "Dirty pirates left: " << counting_a << "\n\n\n";
    }

    else
    {
        return;
    }
}

void fill_map()
{
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < columns; j++)
        {

            map[i][j] = water;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        map[i][0] = '0' + i;
    }
    for (int j = 0; j < columns; j++)
    {
        map[0][j] = '0' + j;
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
            case symbol_sunken_ship_A:
                std::cout << symbol_sunken_ship_A << "   ";
                break;
            case symbol_sunken_ship_B:
                std::cout << symbol_sunken_ship_B << "   ";
                break;
            case spawned_ship_A:
                std::cout << spawned_ship_A << "   ";
                break;
            case spawned_ship_B:
                std::cout << spawned_ship_B << "   ";
                break;
            case water:
                std::cout << water << "   ";
                break;

            default:
                std::cout << map[i][j] << "   ";
                break;
            };
        }
        std::cout << "\n\n";
    }
}

// for debugging
void count_remaining_ships()
{
    double remaining_ships_A = 0;
    double remaining_ships_B = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (map[i][j] == spawned_ship_A)
            {
                remaining_ships_A++;
            }
            else if (map[i][j] == spawned_ship_B)
            {
                remaining_ships_B++;
            }
        }
    }
    std::cout << "Ships of type A :" << remaining_ships_A << " ( " << (remaining_ships_A / (rows * columns)) * 100 << "% )" << std::endl;
    std::cout << "Ships of type B :" << remaining_ships_B << " ( " << (remaining_ships_B / (rows * columns)) * 100 << "% )" << std::endl;
    std::cout << "Water in the sea: " << rows * columns << std::endl;
}

void load_banner(char banner)
{
    switch (banner)
    {
    case 'S':
        std::cout << "                   |    |    |                   \n"
                     "                  )_)  )_)  )_)                  \n"
                     "                 )___))___))___)\\                \n"
                     "                )____)____)_____)\\              \n"
                     "              _____|____|____|____\\\\__          \n"
                     "     ---------\\                   /---------    \n"
                     "       ^^^^^ ^^^^^^^^^^^^^^^^^^^^^               \n"
                     "         ^^^^      ^^^^     ^^^    ^^            \n"
                     "              ^^^^      ^^^                      \n"
                     "                                                \n"
                     "     ~~~~ ^^^^^^^^ ^^^^^^^^^^ ^^^^^^^^^^ ~~~~    \n"
                     "       ~~~~    ^^^^     ^^^^     ^^^^    ~~~~    \n"
                     "                                                \n"
                     "   ~~~~~~~ ^^^^^^^^^^ ^^^^^^^^^^ ^^^^^^^^^ ~~~~~ \n"
                     "     ~~~~~    ^^^^^       ^^^^^     ^^^^    ~~~~ \n"
                     "                                                \n"
                     "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        break;
    case 'P':
        std::cout << ".=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n"
                     "|                     ______                     |\n"
                     "|                  .-\"      \"-.                  |\n"
                     "|                 /            \\                 |\n"
                     "|     _          |              |          _     |\n"
                     "|    ( \\         |,  .-.  .-.  ,|         / )    |\n"
                     "|     > \"=._     | )(__/  \\__)( |     _.=\" <     |\n"
                     "|    (_/\"=._\"=._ |/     /\\     \\| _.=\"_.=\"\\_)    |\n"
                     "|           \"=._\"(_     ^^     _)\"_.=\"           |\n"
                     "|               \"=\\__|IIIIII|__/=\"               |\n"
                     "|              _.=\"| \\IIIIII/ |\"=._              |\n"
                     "|    _     _.=\"_.=\"\\          /\"=._\"=._     _    |\n"
                     "|   ( \\_.=\"_.=\"     `--------`     \"=._\"=._/ )   |\n"
                     "|    > _.=\"                            \"=._ <    |\n"
                     "|   (_/                                     \\_)  |\n"
                     "|                                                |\n"
                     "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-='\n";
        break;
    case 'R':
        std::cout << "=====================================\n"
                     "          VICTORY AT SEA\n"
                     "      Royal Navy Prevails!\n"
                     "=====================================\n"
                     "             |    |    \n"
                     "            )_)  )_)   \n"
                     "           )___))___)  \n"
                     "          )____)____)  \n"
                     "        _____|____|____\n"
                     "  ---------\\         /---------\n"
                     "    ^^^^^ ^^^^^^^^^^^^^^^^^\n"
                     "      ^^^^      ^^^^     ^^^\n"
                     "           ^^^^      ^^^\n"
                     "=====================================\n";
        break;
    case 'E':
        std::cout << "%%%%%%%%%%%%%%%################################%##%%%###########################\n"
                     "%%%%%%%%%%#######################################%##%%%######################*##\n"
                     "#%%%%%%%%%#############################******#***###############################\n"
                     "#%%%%%%%%###############################***####**###############################\n"
                     "%%%%%%%%%##%####################**###******##****#*#**##**######################\n"
                     "%%%%%%%%%%%%######################********************#****###############******\n"
                     "%%%%%%%%%%%########################**************************##*###########*****\n"
                     "%%%#%#%%%%%#%##**#######*############******##*##******#*********#############***\n"
                     "%%%%%#+*#######*+=**####****########***************************#######%%%%%#####\n"
                     "%%%%%%#=+*######**+=******+=+*******************#*************####%%############\n"
                     "%%%%%%#*+++##%%#****=+*###++==++++++++***#########****######**##################\n"
                     "%%%%%%##*#++*##**##**+++*++**===+*#****++**###**************##**###############*\n"
                     "%%%%%%%#*##*==+**####*====++++=====++++++*****#*************#****###############\n"
                     "%%%%%%%##***#*++=*#**++++=--+++*=::-==+*#**********+******##################*###\n"
                     "%%%%%%%#**##%#*=:=+++++++===-=++++===-==+++****+=--:-=*#########################\n"
                     "%%%%%%%##%#####*=-====+***++======+==+====--==--:.::::+#########################\n"
                     "#######**##**#**+-===++==+*+-+==**+------:-::--..::::-+********************++***\n"
                     "#**#***+==++==+===-+======--::-::::--:::::--:-..:::.:--===========-=========----\n"
                     "*******++===--====--==-::----::-:-:--:::---::::::..::---=-====+=------=-==--==--\n"
                     "*****+++++++++++==----===++====+===+=========+======+=--=====--=--:-:-=------===\n"
                     "+++***+++========-=----=---=-=====------=---==-==============-::==---=------=---\n"
                     "++=+**++==----------------:::------:::::-::::-----------==-------:---------:::::\n"
                     "===+++++=--:---:--:::::-:::.:::::::::::.::::::::::-:::::::::::::::::::::::.:..::\n"
                     "=-----==-=-:----:::::::.::::..::::::..::::...::::::::::...::::::::..............\n"
                     "=++====**++==-------::---:-::..:-:.:..:::.......:::::::::::-:.:::::::.::...:::..\n"
                     "***+++++==++=-=+=-::---=+=::------=+=+=---:::.::-=+=-:::-=-:::::::====-:----:--=\n"
                     "++==-=**+*+**=++++-=*++++=--==**+***++==+=--:===----:::=++=+=-=+++++++===-=-+***\n";

        break;

    default:
        break;
    }
}