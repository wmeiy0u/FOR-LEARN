// #include<bits/stdc++.h>
// using namespace std;
// int n;
// void mergesort( int *arr,int left,int mid,int right){
//     int l_pos=left, r_pos=mid+1;
//     int pos=left;
//     int temparr[n]={0};

//     while(l_pos<=mid&&r_pos<=right){
//         if(arr[l_pos]>arr[r_pos]){          //大于或者小于号决定升序，降序排序，当前为降序排序
//             temparr[pos++]=arr[l_pos++];
//         }
//         else temparr[pos++]=arr[r_pos++];
//     }


//     while(l_pos<=mid)
//         temparr[pos++]=arr[l_pos++];
//     while(r_pos<=right)  
//         temparr[pos++]=arr[r_pos++];


//     while(left<=right){
//         arr[left]=temparr[left];
//         left++;
//     }
// }

// void in_mergesort(int *arr,int left,int right){
//     if(left<right){
//         int mid=(left+right)/2;
//         //递归分开数
//         in_mergesort(arr,left,mid);
//         in_mergesort(arr,mid+1,right);
//         //合并排序
//         mergesort(arr,left,mid,right);
//     }

// }
// int main(){
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<' ';
//     }
//     cout<<endl;
//     in_mergesort(a,0,n-1);
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<' ';
//     }
//     system("pause");
//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;
int n;

void mergesort(int *arr,int left,int mid,int right){
    int l_pos=left,r_pos=mid+1;
    int pos=left;
    int temparr[n]={0};
    while(l_pos<=mid&&r_pos<=right){
        if(arr[l_pos]<arr[r_pos])temparr[pos++]=arr[l_pos++];       //此行决定为升序排序
        else temparr[pos++]=arr[r_pos++];
    }

    while(l_pos<=mid)temparr[pos++]=arr[l_pos++];
    while(r_pos<=right)temparr[pos++]=arr[r_pos++];

    while(left<=right){
        arr[left]=temparr[left];
        left++;
    }
}

void in_mergesort(int *arr,int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        in_mergesort(arr,left,mid);
        in_mergesort(arr,mid+1,right);

        mergesort(arr,left,mid,right);
    }
}

int main(){
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    in_mergesort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    system("pause");
    return 0;
}