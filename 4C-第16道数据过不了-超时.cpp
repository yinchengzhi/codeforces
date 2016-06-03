

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n;
    cin>>n;
    int b[100005];                  //用来存储每个账号出现的次数
    memset(b,0,sizeof(b));
    char a[n][40];                //存储字符串
    for(int i=0;i<n;i++) {
        strcpy(a[i],"0");         //把里面所有字符数组初始化为0
    }
    //    for(int i=0;i<n;i++){       //打印所有字符数组
    //        cout<<a[i]<<endl;
    //    }
    char str[50];
    for(int i=0;i<n;i++){
        memset(str,0,sizeof(str));
        cin>>str;
        int flag=1;               //设置标志位,1表示不存在记录,0表示存在记录
        int number=0;             //记录每个账号出现的次数
        for(int j=0;j<i;j++){
            if(strcmp(a[j],str)==0){
                b[j]++;
                number=b[j];
//                cout<<"------------------------------------"<<"j="<<j<<" "<<"b[j]="<<b[j]<<endl;
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<"OK"<<endl;
            strcpy(a[i],str);
        }else{
            cout<<str<<number<<endl;
        }
    }

//        cout<<endl;
//        cout<<endl;

//        for(int i=0;i<n;i++){       //打印所有字符数组
//            cout<<"a["<<i<<"]="<<a[i]<<endl;
//        }
//        cout<<endl;

//        for(int i=0;i<n;i++){
//            cout<<"b["<<i<<"]="<<b[i]<<endl;
//        }

    return 0;
}

