#include <stdio.h>
 
 
int main(){
 
    int total,arrival_time[10],burst_time[10],OG_BT[10],q,complete = 0;
    int w_t[10],c_t[10],ta_t[10],current,completion_time=0,flag=0;
    float avg_w_t=0,avg_ta_t=0;
    printf("Enter Time Quantum:");
    scanf("%d", &q);
    printf("\nEnter the total number of processes:");
    scanf("%d", &total); 
 
    for(int i = 0; i < total; i++){
        
        printf("\nEnter Burst Time:");
        scanf("%d", &burst_time[i]); 
        OG_BT[i] = burst_time[i];
 
    }
 
 
    current=0;
    for(int time=0;complete<total;){
        if(burst_time[current]<=q && (burst_time[current])>0){
            
            time+=burst_time[current];
            burst_time[current]=0;
            flag=1;
            
        }else if(burst_time[current]>q){
            burst_time[current]-=q;
            time+=q;
            
        }
        if(burst_time[current]==0 && flag==1){
            
            
            complete++;
            c_t[current] = time;
            w_t[current] = time  - OG_BT[current];
            ta_t[current] = time;
            flag=0;
        }
        current+=1;
        current=current%total;
        completion_time=time;
 
    }
     for(int i = 0; i < total; i++){
        avg_w_t+=w_t[i];
        avg_ta_t+=ta_t[i];
    }
 
    avg_w_t=avg_w_t/total;
    avg_ta_t=avg_ta_t/total;
 
 
    printf("WT is %f\nTAT is %f\nCT is %d\n",avg_w_t,avg_ta_t,completion_time);
 
 
}
