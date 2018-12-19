#include <stdio.h>

void continueCheck(int* active) 
{
	printf("\nContinue? Enter 1 or 0: ");
	scanf("%i", active);
	printf("\n");
}

int main(int argc, char* argv[])
{

    system("clear");

    int one = 0, two = 0;
    char symbol;
	
	int active = 1;

    while (active) {

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
                printf("%f\n\n", (float)one / two);
                break;

            case '%':
                printf("%i\n\n", one % two);
                break;

            default:
                printf("unknown\n\n");
                break;
        }
		
		continueCheck(&active);
    }

   return 0;
}