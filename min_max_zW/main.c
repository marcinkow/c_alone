// minimum, maksimum, srednia na wskaznikach
#include<stdio.h>
#include<stdlib.h> // malloc
#include<conio.h>

int main()
{
    int i, liczba_pacjentow;
    int tyle;
    float min, max, srednia, suma = 0;
    printf("Podaj ilosc pacjentow: ");
    scanf("%d", &liczba_pacjentow);
    float *tab = (float*) malloc(liczba_pacjentow * sizeof(float));
    for(i = 0; i < liczba_pacjentow; i++)
    {
        printf("Podaj wage pacjenta nr %d: ", i+1);
        scanf("%f", tab + i);// tab + i to &tab[i]
        suma += *(tab + i);
    }
    srednia = suma / liczba_pacjentow;
    max = min = *tab;
    for(i = 1; i < liczba_pacjentow; i++)
    {
        if (*(tab + i) > max) max = *(tab + i);
        if (*(tab + i) < min) min = *(tab + i);
        if(*(tab +1) > srednia ) tyle++;
    }
    free(tab); // zwalnianie pamieci
    printf("\nmaksimum = %.2f, minimum = %.2f, srednia = %.2f, tyle=%d", max, min, srednia, tyle);
    getch();
    return 0;
}
