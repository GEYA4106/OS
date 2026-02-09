#include<stdio.h>
int main(){
	int n,i;
	int bt[20],wt[20],tat[20];
	printf("Enter number of process");
	scanf("%d",&n);
	printf("Enter burst time of processes:\n");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
	}
	wt[0]=0;
	for(i=0;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
	}
	for(i=0;i<n;i++){
		tat[i]=wt[i]+bt[i];
	}
	printf("\Process\tBT\tWT\tTAT\n");
	for(i=0;i<n;i++){
		printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
	}
	return 0;
}
