#include <stdlib.h>
#include <stdio.h>

int arrayInt[10]={100,100,23,5,1,463,98,3,99,0};
void quick_sort(int arrayInt[],int firstElement, int endElement);
int partition(int arrayInt[],int firstElement, int endElement);
void printArray(int arrayInt[], int numberElement);
int main(){
	quick_sort(arrayInt,0,9);
	printArray(arrayInt,10);
}
void quick_sort(int arrayInt[],int firstElement, int endElement){

	int i;
	if(endElement>firstElement){
		i=partition(arrayInt,firstElement,endElement);
		quick_sort(arrayInt,firstElement,i-1);
		quick_sort(arrayInt,i+1,endElement);
	}

}
int partition(int arrayInt[],int firstElement, int endElement){
	int i=firstElement, j=endElement;
	int rootElement=arrayInt[(firstElement+endElement)/2];
	int temp;
	while(1){
	for(i;i<=endElement&&arrayInt[i]<rootElement;i++);
		for(j;arrayInt[j]>rootElement;j--);
		if(i>=j){
			break;
		}
		if(arrayInt[i]==arrayInt[j])
			j--;
		temp=arrayInt[i];
		arrayInt[i]=arrayInt[j];
		arrayInt[j]=temp;
	}
	return j;	
}
void printArray(int arrayInt[], int numberElement){
	int i=0;
	
	for(i=0;i<numberElement;i++){
		printf("array[%d]=%d \n",i,arrayInt[i]);
	}
}