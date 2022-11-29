#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char c = get_char("Do you agree? ");

  //  작은 따옴표로 표시해야지 하나의 문자를 의미하는 타입인 char 타입을 나타낼 수 있다.
  // JavaScript와 비슷하게 || 기호로 조건문의 or 의미를 전달한다. 
    if(c == 'y' || c == 'Y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not Agreed.\n");
    }
}