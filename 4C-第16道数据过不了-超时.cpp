

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n;
    cin>>n;
    int b[100005];                  //�����洢ÿ���˺ų��ֵĴ���
    memset(b,0,sizeof(b));
    char a[n][40];                //�洢�ַ���
    for(int i=0;i<n;i++) {
        strcpy(a[i],"0");         //�����������ַ������ʼ��Ϊ0
    }
    //    for(int i=0;i<n;i++){       //��ӡ�����ַ�����
    //        cout<<a[i]<<endl;
    //    }
    char str[50];
    for(int i=0;i<n;i++){
        memset(str,0,sizeof(str));
        cin>>str;
        int flag=1;               //���ñ�־λ,1��ʾ�����ڼ�¼,0��ʾ���ڼ�¼
        int number=0;             //��¼ÿ���˺ų��ֵĴ���
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

//        for(int i=0;i<n;i++){       //��ӡ�����ַ�����
//            cout<<"a["<<i<<"]="<<a[i]<<endl;
//        }
//        cout<<endl;

//        for(int i=0;i<n;i++){
//            cout<<"b["<<i<<"]="<<b[i]<<endl;
//        }

    return 0;
}

