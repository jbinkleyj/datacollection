#include <iostream>

using namespace std;

int testy;
int licznik;
int mianownik;
char znak;
int wspolny;
int wynik;
int test;

int nwd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        a=a%b;
        return nwd(b,a);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> testy;

    for(int i=1;i<=testy;i++)
    {
        cin >> licznik >> znak >> mianownik;
        wynik=1;

        wspolny=nwd(licznik,mianownik);

        licznik=licznik/wspolny;
        mianownik=mianownik/wspolny;

        test=mianownik;

        while(test%2==0)
        {
            test=test/2;
        }

        mianownik=mianownik/2;

        if(test!=1)
        {
            cout << "Case #" << i << ": impossible" << endl;
        }
        else
        {
            while(mianownik>licznik)
            {
                mianownik=mianownik/2;
                wynik++;
            }

            cout << "Case #" << i << ": " << wynik << endl;
        }
    }

    return 0;
}
