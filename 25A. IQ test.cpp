#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,a[100];
    int EvenSum=1,OddSum=1,EvenCount=0,OddCount=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            EvenCount++;
            EvenSum+=i;
        }else{
            OddCount++;
            OddSum+=i;
        }
    }
    if(EvenCount>OddCount){
        printf("%d\n",OddSum);
    }else{
        printf("%d\n",EvenSum);
    }

    return 0;
}