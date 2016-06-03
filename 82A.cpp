
#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int n,n1 = 0,oldn=0;
    int temp;
    cin>>n;
    if(n>5)
    {
        oldn = n;
        n = n/5+1;
        for(int i=0;i<100;i++)
        {
            if(pow(2,i)>n)
            {
                n1 = i-1;
                break;
            }
        }
//        cout<<n1<<endl;
//        cout<<oldn<<" "<<(5*(pow(2,n1)-1))<<endl;

        temp = oldn - (5*(pow(2,n1)-1));

//        cout<<temp<<endl;
//        cout<<(int)(pow(2,n1))<<endl;

        switch (temp/(int)(pow(2,n1))) {
        case 0:
            cout<<"Sheldon"<<endl;
            break;
        case 1:
            cout<<"Leonard"<<endl;
            break;
        case 2:
            cout<<"Penny"<<endl;
            break;
        case 3:
            cout<<"Rajesh"<<endl;
            break;
        case 4:
            cout<<"Howard"<<endl;
            break;
        }
    }
    else
    {
        switch (n) {
        case 1:
            cout<<"Sheldon"<<endl;
            break;
        case 2:
            cout<<"Leonard"<<endl;
            break;
        case 3:
            cout<<"Penny"<<endl;
            break;
        case 4:
            cout<<"Rajesh"<<endl;
            break;
        case 5:
            cout<<"Howard"<<endl;
            break;
        }

    }
    return 0;
}















