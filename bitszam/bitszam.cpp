#include <stdio.h>
int
main (void)
{
	int szohossz = 0;
	int bithossz = 0x01;
	do
	++szohossz;	 
	while (bithossz <<= 1);
  	printf ("A szohossz ezen a gepen: %d bites\n", szohossz);
  	return 0;
}
