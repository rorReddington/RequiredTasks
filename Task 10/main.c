#include <stdio.h>

int main(int argc, char* argv[])
{
    system("clear");

    char buffer[256];
    char symbol;

    short count = 0;

    printf("\nInput text:\n");
    fgets(buffer, sizeof(buffer), stdin);

    printf("\nEnter symbol: ");
    scanf("%c", &symbol);

    char* p = buffer;

    while (*p != 0)
    {

        if (*p == symbol)
            count++;

        p++;
    }

    printf("\ncount: %lu\n", count);

    return 0;
}
