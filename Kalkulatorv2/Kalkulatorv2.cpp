#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Dodawanie
double dodawanie(double a, double b) {
    return a + b;
}

// Odejmowanie
double odejmowanie(double a, double b) {
    return a - b;
}

// Mnożenie
double mnozenie(double a, double b) {
    return a * b;
}

// Dzielenie
double dzielenie(double a, double b) {
    if (b != 0) {
        return a / b;
    }
    else {
        printf("Blad: Dzielenie przez zero!\n");
        return 0.0;
    }
}

// Reszta z dzielenia przez liczbę całkowitą
int resztaZDzielenia(int a, int b) {
    if (b != 0) {
        return a % b;
    }
    else {
        printf("Blad: Dzielenie przez zero!\n");
        return 0;
    }
}

// Sinus
double sinus(double kat) {
    return sin(kat);
}

int main() {
    char operacja;
    double liczba1, liczba2, pw = 0.0; // Dodana zmienna pw (poprzedni wynik)
    int dzielna, dzielnik;
    int kontynuuj = 1;

    while (kontynuuj) {
        printf("Podaj operacje (+, -, *, /, %%, s, r-restart) lub 'q' aby wyjsc: ");
        scanf(" %c", &operacja);

        if (operacja == 'q') {
            kontynuuj = 0;
        }
        else {
            switch (operacja) {
            case '+':
                printf("Podaj liczbe: ");
                scanf("%lf", &liczba2);
                pw = dodawanie(pw, liczba2);
                printf("Wynik: %.2lf\n", pw);
                break;

            case '-':
                printf("Podaj liczbe: ");
                scanf("%lf", &liczba2);
                pw = odejmowanie(pw, liczba2);
                printf("Wynik: %.2lf\n", pw);
                break;

            case '*':
                printf("Podaj liczbe: ");
                scanf("%lf", &liczba2);
                pw = mnozenie(pw, liczba2);
                printf("Wynik: %.2lf\n", pw);
                break;

            case '/':
                printf("Podaj liczbe: ");
                scanf("%lf", &liczba2);
                if (liczba2 != 0) {
                    pw = dzielenie(pw, liczba2);
                    printf("Wynik: %.2lf\n", pw);
                }
                else {
                    printf("Blad: Dzielenie przez zero!\n");
                }
                break;

            case '%':
                printf("Podaj dzielnik (liczba calkowita): ");
                scanf("%d", &dzielnik);
                if (dzielnik != 0) {
                    pw = resztaZDzielenia((int)pw, dzielnik);
                    printf("Wynik: %.2lf\n", pw);
                }
                else {
                    printf("Blad: Dzielenie przez zero!\n");
                }
                break;

            case 's':
                printf("Podaj kat w radianach: ");
                scanf("%lf", &liczba1);
                pw = sinus(liczba1);
                printf("Wynik: %.2lf\n", pw);
                break;

            case 'r': // Nowa operacja - resetowanie poprzedniego wyniku
                pw = 0.0;
                printf("Poprzedni wynik zostal zresetowany.\n");
                break;

            default:
                printf("Nieprawidlowa operacja!\n");
                break;
            }
        }
    }
    printf("Koniec programu.\n");
    return 0;
}
