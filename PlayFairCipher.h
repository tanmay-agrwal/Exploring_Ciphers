#ifndef PLAYFAIRCIPHER_H
#define PLAYFAIRCIPHER_H

typedef struct pair{
    int row;
    int col;
}pair;

void initialize(pair *alphabet, char matrix[5][5], char *keyword);
void PlayFairCipher(char *mssge, char *keyword);
void PlayFairDecipher(char *mssge, char *keyword);

#endif