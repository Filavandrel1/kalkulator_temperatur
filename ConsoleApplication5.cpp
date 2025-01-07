#include <iostream>
#include "functions.cpp"

using namespace std;

static float getValue() {
    float degrees;
    cout << "Podaj stopie" << endl;
    cin >> degrees;
    return degrees;
}

static bool check(int type, float number) {
    if ((type == 1 and number < -469.67) or (type == 2 and number < -273.15) or (type == 3 and number < 0)) {
        return true;
    }
    return false;
}




static void menu() {
    cout << "Wybierz dzialanie" << endl;
    cout << "1 - Przelicz Fahr -> Celsius" << endl;
    cout << "2 - Przelicz Fahr -> Kelwin" << endl;
    cout << "3 - Przelicz Celsius -> Fahr" << endl;
    cout << "4 - Przelicz Celsius -> Kelwin" << endl;
    cout << "5 - Przelicz Kelwin -> Celsius" << endl;
    cout << "6 - Przelicz Kelwin -> Fahr" << endl;
    cout << "7 - wyswietl historie" << endl;
    cout << "8 - usun z historii" << endl;
    cout << "-1 - zakoncz dzialanie programu" << endl;
}

static void menu_units() {
    cout << "Wybierz dzialanie" << endl;
    cout << "1 - Tylko C -> inne" << endl;
    cout << "2 - Tylko F -> inne" << endl;
    cout << "3 - Tylko K -> inne" << endl;
    cout << "4 - wszystko" << endl;
}


int main()
{

    temperature history[100];
    temperature garbage;
    int dataCounter = 0;
    int choosen;
    float number;
    bool is_program_active = true;

    while (is_program_active)
    {
        menu();
        cin >> choosen;
        switch (choosen)
        {

        case 1:
            system("cls");
            number = getValue();
            if (check(1, number)) {
                cout << "Podano za mala liczbe" << endl;
                break;
            }
            if (dataCounter < 100) {
                cout << number << " Fahr, to: " << FtoC(number, &history[dataCounter++]) << " Celsius" << endl;
            }
            else {
                cout << number << " Fahr, to: " << FtoC(number, &garbage) << " Celsius" << endl;
                cout << "nowe przeliczenie nie zostalo dodane do historii" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            number = getValue();
            if (check(1, number)) {
                cout << "Podano za mala liczbe" << endl;
                break;
            }
            if (dataCounter < 100) {
                cout << number << " Fahr, to: " << FtoK(number, &history[dataCounter++]) << " Kelwin" << endl;
            }
            else {
                cout << number << " Fahr, to: " << FtoK(number, &garbage) << " Kelwin" << endl;
                cout << "nowe przeliczenie nie zostalo dodane do historii" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            number = getValue();
            if (check(2, number)) {
                cout << "Podano za mala liczbe" << endl;
                break;
            }
            if (dataCounter < 100) {
                cout << number << " Celsius, to: " << CtoF(number, &history[dataCounter++]) << " Fahr" << endl;
            }
            else {
                cout << number << " Celsius, to: " << CtoF(number, &garbage) << " Fahr" << endl;
                cout << "nowe przeliczenie nie zostalo dodane do historii" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            number = getValue();
            if (check(2, number)) {
                cout << "Podano za mala liczbe" << endl;
                break;
            }
            if (dataCounter < 100) {
                cout << number << " Celsius, to: " << CtoK(number, &history[dataCounter++]) << " Kelwin" << endl;
            }
            else {
                cout << number << " Celsius, to: " << CtoK(number, &garbage) << " Kelwin" << endl;
                cout << "nowe przeliczenie nie zostalo dodane do historii" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            number = getValue();
            if (check(3, number)) {
                cout << "Podano za mala liczbe" << endl;
                break;
            }
            if (dataCounter < 100) {
                cout << number << " Kelwin, to: " << KtoF(number, &history[dataCounter++]) << " Fahr" << endl;
            }
            else {
                cout << number << " Kelwin, to: " << KtoF(number, &garbage) << " Fahr" << endl;
                cout << "nowe przeliczenie nie zostalo dodane do historii" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            number = getValue();
            if (check(3, number)) {
                cout << "Podano za mala liczbe" << endl;
                break;
            }
            if (dataCounter < 100) {
                cout << number << " Kelwin, to: " << KtoC(number, &history[dataCounter++]) << " Celsius" << endl;
            }
            else {
                cout << number << " Kelwin, to: " << KtoC(number, &garbage) << " Celsius" << endl;
            cout << "nowe przeliczenie nie zostalo dodane do historii" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            menu_units();
            int option;
            cin >> option;

            switch (option) {
            case 1:
                for (int i = 0; i < dataCounter; i++) {
                    if (history[i].start_unit == 'C') {
                        cout << "<" << i + 1 << ">  " << history[i].start_value << history[i].start_unit << " = " << history[i].end_value << history[i].end_unit << endl;
                    }
                }
                break;
            case 2:
                for (int i = 0; i < dataCounter; i++) {
                    if (history[i].start_unit == 'F') {
                        cout << "<" << i + 1 << ">  " << history[i].start_value << history[i].start_unit << " = " << history[i].end_value << history[i].end_unit << endl;
                    }
                }
                break;
            case 3:
                for (int i = 0; i < dataCounter; i++) {
                    if (history[i].start_unit == 'K') {
                        cout << "<" << i + 1 << ">  " << history[i].start_value << history[i].start_unit << " = " << history[i].end_value << history[i].end_unit << endl;
                    }
                }
                break;

            default:
                for (int i = 0; i < dataCounter; i++) {
                    cout << "<" << i + 1 << ">  " << history[i].start_value << history[i].start_unit << " = " << history[i].end_value << history[i].end_unit << endl;
                }
                break;
            }

            system("pause");
            system("cls");
            break;
        default:
            is_program_active = false;
            break;
        }
    }




    return 0;
}
