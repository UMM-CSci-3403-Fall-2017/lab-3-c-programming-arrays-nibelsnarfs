#include "array_merge.h"
#include <stdlib.h>
#include <stdio.h>
#include "../mergesort/mergesort.c"


int* array_merge(int num_arrays,int* sizes, int** values){
	int* result;
	int fullSize = 0;

	for(int i = 0; i < num_arrays; i++){
		fullSize += sizes[i];
	}

	int* tempArr = (int*) calloc(fullSize, sizeof(int));
	int currentIndex = 0;

	for(int j = 0; j < num_arrays; j++){
		for(int n = 0; n < sizes[j]; n++){
				tempArr[currentIndex] = values[j][n];
				currentIndex++;
		}
	}

	mergesort(fullSize, tempArr);

	int tempSize = fullSize;
	int current = tempArr[0];
	int* holder = (int*) calloc(fullSize, sizeof(int));
	currentIndex = 1;
	holder[0] = tempArr[0];

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

	for(int i = 1; i < fullSize + 1; i++){
		result[i] = holder[i - 1];
	}

	free(holder);

	result[0] = fullSize;

	return result;

}

