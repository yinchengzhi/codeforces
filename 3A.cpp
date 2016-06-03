#include<cstdio>
char a[3],b[3],c,d,x,y;
int main(){
    gets(a);
    gets(b);
    x=a[0]-b[0];
    y=a[1]-b[1];
    c=((x<0)?x=-x,'R':'L');
    d=((y<0)?y=-y,'U':'D');
    printf("%d",x>y?x:y);
    while(x|y){
        puts("");
        if(x)x--,putchar(c);
        if(y)y--,putchar(d);
    }
    return 0;
}