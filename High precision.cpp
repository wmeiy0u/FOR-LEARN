#include<bits/stdc++.h>
using namespace std;
    string A,B;
    int sum1[2100],ta[2100],tb[2100],sum2[2100];
    int len1,jw,len2;
void AplusB(string A,string B,int *sum){            //高精度加法
    int lena=A.size(),lenb=B.size();
    len1=max(lena,lenb);
    for(int i=0;i<lena;i++){
        ta[i]=A[lena-i-1]-'0';
    }
    for(int i=0;i<lenb;i++){
        tb[i]=B[lenb-i-1]-'0';
    }

    for(int i=0;i<len1;i++){
        sum[i]=ta[i]+tb[i]+jw;
        jw=sum[i]/10;
        sum[i]=sum[i]%10;
    }

    if(jw>0){
        sum[len1]=jw;
        len1++;
    }
}

void AmultiplyB(string A,string B,int *sum){         //高精度乘法
    int lena=A.size(),lenb=B.size();
    for(int i=1;i<=lena;i++){
        ta[i]=A[lena-i]-'0';
    }
    for(int i=1;i<=lenb;i++){
        tb[i]=B[lenb-i]-'0';
    }
    for(int i=1;i<=lenb;i++){
        for(int j=1;j<=lena;j++){
            sum[i+j-1]+=ta[j]*tb[i];
        }
    }
    for(int i=1;i<=lena+lenb;i++){
        if(sum[i]>9){
                sum[i+1]+=sum[i]/10;
                sum[i]=sum[i]%10;
            }
    }
    len2=lena+lenb;
    while(sum[len2]==0&&len2>1)len2--;
}
int main(){
    cin>>A>>B;
    AplusB(A,B,sum1);
    AmultiplyB(A,B,sum2);
    for(int i=len1-1;i>=0;i--)cout<<sum1[i];
    cout<<endl;
    for(int i=len2;i>=1;i--)cout<<sum2[i];
    system("pause");
    return 0;
}