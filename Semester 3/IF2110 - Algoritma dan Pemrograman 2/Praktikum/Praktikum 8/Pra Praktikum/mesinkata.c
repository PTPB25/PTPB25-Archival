#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    while(currentChar == BLANK) ADV();
}

void STARTWORD(){
    START();
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true;
    }
    else{
        EndWord = false;
        CopyWord();
    }
}


void ADVWORD(){
    CopyWord();
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true;
    }
}

void CopyWord(){
    int i = 0;
    while(currentChar != MARK && currentChar != BLANK){
        if(i < NMax){
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV(); 
    }
    currentWord.Length = i;

}
