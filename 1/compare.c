#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    if(x < y) 
    {
        printf("x가 y 보다 작음\n");
    }
}