#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  

using namespace std;  

const int M = 1000 + 5;  
char str[M][M];  
int  a, b;  

int main()  
{  
    while(scanf("%d%d", &a, &b)!=EOF)  
    {  
        memset(str, 0, sizeof(str));  
        for(int i=1; i<=a; i++)  
            for(int j=1; j<=b; j++)  
                cin>>str[i][j];  
        for(int i=1; i<=a; i++)  
            for(int j=1; j<=b; j++)  
            {  
                if(str[i][j]=='.')  
                {  
                    if((i+j)%2==0)  
                        str[i][j]='B';  
                    else  
                        str[i][j]='W';  
                }  
            }  
        for(int i=1; i<=a; i++)  
        {  
            for(int j=1; j<=b; j++)  
                cout<<str[i][j];  
            cout<<endl;  
        }  
    }  

    return 0;  
}  

