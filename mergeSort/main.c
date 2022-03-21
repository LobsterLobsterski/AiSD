#include <stdio.h>
#include <stdlib.h>

//############################
//#     MERGE SORT !!!!!!!   #
//############################

void merge(int tab[], int l_side, int middle, int r_side)
{
    //len1 i len2 sa zmiennymi ktore zawieraja dlugosci
    //tablic tymczasowych.

    int overwriteIndex, i, j;
    int len1 = middle - l_side + 1;
    int len2 = r_side - middle;
    int L_temp[len1], R_temp[len2];


    //te dwie petle wypelniaja te tablice tymczasowe
    //rzeczywistymi wartosciami z tablicy ale tylko
    //z lewej albo z prawej
    for (i = 0; i < len1; i++)
    {
        L_temp[i] = tab[l_side + i];
    }

    for (j = 0; j < len2; j++)
    {
        R_temp[j] = tab[middle + 1 + j];
    }


    i = 0;
    j = 0;
    overwriteIndex = l_side;

    //sa 3 petle while gdyz tylko jedna czesc
    //moze zostac posortowana w jednej petli
    //w najepszym przypadku uda nam sie posortowac
    //cala lewa i (size-1) prawej ale obydwu naraz nie
    while (i < len1 && j < len2)
    {
        if (L_temp[i] <= R_temp[j])
        {
            tab[overwriteIndex] = L_temp[i];
            i++;
        }
        else
        {
            tab[overwriteIndex] = R_temp[j];
            j++;
        }
        overwriteIndex++;
    }

    //wiec te dwie sa tutaj aby sie upewnic ze wszystkie elementy sa na miejscu
    //bez tych tablica 67 45 zamieniła się w 45 45 a nie 45 67
    while (i < len1)
    {
        tab[overwriteIndex] = L_temp[i];
        i++;
        overwriteIndex++;
    }

    while (j < len2)
    {
        tab[overwriteIndex] = R_temp[j];
        j++;
        overwriteIndex++;
    }
}

void mergeSort(int tab[], int l_side, int r_side)
{   //ta metoda nie tyle co sortuje co znajduje dzieli tablice
    //na pojedyncze czesci ktorych indeksy sa potem wysylane do
    //metody merge gdzie tablica jest sortowana.
    //Najpierw sprawdzamy czy nasza tablica ktora bierzemy
    //pod uwage jest dluzsza od 1, jezeli jest to
    //znajdujemy srodek i wysylamy ta podtablice spowrotem
    //do mergeSort aby dzielił az bedzie dlugosc 1.
    //Gdy dotrze juz do 1 to wysle te wszytskie indeksy do
    //merge, potem wroci do najblizszej tablicy nadrzednej
    //i sprawdzi jej prawa strone tak samo.
    //Jak juz wysle wszystkie jedynkowe tablice z lewej
    //strony do posortowania to zacznie wysylac tablice o dlugosci 2
    //a potem 4 az wroci do samego poczatku, posortuje prawa strone
    //a tak samo powysyla do sortowania az wysle juz cala do sortowania
    //(tak troche trudno mi to wytlumaczyc ale rozrysowalem sobie to
    // wiec rozumiem jak to dziala, nawet jezeli nie brzmi)
    if (l_side < r_side) {

        int middle = l_side + (r_side - l_side) / 2;

        mergeSort(tab, l_side, middle);
        mergeSort(tab, middle + 1, r_side);
        merge(tab, l_side, middle, r_side);
    }
}


int main()
{
    int tab[] = { 7, 6, 5, 4, 3, 2, 1, 0 };
    int tab_size = sizeof(tab) / sizeof(tab[0]);

    mergeSort(tab, 0, tab_size - 1);

    printf("Wynik sortowania tablicy: \n");
    for (int i = 0; i < tab_size; i++)
    {
        printf("%d ", tab[i]);
    }

    return 0;
}
