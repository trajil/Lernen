#include <iostream>
#include <string>
#include <random>
#include <iomanip>

using namespace std;

int main() {
    
    // random number generator geheim
    random_device rd_1;
    mt19937 gen_1(rd_1());
    int min_1 = 1;
    int max_1 = 100;
    uniform_int_distribution<int> dist_1(min_1, max_1);
    int random_number_1 = dist_1(gen_1);

    // random number generator hinweis_min
    random_device rd_2;
    mt19937 gen_2(rd_2());
    int min_2 = max(1, random_number_1 - 10);
    int max_2 = random_number_1;
    uniform_int_distribution<int> dist_2(min_2, max_2);
    int random_number_2 = dist_2(gen_2);
    
    // random number generator hinweis_max
    random_device rd_3;
    mt19937 gen_3(rd_3());
    int min_3 = random_number_1;
    int max_3 = min(100, random_number_1 + 10);
    uniform_int_distribution<int> dist_3(min_3, max_3);
    int random_number_3 = dist_3(gen_3);

    int geheim = random_number_1;
    int rate;
    int hinweis = 102;
    int hinweis_out_min = random_number_2;
    int hinweis_out_max = random_number_3;
    int lösung = 101;
    
    string zu_klein = "Deine Zahl ist zu klein!";
    string zu_gross = "Deine Zahl ist zu gross!";
    string bingo = "Wir haben ein Bingo!";

    do {
        cout << "Rate die Zahl zwischen 1 und 100! (101 fuer Loesung, 102 fuer Tipp) ";
        cin >> rate;
        
        if (rate < geheim) {
            cout << zu_klein << endl;
        }
        else if (rate == lösung) {  
            cout << geheim << endl;
        }
        else if (rate == hinweis) {
            cout << "Das Ergebnis ist zwischen " << hinweis_out_min << " und " << hinweis_out_max << endl;
        }
        else if (rate > geheim) {
            cout << zu_gross << endl;
        }
        else if (rate == geheim) {
            cout << bingo << endl;
        }
    }
    while (rate != geheim);

    return 0;
}
