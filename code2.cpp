#include <iostream>
#include "functions.cpp"

using namespace std;

static void menu() {
    cout << "Wybierz dzialanie" << endl;
    cout << "1 - Przelicz Fahr -> Celsius" << endl;
    cout << "2 - Przelicz Fahr -> Kelwin" << endl;
    cout << "3 - Przelicz Celsius -> Fahr" << endl;
    cout << "4 - Przelicz Celsius -> Kelwin" << endl;
    cout << "5 - Przelicz Kelwin -> Fahr" << endl;
    cout << "6 - Przelicz Kelwin -> Celsius" << endl;
    cout << "7 - wyswietl historie" << endl;
    cout << "8 - usun z historii" << endl;
    cout << "9 - edytuj z historii" << endl;
    cout << "10 - wygeneruj losowe temeratury" << endl;
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
    bool program = true;

    while (program)
    {
        menu();
        cin >> choosen;
        switch (choosen)
        {

        case 1:
            system("cls");
            number = getValue();
            if (check('F', number)) {
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
            if (check('F', number)) {
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
            if (check('C', number)) {
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
            if (check('C', number)) {
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
            if (check('K', number)) {
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
            if (check('K', number)) {
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
        case 8:
            system("cls");
            for (int i = 0; i < dataCounter; i++) {
                    cout << "<" << i + 1 << ">  " << history[i].start_value << history[i].start_unit << " = " << history[i].end_value << history[i].end_unit << endl;
                }
            int index;
            cout << "Podaj index do usuniecia" << endl;
            cin >> index;
            if (index > 0 && index <= dataCounter) {
                for (int i = index - 1; i < dataCounter - 1; i++) {
                    history[i] = history[i + 1];
                }
                dataCounter--;
            }
            else {
                cout << "Podano zly index" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 9:
            system("cls");
            for (int i = 0; i < dataCounter; i++) {
                    cout << "<" << i + 1 << ">  " << history[i].start_value << history[i].start_unit << " = " << history[i].end_value << history[i].end_unit << endl;
                }
            int index2;
            index2 = -1;
            while (index2 < 0 || index2 > dataCounter)
            {
                cout << "Podaj index do edycji" << endl;
                cin >> index2;
                if(index2 < 0 || index2 > dataCounter){
                    cout << "Podano zly index" << endl;
                }
            }
            Case9(&history[index2 - 1]);
            break;
        case 10:
            system("cls");
            int amount;
            cout << "Podaj ilosc losowych temperatur" << endl;
            cin >> amount;
            if(amount + dataCounter > 100){
                cout << "Za duzo temperatur" << endl;
                cout << "Czy chcesz dodac " << 100 - dataCounter << " temperatur?" << endl;
                cout << "1 - tak" << endl;
                cout << "2 - nie" << endl;
                int choice;
                cin >> choice;
                if(choice == 1){
                    amount = 100 - dataCounter;
                }
                else{
                    break;
                }
            }
            for(int i = 1; i <= amount; i++){
                char units[3] = {'F', 'C', 'K'};
                int start = rand() % 3;
                char start_unit = units[start];
                for (int j = start; j < 2; j++) {
                    units[j] = units[j + 1];
                }
                char end_unit = units[rand() % 2];
                float value = rand() % 1000;
                if(start_unit == 'F'){
                    value -= 469;
                }
                else if(start_unit == 'C'){
                    value -= 273;
                }
                history[dataCounter++] = {value, EditValue(value, start_unit, end_unit), start_unit, end_unit};
            }
            break;
        default:
            program = false;
            break;
        }
    }




    return 0;
}