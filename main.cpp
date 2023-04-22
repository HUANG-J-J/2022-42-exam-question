#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

void swap(int &a,int &b){
    int temp=a;
     a=b;
     b=temp;
}

void HeapAdjust(int* A,int key,int len){
    int dad=key;
    int son=2*dad+1;
    while(son<len) {
        if (son<len-1&&A[son + 1] > A[son]) {
            son++;
        }
        if(A[son]>A[dad]){
            swap(A[son],A[dad]);
            dad=son;
            son=2*dad+1;
        }else{
            break;
        }
    }
}

void HeapSort(int* A,int len,int len0){
    int i;
    for(i=len/2-1;i>=0;i--){
        HeapAdjust(A,i,len);
    }
    for(i=len;i<len0;i++){
        if(A[i]<A[0]){
            A[0]=A[i];
            HeapAdjust(A,0,len);
        }
    }
}
void InitARR(int*& arr, int len) {
    arr = (int*)calloc(len, sizeof(int));
    srand((unsigned)time(NULL));
    for (int i = 0; i < len; i++) {
        if (arr)
            arr[i] = rand();
    }
}

void PrintARR(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int *ARR=NULL;
    const int length0=10000;
    const int length=10;
    InitARR(ARR,length0);
    HeapSort(ARR,length,length0);
    PrintARR(ARR,length);
    return 0;
}
