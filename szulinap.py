def datetoday(day, month, year):
    d = day
    m = month
    y = year
    if m < 3:
        z = y-1
    else:
        z = y
    dayofweek = ( 23*m//9 + d + 4 + y + z//4 - z//100 + z//400 )
    if m >= 3:
        dayofweek -= 2
    dayofweek = dayofweek%7
    return dayofweek



months = [ 'january', 'february', 'march', 'april', 'may', 'june', 'july',
          'august', 'september', 'october', 'november', 'december' ]

days =[ 'Hetfo', 'Kedd', 'Szerda', 'Csutortok', 'Pentek', 'Szombat',
       'Vasarnap' ]

d = int(raw_input("Nap 1-31 >>"))
m = int(raw_input("Honap 1-12 >>"))
y = int(raw_input("Ev e.g. 1974 >>"))


dayofweek = days[datetoday(d, m, y)-1]

print dayofweek
