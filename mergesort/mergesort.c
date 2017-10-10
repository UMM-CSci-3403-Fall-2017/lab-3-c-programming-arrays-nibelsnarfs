#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "mergesort.h"

// Looks at the size of the range and returns a one if it is greater than 2 and thus the array needs sorting. 
// Returns a 0 if smaller and not in need of sorting
int needsSorting(int rangeSize){
        if(rangeSize >= 2){
                return 1;
        }else{
                return 0;
        }
}

//Takes an array of values, a starting index, a midpoint index, and an ending index
//and merges the two values array from the start to the midpoint and from the midpoint to the end together
void mergeRanges(int* values, int startIndex, int midPoint, int endIndex){
        const int rangeSize = endIndex - startIndex;
        int* destination = (int*) calloc(rangeSize, sizeof(int));
        int firstIndex = startIndex;
        int secondIndex = midPoint;
        int copyIndex = 0;
        while(firstIndex < midPoint && secondIndex < endIndex){
                if(values[firstIndex] < values[secondIndex]){
                	destination[copyIndex] = values[firstIndex];
                	firstIndex++;
        }else{
                	destination[copyIndex] = values[secondIndex];
                	secondIndex++;
        }
        	copyIndex++;
        }
        while (firstIndex < midPoint){
        	destination[copyIndex] = values[firstIndex];
        	copyIndex++;
        	firstIndex++;
        }
        while(secondIndex < endIndex){
        	destination[copyIndex] = values[secondIndex];
        	copyIndex++;
        	secondIndex++;
        }
        for(int i = 0;i < rangeSize;i++){
                values[i + startIndex] = destination[i];
                }
	free(destination);
        }
//Takes an array of values and sorts the array from startIndex to endIndex in place
void mergesortRange(int* values, int startIndex,int endIndex){
        int rangeSize = endIndex - startIndex;
        if(needsSorting(rangeSize) == 1){
                int midPoint = (startIndex + endIndex) / 2;
                mergesortRange(values,startIndex,midPoint);
                mergesortRange(values,midPoint,endIndex);
                mergeRanges(values,startIndex,midPoint,endIndex);
        }
}
//Calls mergesortRange on the array of a given size
void mergesort(int size,int* values){
	mergesortRange(values,0,size);
}

