
#include "matrix.h"

/* For testing*/

int main(){
    Matrix M1, M2;
    Matrix *result;
    ReadMatrix(&M1);
    PrintMatrix(GetTranspose(M1));
    ReadMatrix(&M2);
    result = MultiplyMatrix(M1, M2);
    PrintMatrix(*result);
    return 0;
}