#include <stdlib.h>
#include <stdio.h>
void mergeRanges(int values[], int startIndex, int midPoint, int endIndex){
        const int rangeSize = endIndex - startIndex;
        int destination[rangeSize] = {0};
        int firstIndex = startIndex;
        int secondIndex = midPoint;
        int copyIndex = 0;
        while(firstIndex < midPoint && secondIndex < endIndex){
                if(values[firstIndex] < values[secondIndex]){
                destination[copyIndex] = values[secondIndex];
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
        for(int i;i < rangeSize;i++){
                values[i+startIndex] = destination[i];
                }
        free(destination);
        }
	int needsSorting(int rangeSize){
if(rangeSize >= 2){
return 1;
}else{
return 0;
}
}

void mergesortRange(int values[], int startIndex,int endIndex){
        int rangeSize = endIndex - startIndex;
        if(needsSorting(rangeSize) == 1){
                int midPoint = (startIndex + endIndex) / 2;
                mergesortRange(values,startIndex,midPoint);
                mergesortRange(values,midPoint,endIndex);
                mergeRanges(values,startIndex,midPoint,endIndex);
        }
}

void mergesort(int size,int values[]){
	mergesortRange(values,0,size);
}

