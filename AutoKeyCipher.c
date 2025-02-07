#include <stdio.h>
#include <string.h>
#include "AutoKeyCipher.h"
#include "errormssge.h"

void AutoKeyCipher(char *mssge, char *keyword){
    char newMssge[100];
    char key[100]={'\0'};

    strcat(key, keyword);
    strncat(key, mssge, strlen(mssge)-strlen(keyword));

    int i=0;
    for(i=0; mssge[i]!='\0'; i++){

        if(mssge[i]>='a' && mssge[i]<='z' && key[i]>='a' && key[i]<='z'){
            newMssge[i]=(((mssge[i]-'a')+(key[i]-'a'))%26)+'A';
        }
        else if(mssge[i]==' '){
            newMssge[i]=mssge[i];
        }
        else{
            error();
        }
    }
    newMssge[i]='\0';

    printf("\nCorresponding ciper text:\n%s\n\n", newMssge);
}

void AutoKeyDecipher(char *mssge, char *keyword){
    char newMssge[100];
    char key[100]={'\0'};

    strcat(key, keyword);

    int i=0;
    for(i=0; mssge[i]!='\0'; i++){

        if(mssge[i]>='A' && mssge[i]<='Z' && key[i]>='a' && key[i]<='z'){
            newMssge[i]=(((mssge[i]-'A')-(key[i]-'a')+26)%26)+'a';
            key[strlen(key)]=newMssge[i];
            key[strlen(key)+1]='\0';
        }
        else if(mssge[i]==' '){
            newMssge[i]=mssge[i];
        }
        else{
            error();
        }
    }
    newMssge[i]='\0';

    printf("\nCorresponding plain text:\n%s\n\n", newMssge);
}