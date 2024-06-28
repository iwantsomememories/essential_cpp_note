#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char name[1000] = "";
    printf("Please enter your name: ");
    scanf("%s", name);
    int n = strlen(name);
    if(n > 2){
        printf("Hello, %s\n", name);
    } else
        printf("Invalid input\n");
    return 0;
}
