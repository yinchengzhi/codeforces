
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){

    int n,m,sum=0;
    scanf("%d%d",&n,&m);
    int a[n]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    sort(a,a+n);
    for(int i=0;i<m;i++){
        if(a[i]<0){
            sum+=a[i];
        }
    }

    printf("%d\n",-sum);

    return 0;
}




