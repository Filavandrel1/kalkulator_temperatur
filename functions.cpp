#include <iostream>

using namespace std;

struct temperature {
    double start_value;
    double end_value;
    char start_unit;
    char end_unit;
};

static float getValue() {
    float n;
    while (true) {
        cout << "Podaj stopie" << endl;
        cin >> n;
        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Niewlasciwa liczba." << endl;
        } else {
            break; // valid input
        }
    }
    return n;
}

static bool check(char unit, float number) {
    if ((unit == 'F' && number < -469.67) || (unit == 'C' && number < -273.15) || (unit == 'K' && number < 0)) {
        return true;
    }
    return false;
}

static float FtoC(float stopnie, temperature* historia) { //naglowek funkcji
    float wynik = (5.0 / 9.0) * (stopnie - 32.0);
    *historia = { stopnie, wynik, 'F', 'C' };
    return wynik;
}

static float FtoK(float stopnie, temperature* historia) { //naglowek funkcji
    float wynik = (5.0 / 9.0) * (stopnie + 459.67);
    *historia = { stopnie, wynik, 'F', 'K' };
    return wynik;
}

static float CtoF(float stopnie, temperature* historia) { //naglowek funkcji
    float wynik = (5.0 / 9.0) * stopnie + 32.0;
    *historia = { stopnie, wynik, 'C', 'F' };
    return wynik;
}

static float CtoK(float stopnie, temperature* historia) { //naglowek funkcji
    float wynik = stopnie + 273.15;
    *historia = { stopnie, wynik, 'C', 'K' };
    return wynik;
}

static float KtoC(float stopnie, temperature* historia) { //naglowek funkcji
    float wynik = stopnie - 273.15;
    *historia = { stopnie, wynik, 'K', 'C' };
    return wynik;
}

static float KtoF(float stopnie, temperature* historia) { //naglowek funkcji
    float wynik = (5.0 / 9.0) * stopnie - 459.67;
    *historia = { stopnie, wynik, 'K', 'F' };
    return wynik;
}   

static float EditValue(float stopnie, char start_unit, char end_unit){
    temperature garbage;
    switch (start_unit)
    {
    case 'F':
        switch (end_unit)
        {
        case 'C':
            return FtoC(stopnie, &garbage);
            break;
        case 'K':
            return FtoK(stopnie, &garbage);
            break;
        default:
            break;
        }
        break;
    case 'C':
        switch (end_unit)
        {
        case 'F':
            return CtoF(stopnie, &garbage);
            break;
        case 'K':
            return CtoK(stopnie, &garbage);
            break;
        default:
            break;
        }
        break;
    case 'K':
        switch (end_unit)
        {
        case 'C':
            return KtoC(stopnie, &garbage);
            break;
        case 'F':
            return KtoF(stopnie, &garbage);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return 0;
}


static void Case9(temperature *history){
    float stopnie;
    char start_unit, end_unit;
    start_unit = 'A';
    end_unit = 'A';
    stopnie = getValue();
    while(start_unit != 'F' && start_unit != 'C' && start_unit != 'K'){
        start_unit = 'A';
        cout << "Podaj jednostke poczatkowa: " << endl << "F - Fahrenheit" << endl << "C - Celsius" << endl << "K - Kelwin" << endl;
        cin >> start_unit;
        if(start_unit != 'F' && start_unit != 'C' && start_unit != 'K'){
            cout << "Podano zla jednostke" << endl;
        }
    }
    check(start_unit, stopnie);
    
    while(end_unit != 'F' && end_unit != 'C' && end_unit != 'K'){
        end_unit = 'A';
        cout << "Podaj jednostke koncowa: " << endl << "F - Fahrenheit" << endl << "C - Celsius" << endl << "K - Kelwin" << endl;
        cin >> end_unit;
        if(end_unit != 'F' && end_unit != 'C' && end_unit != 'K'){
            cout << "Podano zla jednostke" << endl;
        }
        if(start_unit == end_unit){
            cout << "Jednostki nie moga byc takie same" << endl;
            Case9(history);
            return;
        }
    }
    *history = { stopnie, EditValue(stopnie, start_unit, end_unit), start_unit, end_unit };
}