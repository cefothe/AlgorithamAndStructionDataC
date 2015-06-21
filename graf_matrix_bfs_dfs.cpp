#include <stdio.h>
#include <stdlib.h>

#define nMax 5

int matrix[nMax][nMax]={
	{0,1,1,0,0},
	{1,0,1,1,0},
	{1,1,0,1,1},
	{0,1,1,0,1},
	{0,0,1,1,0}
};
int used[nMax];

void bfs(int index);
void dfs(int index);

int main(){
	printf("Breadth-First-Search \n");
	bfs(2);
	int k;
	//Reset array elements
	for(k=0;k<nMax;k++)used[k]=0;
	printf("Depth-First-Search");
	dfs(1);
}
void bfs(int index){
	int j,k,p, queue[nMax], currentVert, levelVert, queueEnd;
	
	//Reset array elements
	for(k=0;k<nMax;k++)used[k]=0;
	for(k=0;k<nMax;k++)queue[k]=0;
	
	queue[0]=index;used[index]=1;

	currentVert=0; levelVert=1; queueEnd=1;

	while(currentVert<queueEnd){ //while the queue is not empty
		for(p=currentVert; currentVert<levelVert;p++){
			//take another element from the queue
			printf("%d", queue[p]+1);
			currentVert++;
			for(j=0;j<nMax;j++){
				if(matrix[queue[p]][j]&&!used[j]){
					//for anyone not bypass successor j to queue [p]
					queue[queueEnd++]=j;
					used[j]=1;
				}
			}
			
		}
		printf("\n");
		levelVert=queueEnd;
	}
}
void dfs(int index){
	int k;
	used[index]=1;
	printf("%d ",index+1);
	for(k=1;k<nMax;k++){
		if(matrix[index][k]&& !used[k])dfs(k);
	}
}