#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
	int h = 0, m = 0, angle = 0;
	
	system("clear");
	printf("\nEnter the hour: ");
	scanf("%i", &h);
	
	printf("\nEnter the minute: ");
	scanf("%i", &m);
	
	if ((h < 0) || (h > 12)) {
		
		printf("\nError (hour)\n\n");
		return 1;
	}
	
	if ((m < 0) || (m > 60)) {
		
		printf("\nError (minute)\n\n");
		return 1;
	}
	
	if (h == 12)
		h = 0;
	
	if (m == 60)
		m = 0;
	
	angle = abs((h*30) - (m*6));
	
	printf("\nangle = %i\n\n", angle);
	return 0;
}
