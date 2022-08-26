#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int hm;
double tim;
clock_t start, stop;


void bubble_sort(int *t,int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=n-1; j>=1; j--)
        {
            if(t[j]<t[j-1])
            {
                int buffer;
                buffer=t[j-1];
                t[j-1]=t[j];
                t[j]=buffer;
            }
        }
    }
}

void quicksort(int *tab, int l, int p)
{
    int v=tab[(l+p)/2];
    int i,j,x;
    i=l;
    j=p;
    do
    {
        while (tab[i]<v) i++;
        while (tab[j]>v) j--;
        if(i<=j)
        {
            x=tab[i];
            tab[i]=tab[j];
            tab[j]=x;
            i++;
            j--;
        }
    }
    while (i<=j);
    if(j>l) quicksort(tab, l, j);
    if(i<p) quicksort(tab, i, p);
}

int main()
{
    cout << "Sorting times comparison v.1" << endl;

    cout << "How many random numbers in array?:";

    cin>> hm;

    // dynamic allocation for array

    int *tab;
    tab=new int [hm];

    int *tab2;
    tab2=new int [hm];

    //initiate rng
    srand(time(NULL));

    // loading random numbers to array

    for(int i=0; i<hm; i++)
    {
        tab[i] = rand()%100000+1;
        //cout << tab[i]<<" ";
    }

    //rewrite tab values to tab2:

    for(int i=0; i<hm; i++)
    {
        tab2[i]=tab[i];
    }

    /*cout<<"before sorting:"<<endl;
    for(int i=0; i<hm; i++)
    {
        cout << tab[i]<<" ";
    }

    cout<<"tab2 before quicksorting:"<<endl;
    for(int i=0; i<hm; i++)
    {
        cout << tab2[i]<<" ";
    }*/

    cout<<"Bubble sorting, please wait"<<endl;
    start=clock();
    bubble_sort(tab,hm);
    stop = clock();
    tim=(double)(stop-start)/CLOCKS_PER_SEC;
    /*cout<<"after sorting:"<<endl;
    for(int i=0; i<hm; i++)
    {
        cout << tab[i]<<" ";
    }*/
    cout<<endl<<"Bubble sort time: "<< tim <<" s"<<endl;


    cout<<"Quicksorting, please wait"<<endl;
    start=clock();
    quicksort(tab2, 0, hm-1);
    stop = clock();
    tim=(double)(stop-start)/CLOCKS_PER_SEC;
    /*cout<<"tab2 after quicksorting:"<<endl;
    for(int i=0; i<hm; i++)
    {
        cout << tab2[i]<<" ";
    }*/
    cout<<endl<<"Quicksort time: "<< tim <<" s"<<endl;


    delete [] tab;
    delete [] tab2;

    return 0;

}
