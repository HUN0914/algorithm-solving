#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// diffs_len은 배열 diffs의 길이입니다.
// times_len은 배열 times의 길이입니다.
int solution(int diffs[], size_t diffs_len, int times[], size_t times_len, long long limit) {
    int answer = 0;
    
    long long high=0;
    for(int i=0; i<diffs_len; i++){
        if(diffs[i]>high) high=diffs[i];
    }
    
    long long low=1;

    while(low<high){
        
        long long mid=(high+low)/2;
        
        long long total=0;
        long long recent_time=0;
        
        for(int i=0; i<diffs_len; i++){
            
            if(i>0) {
                recent_time=times[i-1];
            }
            
            if(diffs[i]<=mid){
                total+=times[i];
            }else{
                total+=(times[i]+recent_time)*(diffs[i]-mid)+times[i];
            }
            
        }
        
        if(total<=limit){
            high=mid;
        }else{
            low=mid+1;
        }
        
    }
    answer=low;
    
    return answer;
}