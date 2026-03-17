# Soal
## 1
```
procedure readMatrix (output m: Matrix)
{ I.S. sembarang } 
{ F.S. Ukuran efektif dan semua elemen m terdefinisi }
{ Proses: Membaca masukan ukuran baris dan kolom efektif 
dari keyboard dan melakukan CreateMatrix dan 
mengisi nilai efektifnya. 
Mengisi elemen m dengan pembacaan dari keyboard secara 
secara traversal per baris. }
```
## 2
```
function isMatrixEqual(m1,m2: Matrix) → boolean
{ Mengirimkan true jika m1 = m2, yaitu ukuran efektif m1 dan m2 sama dan 
untuk setiap i,j yang merupakan indeks baris dan kolom, m1[i,j]=m2[i,j] }
```
## 3
```
function isSparse (m: Matrix) → boolean
{ Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan
definisi: hanya maksimal 5% dari memori matriks yang efektif bukan 
bernilai 0 }
```
## 4
```
function transpose (m: Matrix) → Matrix
{ Menghasilkan transpose dari m yaitu setiap elemen m[i,j] ditukar 
nilainya dengan elemen m[j,i] }
```
## 5

Jika definisi ADT Matriks diubah: bahwa matriks selalu dimulai dari “ujung kiri atas” dihapus, tetapi dapat dimulai dari sel mana pun.

Perubahan apa yang harus dilakukan pada definisi struktur data ADT 
Matriks? 

# Solusi
<p style="margin-top: -10px; font-size: 0.9em;">
  credit: Shui
</p>

## 1
```
procedure readMatrix (output m: Matrix)
{ I.S. sembarang }
{ F.S. Ukuran efektif dan semua elemen m terdefinisi }
{ Proses: Membaca masukan ukuran baris dan kolom efektif dari keyboard dan melakukan CreateMatrix dan mengisi nilai efektifnya. Mengisi elemen m dengan pembacaan dari keyboard secara traversal per baris. }
KAMUS LOKAL
    i, j, rowEff, colEff: integer
    masukan: ElType
ALGORITMA
    input(rowEff, colEff)
    CreateMatrix(m, rowEff, colEff)
    i traversal [0..rowEff-1]
		j traversal [0..colEff-1]
			input(masukan)
			setElmt(m, i, j, masukan)
```
## 2
```
function isMatrixEqual(m1,m2: Matrix) → boolean
{ Mengirimkan true jika m1 = m2, yaitu ukuran efektif m1 dan m2 sama dan untuk setiap i,j yang merupakan indeks baris dan kolom, m1[i,j]=m2[i,j] }
KAMUS LOKAL
    result: boolean
    i, j: integer
ALGORITMA
    if (m1.rowEff != m2.rowEff or m1.colEff != m2.colEff) then
		-> false
    else
		result <- true
		i <- 0
		j <- 0
		while (i < m1.rowEff && result) do
			while (j < m1.colEff && result) do
				if (getElmt(m1, i, j) != getElmt(m2, i, j)) then
					result <- false
				j <- j + 1
			{ j=m1.colEff (satu baris sama) or result=false (ditemukan perbedaan) }
			i <- i + 1
		{ i=m1.rowEff (semua sama) or result=false (ditemukan perbedaan) }
	-> result
```
## 3
```
function isSparse (m: Matrix) → boolean
{ Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 }
KAMUS LOKAL
	i, j, count, batasSparse: integer
	result: boolean
ALGORITMA
	count <- 0
	i <- 0
	j <- 0
	result <- true
	batasSparse <- m.rowEff*m.colEff*5 div 100
	while (result and i < m.rowEff) do
		while (result and j < m.colEff) do
			if (getElmt(m, i, j) != 0) then
				count <- count+1
			if (count > batasSparse) then
				result <- false
			j <- j+1
		{ result = false or j = m.colEff }
		i <- i+1
	{ result = false or i = m.rowEff }
	-> result
```
## 4
```
function transpose (m: Matrix) → Matrix
{ Menghasilkan transpose dari m yaitu setiap elemen m[i,j] ditukar nilainya dengan elemen m[j,i] }
KAMUS LOKAL
	i, j: integer
	mOut: Matrix
ALGORITMA
	CreateMatrix(mOut, m.colEff, m.rowEff)
	j traversal [0..m.rowEff]
		i traversal [0..m.colEff]
			setElmt(mOut, j, i, getElmt(m, i, j))
	-> mOut
```
## 5
<p align="justify">
Perubahan yang perlu dilakukan adalah menambahkan komponen untuk memberikan informasi secara eksplisit di mana indeks kolom efektif dimulai dan berakhir serta di mana indeks baris efektif dimulai dan berakhir. Dengan tambahan 4 komponen tersebut, komponen rowEff dan colEff tidak diperlukan lagi. Berikut perubahan yang perlu dilakukan.
</p>

```
{ Ukuran maksimum baris dan kolom }
constant ROW_CAP: integer = 100
constant COL_CAP: integer = 100
{ Definisi Type Matrix dengan indeks integer }
type ElType: integer
type Matrix:
<	mem: matrix[0..ROW_CAP-1,0..COL_CAP-1] of ElType,
	rowStart: integer, { indeks pertama sebuah baris efektif }	
rowEnd: integer, { indeks terakhir sebuah baris efektif }
colStart: integer, { indeks pertama sebuah kolom efektif }
colEnd: integer { indeks terakhir sebuah kolom efektif }	
```
