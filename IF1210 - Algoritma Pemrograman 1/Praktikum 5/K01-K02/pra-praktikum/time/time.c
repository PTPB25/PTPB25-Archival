
#include "time.h"
#include <stdio.h>
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S){
    return 0 <= H && H <= 23 && 0 <= M && M <= 59 && 0 <= S && S <= 59;
}
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME *T, int HH, int MM, int SS){
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T){
    int h, m, s;
    scanf("%d %d %d", &h, &m, &s);
    while(!IsTIMEValid(h, m, s)){
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &h, &m, &s);
    }
    CreateTime(T, h, m, s);
}
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
   
void TulisTIME (TIME T){
    printf("%d:%d:%d", T.HH, T.MM, T.SS);
}
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T){
    return (long) (3600 * T.HH + 60 * T.MM + T.SS);
}
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

TIME DetikToTIME (long N){
    TIME T;
    const long MAX_SECOND = 24 * 3600;
    N %= MAX_SECOND;

    T.HH = N / 3600;
    N %= 3600;
    T.MM = N / 60;
    N %= 60;
    T.SS = N;
    return T;
}
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2){
    return TIMEToDetik(T1) == TIMEToDetik(T2);
}
/* Mengirimkan true jika T1=T2, false jika tidak */
boolean TNEQ (TIME T1, TIME T2){
    return !TEQ(T1, T2);
}
/* Mengirimkan true jika T1 tidak sama dengan T2 */
boolean TLT (TIME T1, TIME T2){
    return TIMEToDetik(T1) < TIMEToDetik(T2);
}
/* Mengirimkan true jika T1<T2, false jika tidak */
boolean TGT (TIME T1, TIME T2){
    return TIMEToDetik(T1) > TIMEToDetik(T2);
}
/* Mengirimkan true jika T1>T2, false jika tidak */
/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T){
    if(T.SS == 59){
        if(T.MM == 59){
            if(T.HH == 23){
                T.HH = 0; T.MM = 0; T.SS = 0;
            }
            else {T.HH++; T.MM = 0; T.SS = 0;}
        }
        else {T.MM++; T.SS = 0;}
    }
    else T.SS++;
    return T;
}
/* Mengirim 1 detik setelah T dalam bentuk TIME */
TIME NextNDetik (TIME T, int N){
    while(N--)T = NextDetik(T);
    return T;
}
/* Mengirim N detik setelah T dalam bentuk TIME */
TIME PrevDetik (TIME T){
    if(!T.SS){
        if(!T.MM){
            if(!T.HH){
                T.HH = 23; T.MM = 59; T.SS = 59;
            }
            else {T.HH--; T.MM = 59; T.SS = 59;}
        }
        else {T.MM--; T.SS = 59;}
    }
    else T.SS--;

    return T;
}
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
TIME PrevNDetik (TIME T, int N){
    while(N--)T = PrevDetik(T);
    return T;
}
/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh){
    const long MAX_SECOND = 24 * 3600;
    return (TIMEToDetik(TAkh) - TIMEToDetik(TAw) + MAX_SECOND) % MAX_SECOND;
}
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
