#include<stdio.h>
#include<conio.h>

int binary_search(int size, int *arr, int target);

int main(){
int arr[] = {1,2,3,4,5,6,7};
int size = sizeof(arr)/sizeof(arr[0]);
int target;
int result;

printf("Enter what you want to search : ");
scanf("%d",&target);
result = binary_search(size, arr, target);
if(result == -1){
printf("Target not found !\n");
}
else{
printf("Target found at index %d\n",result);
}
getch();
return 0;
}

int binary_search(int size, int arr[], int target){
int low = 0;
int high = size - 1;
int mid;
while(low <= high){
mid = (high + low)/2;
if(arr[mid] == target){
return mid;
}
else if(arr[mid] < target){
low = mid + 1;
}
else{
high = mid - 1;
}
}
return -1;
}