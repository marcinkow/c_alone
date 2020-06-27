//minimum, maksimum, srednia bez wskaznikow
#include <stdio.h>
#include <conio.h>
#define ROZMIAR 100

int main()
{
    int i, liczba_pacjentow;
    float  min, max, srednia, suma = 0;
    float tab[ROZMIAR];
    printf("Podaj ilosc pacjentow: ");
    scanf("%d", &liczba_pacjentow);
    for(i = 0; i < liczba_pacjentow; i++)
    {
        printf("Podaj wage pacjenta nr %d: ", i+1);
        scanf("%f", &tab[i]);
        suma += tab[i];
    }
    srednia = suma / liczba_pacjentow;
    max = min = tab[0];
    for(i = 0; i < liczba_pacjentow; i++)
    {
        if (tab[i] > max) max = tab[i];
        if (tab[i] < min) min = tab[i];
    }
    printf("\nmaksimum = %.2f, minimum = %.2f,  srednia = %.2f", max, min, srednia);
    getch();
    return 0;
}
