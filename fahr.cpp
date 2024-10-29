// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

static float getValue() {
    float n;
    cout << "Podaj stopie" << endl;
    cin >> n;
    return n;
}

static bool check(int type, float number) {
    if ((type == 1 and number < -469.67) or (type == 2 and number < -273.15) or (type == 3 and number < 0)) {
        return true;
    }
    return false;
}

static float FtoC(float stopnie) { //naglowek funkcji
    float wynik = (5.0 / 9.0) * (stopnie - 32.0);
    return wynik;
}

static float FtoK(float stopnie) { //naglowek funkcji
    float wynik = (5.0 / 9.0) * (stopnie + 459.67);
    return wynik;
}

static float CtoF(float stopnie) { //naglowek funkcji
    float wynik = (5.0 / 9.0) * stopnie + 32.0;
    return wynik;
}

static float CtoK(float stopnie) { //naglowek funkcji
    float wynik = stopnie + 273.15;
    return wynik;
}

static float KtoC(float stopnie) { //naglowek funkcji
    float wynik = stopnie - 273.15;
    return wynik;
}

static float KtoF(float stopnie) { //naglowek funkcji
    float wynik = (5.0 / 9.0) * stopnie - 459.67;
    return wynik;
}


static void menu() {
    cout << "Wybierz dzialanie" << endl;
    cout << "1 - Przelicz Fahr -> Celsius" << endl;
    cout << "2 - Przelicz Fahr -> Kelwin" << endl;
    cout << "3 - Przelicz Celsius -> Fahr" << endl;
    cout << "4 - Przelicz Celsius -> Kelwin" << endl;
    cout << "5 - Przelicz Kelwin -> Celsius" << endl;
    cout << "6 - Przelicz Kelwin -> Fahr" << endl;
    cout << "7 - zakoñcz dzia³anie programu" << endl;
}


int main()
{
    int choosen;
    float number;
    bool program = true;

    while (program)
    {
        menu();
        cin >> choosen;
        switch (choosen)
        {
        case 1:
            number = getValue();
            if (check(1, number)) {
                cout << "Podano za mala liczbe" << endl;
                break;
            }
            cout << number << " Fahr, to: " << FtoC(number) << " Celsius" << endl;
            break;
        case 2:
            number = getValue();
            if (check(1, number)) {
                cout << "Podano za mala liczbe" << endl;
                break;
            }
            cout << number << " Fahr, to: " << FtoK(number) << " Kelwin" << endl;
            break;
        case 3:
            number = getValue();
            if (check(2, number)) {
                cout << "Podano za mala liczbe" << endl;
                break;
            }
            cout << number << " Celsius, to: " << CtoF(number) << " Fahr" << endl;
            break;
        case 4:
            number = getValue();
            if (check(2, number)) {
                cout << "Podano za mala liczbe" << endl;
                break;
            }
            cout << number << " Celsius, to: " << CtoK(number) << " Kelwin" << endl;
            break;
        case 5:
            number = getValue();
            if (check(3, number)) {
                cout << "Podano za mala liczbe" << endl;
                break;
            }
            cout << number << " Kelwin, to: " << KtoF(number) << " Fahr" << endl;
            break;
        case 6:
            number = getValue();
            if (check(3, number)) {
                cout << "Podano za mala liczbe" << endl;
                break;
            }
            cout << number << " Kelwin, to: " << KtoC(number) << " Celsius" << endl;
            break;
        default:
            program = false;
            break;
        }
    }




    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
