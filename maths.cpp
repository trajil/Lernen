#include <iostream>
#include <iomanip>
using namespace std;


int zeilen_menge;
int spalten_breite;



int main()
{
    int abort = 0;

    string welcome = "Tabellenerstellung: Bitte Zeilen- und Spaltenmenge eingeben. (Type " + to_string(abort) + " to exit)";
    do
    {
    
        cout << welcome << endl;
        cout << "Spalten: "; cin >> spalten_breite; cout << "Zeilen: "; cin >> zeilen_menge;

        for (int i = 0; i < zeilen_menge; i++)
        
        {
            for (int j = 0; j < spalten_breite; j++)
            {
                cout << "Y";
            }
            
        cout << "X" << endl;
        
        }
    } while (spalten_breite != abort);

    return 0; 
}

//das ist ein Test nr2
