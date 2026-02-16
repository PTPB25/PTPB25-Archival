#include <stdio.h>
#include <string.h>

int main(){
    char s[1001];
    int freq[26];
    int i, odd, isPalindrome;

    scanf("%s", s);

    for(i=0; i<26; i++){
        freq[i] = 0;
    }

    i = 0;
    while(s[i] != '\0'){
        freq[s[i]-'a']++;
        i++;
    }

    odd = 0;
    isPalindrome = 1;
    for(i=0; i<26; i++){
        if(freq[i] & 1){
            if(odd){
                isPalindrome = 0;
            }
            odd = 1;
        }
    }

    if(isPalindrome){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    return 0;
}