
#include "matrix.h"

/* Konstruktor */
void CreateMatrix(int rows, int cols, Matrix *M){
    int i, j;

    M->rows = rows;
    M->cols = cols;
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            M->data[i][j] = 0.0;
        }
    }
}
/* I.S. rows dan cols terdefinisi dan valid (1 <= rows,cols <= MAX) */
/* F.S. Terbentuk matrix M dengan ukuran rows x cols */
/* Semua elemen diinisialisasi dengan 0.0 */

/* Selector */
int GetRows(Matrix M){
    return M.rows;
}
/* Mengembalikan jumlah baris matrix M */

int GetCols(Matrix M){
    return M.cols;
}
/* Mengembalikan jumlah kolom matrix M */

float *GetElement(Matrix *M, int row, int col){
    if(row < 0 || col < 0 || row >= GetRows(*M) || col >= GetCols(*M))return NULL;
    return &(M->data[row][col]);
}
/* Mengembalikan pointer ke elemen matrix M pada baris row dan kolom col */
/* Mengembalikan NULL jika row atau col tidak valid untuk matrix M */

/* Mutator */
bool SetElement(Matrix *M, int row, int col, float value){
    if(row < 0 || col < 0 || row >= GetRows(*M) || col >= GetCols(*M))return false;
    M->data[row][col] = value;
    return true;
}
/* I.S. M terdefinisi */
/* F.S. Jika row dan col valid, elemen M pada baris row dan kolom col bernilai value, mengembalikan true */
/*      Jika row atau col tidak valid, mengembalikan false */

/* Operasi Baca/Tulis */
void ReadMatrix(Matrix *M){
    int row, col;
    scanf("%d %d", &row, &col);
    while(row <= 0 || row >= MAX_ROWS || col <= 0 || col >= MAX_COLS){
        scanf("%d %d", &row, &col);
    }

    CreateMatrix(row, col, M);
    int i, j;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            scanf("%f", &(M->data[i][j]));
        }
    }
}
/* I.S. M belum terdefinisi */
/* F.S. M terdefinisi dan diisi dengan nilai-nilai yang dibaca dari input */
/*      Meminta input ukuran matrix (rows, cols) hingga valid
        Valid: 0 < rows < MAX_ROWS and 0 < cols < MAX_COLS */
/*      Meminta input elemen matrix M sebanyak rows * cols 
        Format input: Setiap elemen dipisahkan oleh spasi
        Contoh input: 
        2 3
        1.0 2.0 3.0
        4.0 5.0 6.0
        Contoh input tidak valid:
        -1 -1
        2 3
        1.0 2.0 3.0
        4.0 5.0 6.0
*/

void PrintMatrix(Matrix M){
    int i, j;
    for(i=0; i < GetRows(M); i++){
        for(j=0; j < GetCols(M); j++){
            printf("%.2f ", M.data[i][j]);       /* Asprak Crime part 2 : kalo dikasih extra space baru bisa dapat 100 */
        }
        printf("\n");
    }
}
/* I.S. M terdefinisi */
/* F.S. Seluruh elemen M tertulis ke layar dalam format matrix */
/* Baris dipisahkan oleh newline, kolom dipisahkan oleh spasi */
/* Format output: Setiap elemen diformat "%.2f" */

/* Operator Relasional */
bool IsSquare(Matrix M){
    return GetRows(M) == GetCols(M);
}
/* Mengembalikan true jika M adalah matrix persegi (rows = cols) */

bool IsSymmetric(Matrix M){
    int i, j;
    for(i=0; i<GetRows(M); i++){
        for(j=0; j<GetCols(M); j++){
            if(M.data[i][j] != M.data[j][i]) return false;
        }
    }
    return true;
}
/* Mengembalikan true jika M adalah matrix simetrik terhadap diagonal */
/* Matrix simetrik adalah matrix yang memiliki elemen tercermin oleh diagonal*/
/* Prekondisi: M adalah matrix persegi */

