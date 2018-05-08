// compile gcc labda.c -o labda -lncurses
// futas ./labda

#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

int main()
{
	int xi=0, xj=0, yi=0, yj=0;
	int mx=80*2, my=24*2;

	WINDOW *win;
	win = initscr();

	nodelay(win, true);
	noecho ();
	cbreak ();

	for (;;)
	{
		xi= (xi-1) % mx;
		//std::cout << "xi = " << xi << std::endl;
		xj= (xj+1) % mx;
		//std::cout << "xj = " << xi << std::endl;
		 yi= (yi-1) % my;
		//std::cout << "yi = " << xi << std::endl;

		yj= (yj+1) % my;
		//std::cout << "yj = " << xi << std::endl;


		clear ();

		mvprintw (abs((yi+(my-yj))/2),abs((xi+(mx-xj))/2),"O");
		
		refresh();
		usleep (50000);
		
	}
	return 0;
}
