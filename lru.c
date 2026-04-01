#include<stdio.h>
int main(){
    int pages[]={1,2,3,4,5,6};
    int n=6,f=3;
    int frame[3],time[3];
    int i,j,k,fault=0,found,min,pos;
    for(i=0;i<f;i++){
        frame[i]=-1;time[i]=0;
    }
    for(i=0;i<n;i++){
        found=0;
        for(j=0;j<f;j++){
            if(frame[j]==pages[i]){
                found=1;
                time[j]=i;
                break;
            }
        }
        if(!found){
            min=time[0];
            pos=0;
            for(j=1;j<f;j++){
                if(time[j]<min){
                    min=time[j];
                    pos=j;
                }
            }
            frame[pos]=pages[i];
            time[pos]=i;
            fault++;
        }
        printf("Page%d->",pages[i]);
        for(k=0;k<f;k++)
            printf("%d ",frame[k]);
        printf("\n");
    }
    printf("Total Page Faults=%d\n",fault);
    return 0;
}