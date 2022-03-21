#include <stdio.h>
#include <stdlib.h>

// ###################
// #     QUICKSORT   #
// ###################

//lubie subie wyobrazac ten algorytm jako znajdowanie pivot'a
//sortowanie przed i po nim a potem ustawianie go tma gdzie pasuje
//przez co wartość pivot'a kończy zawsze tam gdzie być powinna
//i potem to jest powtarzane dla tych posortowanych pod list
//gdize ich pivot'y koncza tam gdzie byc powinny
//przypomina mi to troche bubble sort ale zamiast elementow
//bombelkujacych do gory babelkuja tam gdzie musza na pewno byc.
void quickSort(int tab[], int start_element, int last_element)
{
    //jezeli rozpatrujemy jeden element to on automatycznie jest pivot'em
    //więc na pewno jest w dobrym miejscu
    if (last_element <= start_element) return;
    //znajdowanie pivot'a
    int pivot = partitionFunction(tab, start_element, last_element);
    //sortowanie dla tablicy po lewej od pivot'a
    quickSort(tab,start_element, pivot - 1);
    //sortowanie dla tablicy po prawej od pivot'a
    quickSort(tab, pivot + 1, last_element);
}

int partitionFunction(int tab[], int start_element, int last_element)
{
    int i = start_element - 1;
    int pivot = tab[last_element];
    //printf("start: %i \n", start_element);
    //printf("last: %i \n", last_element);

    //przechodzimy przez elementy tablicy lub podtablicy
    //tak jak definiuje nam poprzedni pivot
    for(int k = start_element; k <= last_element; k++)
    {
        //i to jest taki licznik ktory trzyma indeks do ktorego
        //bedzie wpisana liczba mniejsza od pivot'a
        //przez co wszystkie liczby mniejsze od pivot'a beda po lewej
        //a potem w nastepne miejsce wcisnie sie pivot.
        //printf("i: %i \n", i);
        if(tab[k] < pivot)
        {
            i++;
			int temp = tab[i];
			tab[i] = tab[k];
			tab[k] = temp;

			//for (int i = 0; i < 9; i++)
            //{
            //    printf("%d ", tab[i]);
            //}
            //printf("\n");
        }
    }

    i++;
    //printf("returning i: %i \n", i);
    int temp = tab[i];
    tab[i] = tab[last_element];
    tab[last_element] = temp;

    //for (int i = 0; i < 9; i++)
    //{
    //    printf("%d ", tab[i]);
    //}
    //printf("\n");

    return i;
}

int main()
{
    int tab[] = {10, 15, 1, 2, 6, 12, 5, 7, 54};
    int tab_size = sizeof(tab) / sizeof(tab[0]);

    quickSort(tab,0,tab_size - 1);

    printf("Wynik sortowania tablicy: \n");
    for (int i = 0; i < tab_size; i++)
    {
        printf("%d ", tab[i]);
    }
    return 0;
}
