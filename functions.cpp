#include <iostream>

struct temperature {
    double start_value;
    double end_value;
    char start_unit;
    char end_unit;
};

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
