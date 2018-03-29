#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("graf.in");
struct Tranzitie{
    int q1,q2;
    int nr;
};
int main()
{
    int i;

    int nrStari; //nr stari
    f>>nrStari;
    int Q[nrStari+1];
    for(i=1;i<=nrStari;i++)
        f>>Q[i];

    int nrF; //nr stari finale
    f>>nrF;
    int F[nrF+1];
    for(i=1;i<=nrF;i++)
        f>>F[i];

    int nrA; //nr litere alfabet
    f>>nrA;
    int A[nrA+1];
    for(i=1;i<=nrA;i++)
        f>>A[i];

    int nrT; //nr tranzitii
    f>>nrT;
    vector<Tranzitie>T(nrT+1); //vector< (stare1,stare2), "litera" de pe tranzitie >T;
    //int T[nrT+1];
    for(i=1;i<=nrT;i++)
    {
        f>>T[i].q1;
        f>>T[i].q2;
        f>>T[i].nr;
    }

    //Citire cuvant si verificare
    int acceptat = -1;
    int x, stareCurenta = 1;
    while(f>>x && acceptat != 0){ //citesc pe rand cate o "litera"

        int ok = 0;
        for(i=1;i<=nrA;i++) //verific daca x face parte din alfabetul meu
            if(x == A[i])
                ok = 1;

        if(ok == 0) //"litera" nu face parte din alfabet
        {
            acceptat = 0; //nu e acceptat
        }

        //Daca am ajuns aici, "litera" face parte din alfabet
        ok = 0;
        for(i=1;i<=nrT && ok!=1;i++)
            if(T[i].q1 == stareCurenta && T[i].nr == x)//exista o tranzitie
            {
                ok = 1;
                stareCurenta = T[i].q2;
            }

        if(ok == 0) //nu s-a gasit o tranzitie
        {
            acceptat = 0; //nu e acceptat
        }
    }

    if(acceptat == 0){
        cout<<"Cuvant neacceptat"<<endl;
    }
    else{

        //Daca am ajuns aici, s-a citit tot cuvantul
        //Acum verificam daca starea in care am ajuns este stare finala

        int ok = 0;
        for(i=1;i<=nrF && ok!=1;i++)
            if(F[i] == stareCurenta)
            {
                cout<<"Cuvant acceptat"<<endl;
                ok = 1;
            }

        if(ok != 1)
            cout<<"Cuvant neacceptat"<<endl;

    }

    return 0;
}
