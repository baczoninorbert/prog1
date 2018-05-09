// lo.c
//
// Deriváló progi
// Programozó Páternoszter
//
// Copyright (C) 2011, Bátfai Norbert, nbatfai@inf.unideb.hu, nbatfai@gmail.com
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Ez a program szabad szoftver; terjeszthetõ illetve módosítható a
// Free Software Foundation által kiadott GNU General Public License
// dokumentumában leírtak; akár a licenc 3-as, akár (tetszõleges) késõbbi
// változata szerint.
//
// Ez a program abban a reményben kerül közreadásra, hogy hasznos lesz,
// de minden egyéb GARANCIA NÉLKÜL, az ELADHATÓSÁGRA vagy VALAMELY CÉLRA
// VALÓ ALKALMAZHATÓSÁGRA való származtatott garanciát is beleértve.
// További részleteket a GNU General Public License tartalmaz.
//
// A felhasználónak a programmal együtt meg kell kapnia a GNU General
// Public License egy példányát; ha mégsem kapta meg, akkor
// tekintse meg a <http://www.gnu.org/licenses/> oldalon.
//
// Tesztesetek:
/*
[nbatfai@desteny Batfai-Barki]$ gcc lo.c -o lo
[nbatfai@desteny Batfai-Barki]$ ./lo xx*
x1*1x*+
OK, lásd lerajzolva itt: http://progpater.blog.hu/2011/03/18/derivalni_a_lo_is_tud
[nbatfai@desteny Batfai-Barki]$ ./lo xxx**
xx*1*x1*1x*+x*+
OK, lásd lerajzolva itt: http://progpater.blog.hu/2011/03/18/derivalni_a_lo_is_tud
[nbatfai@desteny Batfai-Barki]$ ./lo xxs+2p
2xxs+21-p*xc1*1+*
OK, lásd lerajzolva itt: http://progpater.blog.hu/2011/03/18/derivalni_a_lo_is_tud
[nbatfai@desteny Batfai-Barki]$ ./lo 3x2+*
x2+0*01+3*+
OK
[nbatfai@desteny Batfai-Barki]$ ./lo xx*xx**
xx*x1*1x*+*x1*1x*+xx**+
OK, mert [x^4]' = 4x^3
[nbatfai@desteny Batfai-Barki]$ ./lo x2px2p*
x2p2x21-p*1**2x21-p*1*x2p*+
OK, mert [x^4]' = 4x^3
*/
//
// Version history:
//
// 0.0.1, 2011.03.18., (BN), iniciális hack: http://progpater.blog.hu/2011/03/18/derivalni_a_lo_is_tud
// 0.0.2, 2014.04.05., (BN), az ismert BUG-ok javítása
//


#include <stdio.h>

#define FL_BUFFER_MERET 1024

char fl_buffer[FL_BUFFER_MERET];

int sp = -1;


void
push(char c)
{
    fl_buffer[++sp] = c;
}


char
pop()
{
    return fl_buffer[sp--];
}

void
kiir(char op)
{
    if (op >= '0' && op <= '9') {
        printf("%c", op);
        return;
    } else if (op == 'x') {
        printf("%c", 'x');
        return;
    } else if (op == '+' || op == '*' || op == 'p') {
        char op1 = pop();
        char op2 = pop();
        kiir(op2);
        kiir(op1);
        printf("%c", op);
        return;
    } else if (op == 's' || op == 'e') {
        char op1 = pop();
        kiir(op1);
        printf("%c", op);
        return;
    }
}


void
d(char op)
{
    if (op >= '0' && op <= '9') {
       
        printf("%c", '0');
        return;
    } else if (op == 'x') {
       
        printf("%c", '1');
        return;
    } else if (op == '+') {
     
        char op1 = pop();
        d(op1);
        char op2 = pop();
        d(op2);
        printf("%c", '+');
        return;
    } else if (op == '*') {
       
        char op1 = pop();
        int mentsp = sp;
        kiir(op1);
        char op2 = pop();
        int mentsp2 = sp;
        d(op2);
        printf("%c", '*');
        sp = mentsp;
        d(op1);
        sp = mentsp2;
        kiir(op2);
        printf("%c", '*');
        printf("%c", '+');
        return;
    } else if (op == 's' || op == 'e') {
        
        char op1 = pop();
        int mentsp = sp;
        kiir(op1);
        switch (op) {
        case 's':
            printf("%c", 'c');
            break;
        case 'e':
            printf("%c", 'e');
            break;
        }
        sp = mentsp;
        d(op1);
        printf("%c", '*');
        return;
    } else if (op == 'p') {       
        char op1 = pop();	
        int mentsp = sp;
        kiir(op1);
        char op2 = pop();
        int mentsp2 = sp;
        kiir(op2);
        sp = mentsp;
        kiir(op1);
        printf("%c", '1');
        printf("%c", '-');
        printf("%c", 'p');
        printf("%c", '*');
        sp = mentsp2;
        d(op2);
        printf("%c", '*');
        return;
    }
}

void
derival(char *mit)
{
    int c;
    sp = -1;

    while (c = *mit++)
        switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'x':
        case '+':
        case '*':
        case 's':
        case 'e':
        case 'p':
            push(c);
            break;
        default:
            printf("%c-t nem ismeri ez az implementacio...", c);
            break;
        }

    d(pop());
    printf("\n");
}

int
main(int argc, char *argv[])
{
    while (--argc)
        derival(*++argv);

    return 0;
}

