#include <iostream>
#include <iomanip>
#include <string>
using namespace std;



int main() {

    do
    {
    string text_welcome_1 = "Willkommen bei Ihrem örtlichen Finanzamt!";
    string text_welcome_2 = "Hier können Sie die MwST ausrechnen lassen,";
    string text_welcome_3 = "Um welchen Nettobetrag handelt es sich? ";
    int length = text_welcome_1.length(); // oder text.size();
    double eingabe_netto;

    
    cout << "#" << setfill('#') << setw(length-2) << "#" << endl;
    cout << text_welcome_1 << endl;
    cout << text_welcome_2 << endl;
    cout << text_welcome_3 << endl;
    cout << "+" << setfill('+') << setw(length-2) << "+" << endl;
    cout << "Eingabe: ";
    cin >> eingabe_netto;

    if 



    } while(action !=5);
    
}
