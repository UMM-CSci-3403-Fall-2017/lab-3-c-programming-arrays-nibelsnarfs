#include "array_merge.h"
#include <stdlib.h>
#include <stdio.h>
#include "../mergesort/mergesort.c"

//Takes an int indicating the number of arrays stored in the values array
//and an array describing the sizes of the array in the values array 
//and merges all the arrays in values into one sorted array 
//of only the unique values in the arrays of values
int* array_merge(int num_arrays,int* sizes, int** values){
	int* result;
	int fullSize = 0;

	for(int i = 0; i < num_arrays; i++){
		fullSize += sizes[i];
	}

	int* tempArr = (int*) calloc(fullSize, sizeof(int));
	int currentIndex = 0;
	
	//puts all of the elements in value into a temporary array
	for(int j = 0; j < num_arrays; j++){
		for(int n = 0; n < sizes[j]; n++){
				tempArr[currentIndex] = values[j][n];
				currentIndex++;
		}
	}
	
	//sorts the temporary array to make later operations easier
	mergesort(fullSize, tempArr);

	int tempSize = fullSize;
	int current = tempArr[0];
	int* holder = (int*) calloc(fullSize, sizeof(int));
	currentIndex = 1;
	holder[0] = tempArr[0];
	
	//iterates through the temporary array and finds all the unique values
	for(int i = 1; i < tempSize; i++){
		if(tempArr[i] == current){
			fullSize--;
		}else{
			holder[currentIndex] = tempArr[i];
			current = tempArr[i];
			currentIndex++;
		}
	}

	free(tempArr);

	result = (int*) calloc(fullSize + 1, sizeof(int));
	
	//moving everything from a temporary array to the result array
	//this gives us the proper array size
	for(int i = 1; i < fullSize + 1; i++){
		result[i] = holder[i - 1];
	}

	free(holder);

	//adds the amount of values in the result array to the front of the result array
	result[0] = fullSize;

	return result;

}

