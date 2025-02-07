#include <stdio.h>
#include <string.h>
#include "PlayFairCipher.h"
#include "errormssge.h"

void initialize(pair *alphabet, char matrix[5][5], char *keyword){
    int ptr=0;

    for(int i=0; i<26; i++){
        alphabet[i].row=-1;
        alphabet[i].col=-1;
    }

    for(int i=0; i<strlen(keyword); i++){
        if(keyword[i]>='a' && keyword[i]<='z'){
            if(keyword[i]=='j'){
                keyword[i]='i';
            }
            if(alphabet[keyword[i]-'a'].row==-1 && alphabet[keyword[i]-'a'].col==-1){
                matrix[ptr/5][ptr%5]=keyword[i];
                alphabet[keyword[i]-'a'].row=ptr/5;
                alphabet[keyword[i]-'a'].col=ptr%5;
                ptr++;
            }
        }
        else if(keyword[i]==' '){
            continue;
        }
        else{
            error();
        }
    }
    for(int i=0; i<26; i++){
        if(alphabet[i].row==-1 && alphabet[i].col==-1 && i!='j'-'a'){
            matrix[ptr/5][ptr%5]='a'+i;
            alphabet[i].row=ptr/5;
            alphabet[i].col=ptr%5;
            ptr++;
        }
    }
}

void PlayFairCipher(char *mssge, char *keyword){
    pair alphabet[26];
    char matrix[5][5];
    initialize(alphabet, matrix, keyword);

    char newMssge[100];

    int p=0;
    int ptr1=0;
    int ptr2=1;
    char a,b;

    while(mssge[ptr1]!='\0'){

        if(mssge[ptr1]==' '){
            ptr1++;
            ptr2++;
            continue;
        }
        if(mssge[ptr2]==' '){
            ptr2++;
            continue;
        }
        if(mssge[ptr2]=='\0'){
            mssge[ptr2]='x';
            mssge[ptr2+1]='\0';
        }

        if(mssge[ptr1]=='j'){
            mssge[ptr1]='i';
        }
        if(mssge[ptr2]=='j'){
            mssge[ptr2]='i';
        }

        if(mssge[ptr1]>='a' && mssge[ptr1]<='z' && mssge[ptr2]>='a' && mssge[ptr2]<='z'){
            if(mssge[ptr1]==mssge[ptr2]){
                a=mssge[ptr1];
                b='x';
                ptr1=ptr2;
                ptr2++;
            }
            else{
                a=mssge[ptr1];
                b=mssge[ptr2];
                ptr1=ptr2+1;
                ptr2=ptr1+1;
            }

            if(alphabet[a-'a'].row==alphabet[b-'a'].row){
                newMssge[p++]=matrix[alphabet[a-'a'].row][(alphabet[a-'a'].col+1)%5]-'a'+'A';
                newMssge[p++]=matrix[alphabet[b-'a'].row][(alphabet[b-'a'].col+1)%5]-'a'+'A';
            }
            else if(alphabet[a-'a'].col==alphabet[b-'a'].col){
                newMssge[p++]=matrix[(alphabet[a-'a'].row+1)%5][alphabet[a-'a'].col]-'a'+'A';
                newMssge[p++]=matrix[(alphabet[b-'a'].row+1)%5][alphabet[b-'a'].col]-'a'+'A';
            }
            else{
                newMssge[p++]=matrix[alphabet[a-'a'].row][alphabet[b-'a'].col]-'a'+'A';
                newMssge[p++]=matrix[alphabet[b-'a'].row][alphabet[a-'a'].col]-'a'+'A';
            }
        }
        else{
            error();
        }
    }
    newMssge[p]='\0';

    printf("\nCorresponding ciper text:\n%s\n\n", newMssge);
}

void PlayFairDecipher(char *mssge, char *keyword){
    pair alphabet[26];
    char matrix[5][5];
    initialize(alphabet, matrix, keyword);

    char newMssge[100];

    int p=0;
    int ptr1=0;
    int ptr2=1;
    char a,b;

    while(mssge[ptr1]!='\0'){

        if(mssge[ptr1]==' '){
            ptr1++;
            ptr2++;
            continue;
        }
        if(mssge[ptr2]==' '){
            ptr2++;
            continue;
        }

        if(mssge[ptr1]=='J'){
            mssge[ptr1]='I';
        }
        if(mssge[ptr2]=='J'){
            mssge[ptr2]='I';
        }

        if(mssge[ptr1]>='A' && mssge[ptr1]<='Z' && mssge[ptr2]>='A' && mssge[ptr2]<='Z'){
            a=mssge[ptr1];
            b=mssge[ptr2];
            ptr1=ptr2+1;
            ptr2=ptr1+1;

            if(alphabet[a-'A'].row==alphabet[b-'A'].row){
                newMssge[p++]=matrix[alphabet[a-'A'].row][(alphabet[a-'A'].col-1+5)%5];
                newMssge[p++]=matrix[alphabet[b-'A'].row][(alphabet[b-'A'].col-1+5)%5];
            }
            else if(alphabet[a-'A'].col==alphabet[b-'A'].col){
                newMssge[p++]=matrix[(alphabet[a-'A'].row-1+5)%5][alphabet[a-'A'].col];
                newMssge[p++]=matrix[(alphabet[b-'A'].row-1+5)%5][alphabet[b-'A'].col];
            }
            else{
                newMssge[p++]=matrix[alphabet[a-'A'].row][alphabet[b-'A'].col];
                newMssge[p++]=matrix[alphabet[b-'A'].row][alphabet[a-'A'].col];
            }
        }
        else{
            error();
        }
    }
    newMssge[p]='\0';

    printf("\nCorresponding plain text:\n%s\n\n", newMssge);
}