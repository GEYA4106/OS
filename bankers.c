#include<stdio.h>
int main(){
    int n,m,i,j,k;
    int alloc[10][10],max[10][10],need[10][10];
    int avail[10],finish[10],safeseq[10];
    int found,count=0;
    printf("Enter no.of processes: ");
    scanf("%d",&n);
    printf("Enter no.of resources: ");
    scanf("%d",&m);
    printf("Enter allocation matrix:\n"); 
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter maximum matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter available resources:\n");
    for(i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(i=0;i<n;i++)
        finish[i]=0;
    while(count<n){
        found=0;
        for(i=0;i<n;i++){
            if(finish[i]==0){
                for(j=0;j<m;j++){
                    if(need[i][j] > avail[j])
                        break;
                }
                if(j==m){ 
                    for(k=0;k<m;k++){
                        avail[k] += alloc[i][k];
                    }
                    safeseq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found==0){
            printf("System is not in safe state\n");
            return 0;
        }
    }
    printf("System is in safe state\nSafe sequence: ");
    for(i=0;i<n;i++){
        printf("P%d ", safeseq[i]);
    }
    return 0;
}