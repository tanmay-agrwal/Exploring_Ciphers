#include <stdio.h>
#include "CaeserCipher.h"
#include "errormssge.h"

void CaeserCipher(char *mssge, int key){
    char newMssge[100];

    int i=0;
    for(i=0; mssge[i]!='\0'; i++){
        if(mssge[i]>='a' && mssge[i]<='z'){
            newMssge[i]=((mssge[i]-'a'+key)%26)+'A';
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

void CaeserDecipher(char *mssge, int key){
    char newMssge[100];

    int i=0;
    for(i=0; mssge[i]!='\0'; i++){
        if(mssge[i]>='A' && mssge[i]<='Z'){
            newMssge[i]=((mssge[i]-'A'-key+26)%26)+'a';
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