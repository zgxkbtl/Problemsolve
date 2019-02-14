#include<bits/stdc++.h>
using namespace std;
char org[202];
int ocr[202]={0};
int main()
{
    scanf("%s",org);
    ocr['J']=1;
    for(int i=1;i<=strlen(org);i++)
    {
        if(org[i]=='J') 
            org[i]='I';
    }
    for(int i=1;i<=25;i++)
    {
        int pos=0;
        while(pos<strlen(org))
        {
            if(ocr[org[pos]]==0) 
            {
                printf("%c",org[pos]);
                if(i%5==0) printf("\n");
                i++;
                ocr[org[pos]]=1;
            }      
            pos++;
        }
        for(int j='A';j<='Z';j++)
        {
            if(ocr[j]==0)
            {
                printf("%c",j);
                if(i%5==0) printf("\n");
                i++;
            }
        }
    }
}