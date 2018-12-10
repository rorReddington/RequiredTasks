#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
	
	float a = 1, b = 1, c = 1;
	float discriminant = 0;
	float oneX = 0, twoX = 0;
    
    system("clear");
	
	while (true) {
        
		printf("\nPlease enter the a, b, c: ");
		scanf("%f %f %f", &a, &b, &c);
		
		discriminant = (b*b) - (4*a*c);
		
        if (discriminant > 0) {
            
            b = b * -1;
            oneX = (b + sqrt(discriminant))/(2*a);
            twoX = (b - sqrt(discriminant))/(2*a);
            printf("\n\nThe roots of the equation: %.2f %.2f\n\n", oneX, twoX);
        }
        else if (discriminant == 0) {
            
            b = b * -1;
            oneX = b/(2*a);
            printf("\n\nThe root of the equation: %.2f\n\n", oneX);
        }
        else {
            printf("\n\nThe equation has no roots\n\n");
        }
		
	}
	
	return 0;
}