#include <stdio.h>
int binaryiterative(int arr[],int element,int size){
    int lb=0,ub=size-1,mid;
    while(lb<=ub){
        mid=(lb+ub)/2;
        if(arr[mid]==element){
            return mid+1;
        }else if(element>arr[mid]){
            lb=mid+1;
        }else{
            ub=mid-1;
        }
    }
    return -1;
}
int binarysearchrecursive(int arr[],int lb,int ub,int element){
    int mid=(ub+lb)/2;
    if(lb>ub){
        return -1;
    }
        if(arr[mid]==element){
            return mid+1;
        }if(element>arr[mid]){
           return binarysearchrecursive(arr, mid+1,ub, element);
        }
    return binarysearchrecursive(arr, lb,mid-1,element);
}
int main(){
    int arr[10];
    int size,element;
    printf("Enter the size of array:");
    scanf("%d",&size);
    printf("Enter %d elements in array:", size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the element to be searched:");
    scanf("%d",&element);
    printf("element found at : %d\n",binaryiterative(arr, element, size));
    printf("Using recursive method : %d\n ",binarysearchrecursive(arr,0,size-1,element));
}