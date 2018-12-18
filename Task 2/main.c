#include <stdio.h>
#include <math.h>

void continueCheck(int* active)
{
    printf("\nContinue? Enter 1 or 0: ");
    scanf("%i", active);
}

int main(int argc, char* argv[])
{
    float a = 1, b = 1, c = 1;
    float discriminant = 0;
    float oneX = 0, twoX = 0;

    int active = 1;

    system("clear");

    while (active != 0)
    {

        printf("\nPlease enter the a, b, c: ");
        scanf("%f %f %f", &a, &b, &c);

        discriminant = (b * b) - (4 * a * c);

        if (a == 0)
        {

            printf("\nThe coefficient at the first term of the equation cannot be equal to zero, "
                   "change it and try again.\n");
            continueCheck(&active);
            continue;
        }

        if (discriminant > 0)
        {

            b = b * -1;
            oneX = (b + sqrt(discriminant)) / (2 * a);
            twoX = (b - sqrt(discriminant)) / (2 * a);
            printf("\nThe roots of the equation: %.2f %.2f\n", oneX, twoX);
        }
        else if (discriminant == 0)
        {

            b = b * -1;
            oneX = b / (2 * a);
            printf("\nThe root of the equation: %.2f\n", oneX);
        }
        else
        {
            printf("\nThe equation has no roots\n");
        }

        continueCheck(&active);
    }

    return 0;
}