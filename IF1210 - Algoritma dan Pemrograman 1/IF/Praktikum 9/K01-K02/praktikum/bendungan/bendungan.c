#include <stdio.h>
#include <stdlib.h>
#include "../stack.h"

int main(){
    int n, val, top, pivot, idx;
    int l, r;
    int ans = 0;
    scanf("%d", &n);
    if(n == 0){
        printf("%d\n", 0);
        return 0;
    }
    
    Stack stack, temp;
    CreateEmpty(&stack);
    CreateEmpty(&temp);

    /* Make a block to be a pivot, starting from most left, if there is a higher block, then calcualte result and make the higher block the new pivot */

    scanf("%d", &val);
    pivot = val;
    Push(&stack, pivot);

    l = 0;

    for(int i = 1; i < n; i++){
        scanf("%d", &val);
        r = i;
        if(pivot <= val){
            ans += pivot * (r - l - 1);
            while(!IsEmpty(stack)){
                Pop(&stack, &top);
                ans -= top;
            }
            ans += pivot;
            pivot = val;
            l = i;
        }
        Push(&stack, val);
    }

    /* If there is residue, redo similar procedure, use 'idx' to simulate indexing as if we are going from the left again */
    if(!IsEmpty(stack)){
        
        idx = 0;

        Pop(&stack, &pivot);
        l = idx;

        while(!IsEmpty(stack)){
            idx++;

            Pop(&stack, &val);
            r = idx;

            if(val >= pivot){
                ans += pivot * (r - l - 1);
                while(!IsEmpty(temp)){
                    Pop(&temp, &top);
                    ans -= top;
                }
                pivot = val;
                l = idx;
            }
            else{
                Push(&temp, val);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}