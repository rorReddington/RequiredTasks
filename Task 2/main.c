#include <stdio.h>

int main(int argc, char* argv[])
{
	
    system("clear");
    
    int one = 0, two = 0;
    char symbol;
    
    while (true) {
        
        scanf("%i %c %i", &one, &symbol, &two);
        
        printf("%i %c %i = ", one, symbol, two);
        
        switch (symbol) {
                
            case '+':
                printf("%i\n\n", one + two);
                break;
                
            case '-':
                printf("%i\n\n", one - two);
                break;
                
            case '*':
                printf("%i\n\n", one * two);
                break;
                
            case '/':
                printf("%d\n\n", one / two);
                break;
                
            case '%':
                printf("%i\n\n", one % two);
                break;
                
            default:
                printf("unknown\n\n");
                break;
        }
    }
 
   return 0;
}
