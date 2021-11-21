/*
    CS252
    Operating systems
    Assignment
    9.28

    Yuvasankar B
    191ME197
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
unsigned long page;
unsigned long offset;
unsigned long address;


address= atoll(argv[1]);
/* Page Number =  quotient of  address / 4KB 
offset = remainder*/

page = address >> 12;
offset = address & 0xfff;

printf("The address %lu contains: \n", address);
printf("page number = %lu\n",page);
printf("offset = %lu\n", offset);


return 0;
}
