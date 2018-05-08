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