bool IsDiagonallyDominant(Matrix M){
    int i, j;
    for(i=0; i<GetRows(M); i++){
        float sum = 0;
        for(j=0; j<GetCols(M); j++){
            if(i != j){
                sum += M.data[i][j];
            }
        }
        if(fabsf(M.data[i][i]) <= sum) return false;
    }
    return true;
}
/* Mengembalikan true jika M adalah matrix diagonal dominant */
/* |a[i][i]| > sum(|a[i][j]|) untuk j != i pada setiap baris i */
/* Hint: Gunakan fabs untuk melakukan abs terhadap float */

/* Operator Aritmatika */
Matrix *MultiplyMatrix(Matrix M1, Matrix M2){
    if(M1.cols != M2.rows)return NULL;
    Matrix *result = (Matrix *) malloc(sizeof(Matrix));
    result->rows = M1.rows;
    result->cols = M2.cols;

    int i, j, k;
    float sum = 0;
    
    for(i=0; i<M1.rows; i++){
        for(j=0; j<M2.cols; j++){

            result->data[i][j] = 0;
            for(k=0; k<M1.cols; k++){
                result->data[i][j] += M1.data[i][k] * M2.data[k][j];
            }
            
        }
    }
    return result;
}
/* Menghasilkan hasil perkalian matrix M1 dan M2 */
/* Mengembalikan NULL jika jumlah kolom M1 != jumlah baris M2 */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix *AddMatrix(Matrix M1, Matrix M2){
    if(M1.rows != M2.rows || M1.cols != M2.cols)return NULL;

    int i, j;
    Matrix *result = (Matrix *) malloc(sizeof(Matrix));
    
    result->rows = M1.rows;
    result->cols = M1.cols;

    for(i=0; i<M1.rows; i++){
        for(j=0; j<M1.cols; j++){
            result->data[i][j] = M1.data[i][j] + M2.data[i][j];
        }
    }
    return result;
}
/* Menghasilkan hasil penjumlahan matrix M1 dan M2 */
/* Mengembalikan NULL jika ukuran matrix M1 dan M2 berbeda */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix *SubtractMatrix(Matrix M1, Matrix M2){
    if(M1.rows != M2.rows || M1.cols != M2.cols)return NULL;

    int i, j;
    Matrix *result = (Matrix *) malloc(sizeof(Matrix));

    result->rows = M1.rows;
    result->cols = M1.cols;

    for(i=0; i<M1.rows; i++){
        for(j=0; j<M1.cols; j++){
            result->data[i][j] = M1.data[i][j] - M2.data[i][j];
        }
    }

    return result;
}
/* Menghasilkan hasil pengurangan matrix M1 dan M2 (M1 - M2) */
/* Mengembalikan NULL jika ukuran matrix M1 dan M2 berbeda */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix MultiplyScalar(Matrix M, float scalar){
    int i, j;
    Matrix result;
    result.rows = GetRows(M);
    result.cols = GetCols(M);

    for(i=0; i<GetRows(M); i++){
        for(j=0; j<GetCols(M); j++){
            result.data[i][j] = M.data[i][j] * scalar;
        }
    }

    return result;
}
/* Menghasilkan hasil perkalian matrix M dengan skalar scalar */
/* Prekondisi: M terdefinisi dan skalar terdefinisi */
/* Hint: Buat matrix baru untuk menyimpan hasil */

Matrix GetTranspose(Matrix M){
    int i, j;
    Matrix result;

    result.rows = GetCols(M);
    result.cols = GetRows(M);

    for(i=0; i<GetCols(M); i++){
        for(j=0; j<GetRows(M); j++){
            result.data[i][j] = M.data[j][i];
        }
    }
    
    return result;
}
/* Menghasilkan matrix transpose dari M */
/* Hint: Buat matrix baru untuk menyimpan hasil */
