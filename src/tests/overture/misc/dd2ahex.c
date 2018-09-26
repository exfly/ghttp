#include "csapp.h"
int main(int argc, char **argv)
{
    struct in_addr int_ip;
    char * char_ip;
    inet_aton(argv[1], &int_ip);
    printf("0x%x\n", ntohl(int_ip.s_addr));
    //printf("%s\n", inet_ntoa(argv[2]));
}
