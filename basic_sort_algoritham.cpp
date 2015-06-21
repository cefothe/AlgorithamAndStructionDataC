#include <stdlib.h>
#include <stdio.h>

int arrayInt [10]={10,0,2,5,7,1,4,6,7,3};

void selection_sort(int arrayInt[],int numeberElementArray);
void insertion_sort(int arrayInt[], int numberElementArray);
void bubble_sort(int arrayInt[],int numberElementArray);
void shell_sort(int arrayInt[],int numebrElementArray); 
void printSortArray(int arrayInt[],int numberElementArray);

int main(){
	//selection_sort(arrayInt,10);
	//insertion_sort(arrayInt,10);
	//bubble_sort(arrayInt,10);
	shell_sort(arrayInt,10);
	printSortArray(arrayInt,10);
}

void printSortArray(int arrayInt[],int numberElementArray){
	int i=0;
	for(i=0;i<numberElementArray;i++){
		printf("array[%d]=%d \n",i,arrayInt[i]);
	}
}
void selection_sort(int arrayInt[],int numeberElementArray){
	int i,j,minIndex,temp;
	
	for(i=0;i<numeberElementArray-1;i++){
		minIndex=i;
		for(j=i+1;j<=numeberElementArray-1;j++){
			if(arrayInt[j]<arrayInt[minIndex]){
				minIndex=j;
			}
		}
		if(minIndex!=i){
			temp=arrayInt[minIndex];
			arrayInt[minIndex]=arrayInt[i];
			arrayInt[i]=temp;
		}
	}
}
void insertion_sort(int arrayInt[], int numberElementArray){
	int i,j,temp;
	for(i=1;i<numberElementArray;i++){
		temp=arrayInt[i];
		j=i-1;
		while(j>=0&&temp<arrayInt[j]){
			arrayInt[j+1]=arrayInt[j];j--;
		}
		arrayInt[j+1]=temp;
	}
}
void bubble_sort(int arrayInt[],int numberElementArray){
	int i,j, temp;
	for(i=0;i<numberElementArray-1;i++){
		for(j=i;j<numberElementArray-1;j++){
			if(arrayInt[j]>arrayInt[j+1]){
				temp=arrayInt[j];
				arrayInt[j]=arrayInt[j+1];
				arrayInt[j+1]=temp;
			}
		}
	}
}
void shell_sort(int arrayInt[],int numebrElementArray){
	int i,j,temp, h;
	for(h=1;h<numebrElementArray/3;h=3*h+1){
		while(h>0){
			for(i=h;i<numebrElementArray;i++){
				temp=arrayInt[i];j=i-h;
				while(j>=0&&temp<arrayInt[j]){
					arrayInt[j+h]=arrayInt[j];
					j-=h;
				}
				arrayInt[j+h]=temp;
			}
			h=h/3;
		}
	}
}