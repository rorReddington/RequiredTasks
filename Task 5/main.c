#include <stdio.h>

short getLargestElementArray(short* array, short size) {
	
	short max = array[0];
	
	for (short i = 0; i < size; i++) {
		
		if (array[i] > max)
			max = array[i];
	}
	
	return max;
}

short getSmallestElementArray(short* array, short size) {
	
	short min = array[0];
	
	for (short i = 0; i < size; i++) {
		
		if (array[i] < min)
			min = array[i];
	}
	
	return min;
}

int main(int argc, char* argv[])
{
    system("clear");
	
	short arraySize = 0;
	
	printf("\nEnter the size of the array: ");
	scanf("%i", &arraySize);
	
	if (arraySize < 1) {
		printf("\nerror\n\n");
		return 1;
	}
	
	printf("\n");
	
	short array[arraySize];
	
	for (short i = 0; i < arraySize; i++) {
		printf("Please %i element array: ", i);
		scanf("%i", &array[i]);
	}
	
	short max = getLargestElementArray(array, arraySize);
	short min = getSmallestElementArray(array, arraySize);
	
	printf("\nThe maximum element of the array: %i", max);
	printf("\nThe minimum element of the array: %i", min);
	printf("\nThe sum of the largest and smallest array elements: %i\n\n", max + min);
    return 0;
}