#include<bits/stdc++.h>
using namespace std; 
void quicksort(int arr[],int left,int right){
    int i=left,j=right;
    int pivot=arr[left];
    if(i>=j)return ;
    while (i<j){
        while(arr[j]>=pivot&&i<j)j--;                       //8,9行决定升序与降序，此处为升序
        while(arr[i]<=pivot&&i<j)i++;
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[left],arr[i]);
    quicksort(arr,left,i-1);
    quicksort(arr,i+1,right);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    system("pause");
	return 0;
}




