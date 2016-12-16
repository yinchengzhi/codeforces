#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
unsigned int gcd(unsigned int a,unsigned int b){
    int r;
    while(b>0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    a = max(a,b);
    printf("%d/%d\n",(7-a)/gcd(7-a,6),6/gcd(7-a,6));
    return 0;
}

