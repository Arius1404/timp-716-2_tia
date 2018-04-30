#include <stdio.h>
#include <stdlib.h>

void comb_sort(int n, int arr[]){
    int step=n-1,c;
    while(step>=1){
        for(int i=0;i<n-step;i++){
            if(arr[i]>arr[i+step]){
                c=arr[i];
                arr[i]=arr[i+step];
                arr[i+step]=c;
            }
        }
        step--;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    comb_sort(n,arr);
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

