#include <stdio.h>

int main(int argc, char* argv[])
{
	int linesNumber = 0;
	
	system("clear");
	printf("\nEnter the number of lines: ");
	scanf("%i", &linesNumber);
	system("clear");
	
	for (int i = 0; i <= linesNumber; i++) {
        
        printf("\t");
        
        for(int k = linesNumber; k > i; --k)
            printf(" ");
        
        for(int k = 1; k < 2 * i; ++k)
            printf("*");
        
        printf("\n");
	}
    
    printf("\n");
	return 0;
}
