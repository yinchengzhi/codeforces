
//codeforce Problem-1B  code by yinchengzhi

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int pow(int x,int y){
    int result = 1;
    for(int i=0;i<y;i++){
        result*=x;
    }
    return result;
}
bool kind_RxCx(char*ch,int len){                                   //�жϵ�ַ�Ƿ���RC��ַ����
    if(ch[0]=='R'&&ch[1]>='0'&&ch[1]<='9')                         //���õ�һ���ַ���R�͵ڶ����ַ������֣����к�����ַ�����C�����
        for(int i=0;i<len;i++)
            if(ch[i]=='C') return 1;
    return 0;
}


int main(){
    int n;
    char str[100];
    char number1[64];                                              //����RC��ַ��¼�ڼ���
    char number2[64];                                              //����RC��ַ��¼�ڼ���
    char number3[64];                                              //���ڳ����ַ��¼ǰ����ĸ
    char number4[64];                                              //���ڳ����ַ��¼�ڼ���
    cin>>n;
    while(n--){
        memset(str,0,sizeof(str));
        memset(number1,0,sizeof(number1));
        memset(number2,0,sizeof(number2));
        memset(number3,0,sizeof(number3));
        memset(number4,0,sizeof(number4));
        int i=0;
        cin>>str;
        if(kind_RxCx(str,strlen(str))){                            //����ж�ΪRC��ַ��ִ�д�RC��ַ�������ַ��ת��
            for(i=1;i<strlen(str);i++){
                if(str[i]>='0'&&str[i]<='9'){
                    number1[i-1]=str[i];
                }else{
                    break;
                }
            }
            int PreNumber = atoi(number1);                         //PreNumber��ʾRC��ַ�ĵڼ���.
            for(int j=0;i<strlen(str);i++){
                if(str[i]>='0'&&str[i]<='9'){
                    number2[j++]=str[i];
                }
            }
            int suffixNumber = atoi(number2);                      //suffixNumber��ʾRC��ַ�ĵڼ���.

            int remainder[100],count= 0;                           //count��¼suffix����26�Ĵ���,remainder��¼ÿ�γ���֮������
            memset(remainder,0,sizeof(remainder));

            do{                                                    //do-whileѭ��,����ִ��һ��,������ĵ�Ԫ�����ǳ���26�е����
                if(suffixNumber%26==0){                            //�����������Ϊ0�����
                    remainder[count++]=26;                         //˵����ǰ�����ַ������26��,��Z
                    suffixNumber = (suffixNumber-1)/26;            //����֮�����������һλ����ǰ,suffixNumber�����һ
                }else{
                    remainder[count++]=suffixNumber%26;            //���������Ϊ0,�򱣴�����,��Ϊÿһλ������Ϊ�����ַ����ĸ
                    suffixNumber = suffixNumber/26;                //ȡ��,���λ
                }
            }while(suffixNumber>26);                               //ֻҪRC��ַ�ĵڼ��д���26,��ʾ�����Խ�λ

            for(char k='A';k<='Z';k++){
                if(k-'A'==(suffixNumber-1)){
                    cout<<k;
                    break;
                }
            }

            for(int j=count-1;j>=0;j--){
                for(char k='A';k<='Z';k++){
                    if(k-'A'==(remainder[j]-1)){                   //��Ϊ��26�е�Ԫ������,���Կ���ֱ�ӽ������滻��Ӣ����ĸ
                        cout<<k;
                        break;
                    }
                }
            }
            cout<<PreNumber<<endl;                                 //����ڼ���
        }else{                                                     //����ִ�дӳ����ַ��RC��ַ��ת��
            int j=0,k=0;                                           //j�����ַ��ĸ�ĸ���,k��¼�����ַ���ֵĸ���
            for(i=0;i<strlen(str);i++){
                if(str[i]>='A'&&str[i]<='Z'){
                    number3[j++]=str[i];
                }
                else{
                    number4[k++]=str[i];
                }
            }
            int GerneralRow=0;                                    //��¼�����ʽ�ڼ���,����ͷ����ĸ,k������
            k=0;
            for(i=j-1;i>=0;i--){                                  //�ӿ�ͷ����ĸ��ǰѭ��ת��Ϊ����
                GerneralRow += (number3[i]-'A'+1)*pow(26,k++);
            }
            cout<<"R"<<number4<<"C"<<GerneralRow<<endl;
        }
    }
    return 0;
}










