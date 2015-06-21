#include <stdlib.h>
#include <stdio.h>

int arrayInt[10]={1,12,3,12,4,2,5,7,5,8};
void shift(int arrayInt[], int firstElement, int lastElement);
void heapSort(int arrayInt[], int numberOfElement);
void printArray(int arrayInt[], int numberOfElement);
int main(){
	printArray(arrayInt,10);
	heapSort(arrayInt,10);
	printf("\n\n");
	printArray(arrayInt,10);
}
void shift(int arrayInt[], int firstElement, int lastElement){
	int i= firstElement, temp;
	int j =i+i;
	temp=arrayInt[i];
	while(j<=lastElement){
		if(j<lastElement && arrayInt[j]< arrayInt[j+1]){
			j++;
		}
		if(temp>=arrayInt[j])break;
		arrayInt[i]=arrayInt[j];
		i=j;
		j<<=1;// This is j*=2
	}
	arrayInt[i]=temp;
}
void heapSort(int arrayInt[], int numberOfElement){
	int k;
	 for (k = numberOfElement/2 + 1; k > 1; k--)
		 shift(arrayInt,k-1,numberOfElement); 

	 int temp;
	 for (k = numberOfElement-1; k > 1; k--) {
		 temp=arrayInt[k];
		 arrayInt[k]=arrayInt[1];
		 arrayInt[1]=temp;
		 shift(arrayInt,1,k-1);
	 }
}

void printArray(int arrayInt[], int numberElement){
	int i;
	for(i=0;i<numberElement;i++){
		printf("array[%d]=%d \n",i,arrayInt[i]);
	}
}