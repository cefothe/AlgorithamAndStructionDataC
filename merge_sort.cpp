#include <stdio.h>
#include <stdlib.h>
#define MAXELEMENT 25

int arrayInt[10]={3,12,3,12,4,2,5,7,5,8};
void merge_sort(int arrayInt[],int firstElement, int lastElement);
void merge(int arrayInt[], int firsElement, int mediumElement, int lastElement);
void printArray(int arrayInt[], int numberElement);

int main(){
	merge_sort(arrayInt,0,10);
	printArray(arrayInt,10);
}
void merge_sort(int arrayInt[],int firstElement, int lastElement){

	int mediumElement;
	if(lastElement>firstElement){
		mediumElement=(firstElement+lastElement)/2;
		merge_sort(arrayInt,firstElement,mediumElement);
		merge_sort(arrayInt,mediumElement+1,lastElement);
		merge(arrayInt,firstElement,mediumElement,lastElement);
	}
}
void merge(int arrayInt[], int firsElement, int mediumElement, int lastElement){
	int i,m,k,l,temp[MAXELEMENT];

    l=firsElement;
    i=firsElement;
    m=mediumElement+1;

    while((l<=mediumElement)&&(m<=lastElement)){

         if(arrayInt[l]<=arrayInt[m]){
             temp[i]=arrayInt[l];
             l++;
         }
         else{
             temp[i]=arrayInt[m];
             m++;
         }
         i++;
    }

    if(l>mediumElement){
		for(k=m;k<=lastElement;k++){
			temp[i]=arrayInt[k];
             i++;
         }
    }
    else{
		for(k=l;k<=mediumElement;k++){
			temp[i]=arrayInt[k];
             i++;
         }
    }
   
	for(k=firsElement;k<=lastElement;k++){
		arrayInt[k]=temp[k];
    }
}
void printArray(int arrayInt[], int numberElement){
	int i;
	for(i=0;i<numberElement;i++){
		printf("array[%d]=%d \n",i,arrayInt[i]);
	}
}