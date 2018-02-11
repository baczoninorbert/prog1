#include <iostream>

using namespace std;

int main()
{
	cout<<"eredetileg a=4 es b=7 \n";
	int a = 4, b = 7;
	//MEGOLDAS 1

	a ^= b;
	b ^= a;
	a ^= b;
	
	cout<<"a: "<<a<<" b: "<<b<<endl;

	a ^= b;
	b ^= a;
	a ^= b;

	cout<<"a: "<<a<<" b: "<<b<<endl;
	//MEGOLDAS 2

	a=b-a;
	b=b-a;
	a=b+a;


 	cout<<"a: "<<a<<" b: "<<b<<endl;

 	a=b-a;
 	b=b-a;
 	a=b+a;

  
	cout<<"a: "<<a<<" b: "<<b<<endl;
	
	
}
