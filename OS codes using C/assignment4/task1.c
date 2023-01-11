#include <stdio.h>
 
int main(){
 
    int total,arrival_time[10],burst_time[10],OG_BT[10],complete = 0;
    int w_t[10],c_t[10],ta_t[10],shortest,completion_time;
    float avg_w_t=0,avg_ta_t=0;
    printf("Enter the total number of processes:");
    scanf("%d", &total); 
 
    for(int i = 0; i < total; i++){
        printf("\nEnter Arrival Time:");
        scanf("%d", &arrival_time[i]);
        printf("\nEnter Burst Time:");
        scanf("%d", &burst_time[i]); 
        OG_BT[i] = burst_time[i];
    }
 
    burst_time[9]=999;
 
    for(int time=0;complete<total;time++){
        shortest = 9;
        for(int i = 0; i < total; i++){
                  if(arrival_time[i] <= time &&  burst_time[i] > 0 && burst_time[i] < burst_time[shortest] ){
                        shortest = i;
                  }
            }
        burst_time[shortest]--;
        if(burst_time[shortest]==0){
 
            complete++;
            c_t[shortest] = time+1;
            w_t[shortest] = time + 1 - arrival_time[shortest] -OG_BT[shortest];
            ta_t[shortest] = time + 1 - arrival_time[shortest];
 
        }
 
        completion_time=time+1;
 
    }
     for(int i = 0; i < total; i++){
        avg_w_t+=w_t[i];
        avg_ta_t+=ta_t[i];
    }
 
    avg_w_t=avg_w_t/total;
    avg_ta_t=avg_ta_t/total;
 
    printf("WT is %f\nTAT is %f\nCT is %d",avg_w_t,avg_ta_t,completion_time);
 
}

