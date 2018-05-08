#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
   int szavak = 0;
   int sorok = 0;
   int betuk = 0;
   int szamok = 0;
   int specialis = 0;
   ifstream adatok ("szamlalo.txt");
   char ch;
   int osszesen = 0;
   while(adatok.get(ch))
   {
     if (ch == ' ' || ch == '\n' || ch == '\t')
       szavak++;
     if (ch == '\n')
        sorok++;
     if (isalpha(ch))
       betuk++;
     if (isdigit(ch))
       szamok++;
     if (ispunct(ch))
       specialis++;
   }
   osszesen = betuk + szamok + specialis;
   
   cout << "Ebben a fileban ezzek talalhatoak:\n";
   cout << szavak << " szo\n";
   cout << sorok << " sor\n";
   cout << betuk << " betu\n";
   cout << szamok << " szam\n";
   cout << specialis << " specialis karakter\n";
   cout << "\n osszesen " << osszesen << " karater van\n";
   return 0;
}
       
