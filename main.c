#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CaeserCipher.h"
#include "PlayFairCipher.h"
#include "VigenereCipher.h"
#include "AutoKeyCipher.h"
#include "errormssge.h"

int main(){
    int a,b;

    printf("\nWhich Cipher do you want to work with?\n[1] Caeser Cipher\n[2] Play Fair Cipher\n[3] Vigenere Cipher\n[4] Auto Key Cipher\nEnter the corresponding number here: ");
    scanf("%d", &a);
    getchar();

    printf("\nWhat do you want to do? Cipher[1] or Decipher[2]? ");
    scanf("%d", &b);
    getchar();

    if(a<=0 || a>4 || b<=0 || b>2){
        error();
    }

    char mssge[100];
    char keyword[20];
    int key;    

    if(b==1){
        printf("\nEnter the plain text (in lowercase only):\n");
    }
    else{
        printf("\nEnter the cipher text (in uppercase only):\n");
    }
    fgets(mssge, sizeof(mssge), stdin);
    mssge[strcspn(mssge, "\n")]='\0';

    if(a==1){
        printf("\nEnter the key:\n");
        scanf("%d", &key);
        getchar();
    }
    else{
        printf("\nEnter the keyword (in lowercase only):\n");
        fgets(keyword, sizeof(keyword), stdin);
        keyword[strcspn(keyword, "\n")]='\0';
    }
    

    if(a==1){
        if(b==1) CaeserCipher(mssge, key); else CaeserDecipher(mssge, key);
    }
    else if(a==2){
        if(b==1) PlayFairCipher(mssge, keyword); else PlayFairDecipher(mssge, keyword);
    }
    else if(a==3){
        if(b==1) VigenereCipher(mssge, keyword); else VigenereDecipher(mssge, keyword);
    }
    else if(a==4){
        if(b==1) AutoKeyCipher(mssge, keyword); else AutoKeyDecipher(mssge, keyword);
    }

    return 0;
}