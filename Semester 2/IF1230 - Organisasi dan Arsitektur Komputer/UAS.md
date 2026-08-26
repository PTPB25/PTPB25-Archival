# UAS IF1230 II - Organisasi dan Arsitektur Komputer 2024/2025

### __CACHE__
---
Suatu program komputer digunakan untuk menjumlahkan total nilai dalam array dua dimensi
**Lengkapi kode berikut agar memanfaatkan prinsip locality dalam penggunaan cache untuk mempercepat pembacaan ke memori**
```c
int main(){
    int N = 2;
    int M = 5;
    short data[N][M]; // asumsi array sudah terisi
    short total = 0;
    for(int b = 0; b < ___; b++){
        for(int a = 0; a < ___; a++){
            short tambah = ________;
            total += tambah;
        }
    }
}
```
---
Tentukan baris mana dari kode di bawah yang memanfaatkan **temporal locality dan spatial locality**


---

Diketahui komputer memiliki memori berukuran 64 Byte. Komputer tersebut memiliki two way set associative cache dengan ukuran per blok 8 Byte dan dua buah set. Aturan penggantian dengan Least Recently Used (LRU). Jika array data bertipe short (2 Byte) dimulai pada alamat desimal 10 di memori, **lengkapi tabel berikut berdasarkan akses array pada line ke-8**

| No | Elemen | Alamat (des) | Alamat (biner) | Offset | Set Index | Tag | Hit/Miss | Lokasi M disimpan (desimal) |
|:--:|:------:|:------------:|:--------------:|:------:|:---------:|:---:|:--------:|:-----------------:|
| 1 |        |              |              |        |           |     |          |                   |
| 2 |        |              |              |        |           |     |          |                   |
| 3 |        |              |              |        |           |     |          |                   |
| 4 |        |              |              |        |           |     |          |                   |
| 5 |        |              |              |        |           |     |          |                   |
| 6 |        |              |              |        |           |     |          |                   |
7 |        |              |              |        |           |     |          |                   |
8 |        |              |              |        |           |     |          |                   |
9 |        |              |              |        |           |     |          |                   |
10 |        |              |              |        |           |     |          |                   |
---
**Gambarkan kondisi akhir cache setelah seluruh array data pada pembacaan baris 8 dieksekusi**
| Set | Valid | Tag | Lokasi M (decimal) |
|:---:|:-----:|:---:|:------------------:|
|  _  |       |     |                    |
|  _  |       |     |                    |
|  _  |       |     |                    |
|  _  |       |     |                    |
---
### __STACK__

Berikut adalah fungsi dalam C
```c
int read1 (void){
    int a, b;
    scanf("%x, %x", &a, &b);
    return a + b;
}
```
    
Kode C tersebut menghasilkan kode assembly sebagai berikut.

```assembly
read:
    pushl   %ebp
    movl    %esp,       %ebp
    subl    $40,        %esp
    leal    -4(%ebp),   %eax
    movl    %eax,       8(%esp)
    leal    -8(%ebp),   %eax
    movl    %eax,       4(%esp)
    movl    $.LCO,      (%esp)
    call    scanf
    movl    -4(%ebp),   %eax
    addl    -8(%ebp),   %eax
    leave
    ret
```

Asumsikan bahwa saat prosedur `read1` mulai dieksekusi, nilai register adalah sebagai berikut:

| Register | Nilai |
|:---------|:------|
| %esp | 0x800040 |
| %ebp | 0x800060 |

Fungsi `read1` memanggil `scanf` (baris 10), dan `scanf` membaca nilai 0x46 dan 0x53 dari input standar. Asumsikan bahwa string "%x %x" disimpan dalam memori dengan lokasi 0x300070.

1. Berapa nilai yang diisikan ke register `%ebp` pada line 3?
2. Berapa nilai yang diisikan ke register `%esp` pada line 4?
3. Pada address/alamat berapa variabel lokal a dan b disimpan?
4. Gambarkan diagram stack grame untuk `read1` sesaat setelah `scanf` return. Lengkapi diagram dengan informasi address dan konten elemen-elemen stack frame.

### __STRUKTUR__
Diberikan struktur data sebagai berikut pada mesin IA32:
```c
struct s1 {
    union u1 a;
    char b[3];
    int c;
};
```
```c
struct s2 {
    char d;
    int e[4];
    struct s1 *f;
    struct s2 *g;
};
```
```c
union u1 {
    char h;
    struct s1 *i;
    struct s2 *j;
};
```
Lengkapilah kode C yang kosong pada pasangan kode assembly - bahasa C di bawah ini

```assembly
proc1:
    pushl   %ebp
    movl    %esp,       %ebp
    movl    8(%ebp),    %eax
    movl    12(%eax),   %eax
    movl    %ebp,       %esp
    popl    %ebp
    ret
```
```c
int proc1(struct s2 *x){
    return ____________;
}
```
---
```assembly
proc2:
    pushl   %ebp
    movl    %esp,       %ebp
    movl    8(%ebp),    %eax
    movl    4(%eax),    %eax
    movl    20(%eax),   %eax
    movl    %ebp,       %esp
    popl    %ebp
    ret
```
```c
int proc2(struct s1 *x){
    return ____________;
}
```