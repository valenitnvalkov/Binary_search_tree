#include <stdio.h>
#include <ctype.h>

void Morse(char c);

int main()
{
    int ch;
printf(" \t // Translator from Latin to morse code //");
 printf("\n\nEnter a text in Latin: ");
    while(1)
    {
        ch = getc(stdin);
        if( ch==EOF )
            break;
        Morse(ch);
    }
    return(0);
}

void Morse(char c)
{
    char *morse_alpha[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.",
        "--.", "....", "..", ".---", "-.-", ".-..",
        "--", "-.", "---", ".--.", "--.-", ".-.",
        "...", "-", "..-", "...-", ".--", "-..-",
        "-.--", "--.."
    };
    char *morse_digit[] = {
        "-----", ".----", "..---", "...--", "....-",
        ".....", "-....", "--...", "---..", "----."
    };
    int m;

    if( isalpha(c) )
    {
        c = toupper(c);
        m = c - 'A';
        printf(" %s ",morse_alpha[m]);
    }
    else if( isdigit(c) )
    {
        m = c - '0';
        printf(" %s ",morse_digit[m]);
    }
    else if( c==' ' || c=='\n' )
    {
        putchar('\n');
    }
    else
        return;
}
