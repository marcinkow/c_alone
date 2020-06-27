#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 51

int main()
{
    int e=0;
    int ilosc_aut;
    printf("Ile chcesz podac samododow: ");
    scanf("%d",&ilosc_aut);

    char slowo[MAX];
    int liczba[MAX];
    char **tab = NULL;
    int  **cena=NULL;
    char **bufor = NULL;
    int **bufor2 = NULL;
    unsigned int ilosc_slow = 0;
    int i=0;

    while(ilosc_slow<ilosc_aut)
    {
        printf("Podaj marke:");
        scanf("%s",slowo);
        printf("Podaj cene:");
        scanf("%d", &liczba);
        ilosc_slow++;
        bufor = (char**)realloc(tab,ilosc_slow * sizeof(char*));// powiekszajaca sie tablica wskaznikow
        bufor2 = (int*)realloc(cena,ilosc_slow * sizeof(int*));// powiekszajaca sie tablica wskaznikow

        if (bufor2 == NULL)
		puts("Blad alokacji pamieci");
        else
       		{
        	tab = bufor;
            cena= bufor2;
        	 tab[ilosc_slow - 1] = (char *)malloc(MAX * sizeof(char));//przydzial pamieci na pojedyncze slowo
                 strcpy(tab[ilosc_slow - 1],slowo);
            cena[ilosc_slow-1]= (int*)malloc(MAX * sizeof(int));
                strcpy(cena[ilosc_slow-1],liczba);
            }
    }
    printf("Auto1: %s\n", tab[0]);

    int min_cena=0,max_cena=0;
    printf("\nPodaj Min Cene: ");
    scanf("%d", &min_cena);
    printf("Podaj Max Cene: ");
    while(max_cena<min_cena)
    {
    scanf("%d", &max_cena);
    if(max_cena<min_cena) printf("Podaj jesze raz");
    }
    printf("Przedzial cenowy to [%d-%d]\n A te samochodody pasuja: ", min_cena,max_cena);


    for(e=0;e<ilosc_aut;e++)
    {
        if(*cena[e]>=min_cena && *cena[e]<=max_cena)
            printf("Auto %d to %s i kosztuje %d:\n",e,tab[e], *cena[e]);
        //printf("Cena %d : %d : %d:\n",cena[e],*cena[e],*(&cena[e]));
    }









    for(i = 0; i < ilosc_slow; i++){
        free(tab[i]);
        free(cena[i]);
    }
    free(tab);
    tab = NULL;
    free(bufor);
    bufor = NULL;
    return 0;
}
