#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char s[100];
    scanf("%[^\n]%*c", s);
    
    // Print the input string
    printf("Hello, World!\n");
    printf("%s", s);
    
    return 0;
}
