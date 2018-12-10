#include <stdio.h>

int main(int argc, char* argv[])
{
    system("clear");
	
	short arraySize = 0;
	
	printf("\nEnter the size of the array: ");
	scanf("%i", &arraySize);
	
	if (arraySize < 2) {
		printf("\nerror\n\n");
		return 1;
	}
	
	printf("\n");
	
	short array[arraySize];
	
	for (short i = 0; i < arraySize; i++) {
		printf("Please %i element array: ", i);
		scanf("%i", &array[i]);
	}
	
	short tempSum = array[0] + array[1];
	short element = 1;
	
	for (short i = 1; i < arraySize; i++) {
		
		short sum = array[i - 1] + array[i];
		
		if (sum < tempSum) {
			tempSum = sum;
			element = i;
		}
	}
	
	printf("\nTwo adjacent elements whose sum is minimal: element[%i] + element[%i] = %i\n\n", element - 1, element, tempSum);
    return 0;
}