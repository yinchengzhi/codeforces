
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
bool kind_RxCx(char*ch,int len){                                   //判断地址是否是RC地址类型
    if(ch[0]=='R'&&ch[1]>='0'&&ch[1]<='9')                         //利用第一个字符是R和第二个字符是数字，还有后面的字符存在C的情况
        for(int i=0;i<len;i++)
            if(ch[i]=='C') return 1;
    return 0;
}


int main(){
    int n;
    char str[100];
    char number1[64];                                              //用于RC地址记录第几行
    char number2[64];                                              //用于RC地址记录第几列
    char number3[64];                                              //用于常规地址记录前面字母
    char number4[64];                                              //用于常规地址记录第几行
    cin>>n;
    while(n--){
        memset(str,0,sizeof(str));
        memset(number1,0,sizeof(number1));
        memset(number2,0,sizeof(number2));
        memset(number3,0,sizeof(number3));
        memset(number4,0,sizeof(number4));
        int i=0;
        cin>>str;
        if(kind_RxCx(str,strlen(str))){                            //如果判定为RC地址则执行从RC地址到常规地址的转换
            for(i=1;i<strlen(str);i++){
                if(str[i]>='0'&&str[i]<='9'){
                    number1[i-1]=str[i];
                }else{
                    break;
                }
            }
            int PreNumber = atoi(number1);                         //PreNumber表示RC地址的第几行.
            for(int j=0;i<strlen(str);i++){
                if(str[i]>='0'&&str[i]<='9'){
                    number2[j++]=str[i];
                }
            }
            int suffixNumber = atoi(number2);                      //suffixNumber表示RC地址的第几列.

            int remainder[100],count= 0;                           //count记录suffix整除26的次数,remainder记录每次除完之后余数
            memset(remainder,0,sizeof(remainder));

            do{                                                    //do-while循环,至少执行一回,当输入的单元格数是超过26列的情况
                if(suffixNumber%26==0){                            //如果遇到余数为0的情况
                    remainder[count++]=26;                         //说名当前常规地址满足了26个,即Z
                    suffixNumber = (suffixNumber-1)/26;            //整除之后的数必须留一位给当前,suffixNumber必须减一
                }else{
                    remainder[count++]=suffixNumber%26;            //如果余数不为0,则保存下来,因为每一位的余数为常规地址的字母
                    suffixNumber = suffixNumber/26;                //取整,求进位
                }
            }while(suffixNumber>26);                               //只要RC地址的第几列大于26,表示还可以进位

            for(char k='A';k<='Z';k++){
                if(k-'A'==(suffixNumber-1)){
                    cout<<k;
                    break;
                }
            }

            for(int j=count-1;j>=0;j--){
                for(char k='A';k<='Z';k++){
                    if(k-'A'==(remainder[j]-1)){                   //因为在26列单元格以内,所以可以直接将数字替换成英文字母
                        cout<<k;
                        break;
                    }
                }
            }
            cout<<PreNumber<<endl;                                 //输出第几行
        }else{                                                     //否则执行从常规地址到RC地址的转换
            int j=0,k=0;                                           //j常规地址字母的个数,k记录常规地址数字的个数
            for(i=0;i<strlen(str);i++){
                if(str[i]>='A'&&str[i]<='Z'){
                    number3[j++]=str[i];
                }
                else{
                    number4[k++]=str[i];
                }
            }
            int GerneralRow=0;                                    //记录常规格式第几列,即开头的字母,k计数器
            k=0;
            for(i=j-1;i>=0;i--){                                  //从开头的字母往前循环转换为数字
                GerneralRow += (number3[i]-'A'+1)*pow(26,k++);
            }
            cout<<"R"<<number4<<"C"<<GerneralRow<<endl;
        }
    }
    return 0;
}










