
import curses
import time
def trunc_divmod(a, b):
    q = a / b
    q = -int(-q) if q<0 else int(q)
    r = a - b * q
    return r

def pattog(scr):
    curses.cbreak()  # Ne kelljen erteket visszadni
    curses.noecho()  # Ne lehessen a terminalba irni futas kozben
    curses.curs_set(0)  # Terminal mutato ne latszodjon
    scr = curses.initscr()
    scr.clear()
    scr.refresh()
    my,mx = scr.getmaxyx()
    curses.resizeterm(my,mx)
    
    #scr.clear()
    #curses.resizeterm(my,mx)
    #scr.refresh()
    xi=0
    xj=0
    yi=0
    yj=0
    
    
    while True:
        my,mx = scr.getmaxyx()
        xi= int(trunc_divmod(int((xi-1)), (int(mx-1)*2)))
        xj= int((xj+1) % (int(mx-1)*2))

        yi= int(trunc_divmod(int((yi-1)) , (int(my-1)*2)))

        yj= int((yj+1) % (int(my-1)*2))
        


       # my, mx = scr.getmaxyx()
       # mx = int((mx-1)*2)
       # my = int((my - 1) *2)

        
        scr.clear()
        scr.border(0)

        #try:
        scr.addch(abs(int((yi+(((my-1)*2)-yj))/2)),abs(int((xi+(((mx-1)*2)-xj))/2)), '0')
        #except (curses.error):
        #    pass
        # frisites
        scr.refresh()
        
      
       

        # szunet
      
        time.sleep(0.05)



def main():
    curses.wrapper(pattog)
if __name__ == "__main__":
    main()
