#include "show-msg.h"

/***
 * @brief ShowMessage
 * @param message
 * @param first_color
 * @param second_color
 **/
void
ShowMessage(const char * message, int first_color, int second_color)
{
     //char colors[][20] = {"\033[01;30m\033[22;47m", "\033[01;31m\033[22;47m", "\033[01;32m\033[22;47m", "\033[01;33m\033[22;47m", "\033[01;34m\033[22;47m", "\033[01;35m\033[22;47m", "\033[01;36m\033[22;47m", "\033[01;37m\033[43m", "\033[0m"};

    char colors[][20] = {"\033[02;30m", "\033[02;31m", "\033[02;32m", "\033[02;33m", "\033[02;34m", "\033[02;35m", "\033[02;36m", "\033[02;37m", "\033[0m"};
    long lenght_msg = strlen(message) + 6;
    int i;

    //first line
    for (i = 0; i < lenght_msg; i++) printf("%s%s",colors[first_color], "*");

    //second line
    printf("\n*");for (i = 0; i < lenght_msg-2; i++) printf(" ");
    printf("*");
    printf("\n");
    //
    printf("   %s%s%s",colors[second_color], message, colors[first_color]);

    printf("\n*");for (i = 0; i < lenght_msg-2; i++) printf(" ");
    printf("*");
    printf("\n");

    for (i = 0; i < lenght_msg; i++) printf("*");

    printf("%s\n\n",colors[8]);
}
