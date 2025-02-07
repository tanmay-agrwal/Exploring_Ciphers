#include <stdio.h>
#include <string.h>
#include "VigenereCipher.h"
#include "errormssge.h"

void VigenereCipher(char *mssge, char *keyword){
    char newMssge[100];

    int i=0;
    for(i=0; mssge[i]!='\0'; i++){

        int j=i%strlen(keyword);

        if(mssge[i]>='a' && mssge[i]<='z' && keyword[j]>='a' && keyword[j]<='z'){
            newMssge[i]=(((mssge[i]-'a')+(keyword[j]-'a'))%26)+'A';
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

void VigenereDecipher(char *mssge, char *keyword){
    char newMssge[100];

    int i=0;
    for(i=0; mssge[i]!='\0'; i++){

        int j=i%strlen(keyword);

        if(mssge[i]>='A' && mssge[i]<='Z' && keyword[j]>='a' && keyword[j]<='z'){
            newMssge[i]=(((mssge[i]-'A')-(keyword[j]-'a')+26)%26)+'a';
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