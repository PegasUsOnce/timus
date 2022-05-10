#include <stdio.h>
#include <conio.h>
#include <iostream>

int main() {
    char str[81];
    unsigned int currentIndex = 0;
    char ch;

    for (int i = 0; i < 80; i++)
        str[i] = ' ';

    str[80] = '\0';

    while (std::cin.get(ch) &&  ch != '\n') {
        switch (ch) {
            case '\n':
                break;
            case '>':
                currentIndex++;
                if (currentIndex == 80)
                    currentIndex = 0;
                break;
            case '<':
                if (currentIndex > 0)
                    currentIndex--;
                break;
            default:
                if (currentIndex == 80)
                    currentIndex = 0;
                str[currentIndex] = ch;
                currentIndex++;
                break;
        }
    }

    std::cout << str << std::endl;

    return 0;
}

//>><<<Look for clothes at the <<<<<<<<<<<<<<<second floor. <<<<<<<Fresh pizza and <<<<<<<<<<<<<<<<hamburger at a shop right to <<<<<<<<<<<<<the entrance. Call <<<<<<<<<< 123<-456<-8790 <<<<<<<<<<<<<<<<to order <<<<<<<<<<<<<<<<<computers< and office<<<<<<< chairs.
