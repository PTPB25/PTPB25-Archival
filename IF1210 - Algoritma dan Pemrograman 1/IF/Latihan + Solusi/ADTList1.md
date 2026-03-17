# Soal
## 1
Apakah perlu perubahan definisi tipe bentukan List dari alt-1a ke alt-1b dan dari alt-2a ke alt-2b? Jika ya, tuliskan perubahannya.
## 2
Buatlah realisasi operasi-operasi berikut untuk alt-1b atau alt-2b: <br>
length <br>
insertAt <br>
indexOf <br>
concat <br>
# Solusi
<p style="margin-top: -10px; font-size: 0.9em;">
  credit: Shui
</p>
## 1
<p align="justify">
alt-1a ke alt-1b
Tidak perlu, karena elemen pada alt-1b dapat dicek apakah elemen tersebut elemen efektif atau tidak dengan membandingkannya dengan MARK. Jika sama dengan MARK, maka elemen tersebut tidak efektif. Sebaliknya, jika tidak sama dengan MARK, elemen tersebut bersifat efektif. Dengan cara tersebut, elemen efektif pada tipe bentukan List dapat ditentukan tanpa memerlukan informasi tambahan pada komponen tipe bentukan, sehingga tidak perlu ada perubahan antara perubahan dari tipe bentukan List alt-1a ke alt-1b.
</p>
<p align="justify">
alt-2a ke alt-2b
Perlu, karena elemen pada alt-2b harus secara eksplisit ditentukan mana yang efektif dan mana yang tidak. Berbeda dengan alt-1b yang dapat mengecek keefektifan elemen dengan membandingkannya dengan MARK, List versi alt-2b tidak memiliki definisi MARK untuk mengecek keefektifan elemen. Karena itu, tipe bentukan List harus secara eksplisit memberi tahu di mana elemen efektif dalam List berada. Salah satu cara untuk menyatakan hal itu adalah dengan menambahkan komponen firstIndex yang menyatakan indeks pertama (terkecil) yang elemennya merupakan elemen efektif. Karena sudah ada komponen nEff sebelumnya, semua elemen efektif pada List dapat diketahui, yaitu dari firstIndex sampai firstIndex + nEff - 1. Berikut adalah perubahan yang perlu dilakukan.
</p>

**Awal (alt-2a):**
```
type List: < contents: array [0..CAPACITY-1] of ElType { penyimpanan elemen list }
nEff: integer ≥ 0 { jumlah elemen efektif list } >
```
**Menjadi (alt-2b):**
```
type List: < contents: array [0..CAPACITY-1] of ElType { penyimpanan elemen list }
nEff: integer ≥ 0 { jumlah elemen efektif list }
firstIndex: integer { indeks pertama yang merupakan elemen efektif } >
```
## 2
### alt 1b
```
function length(l: List) -> integer
{ Prekondisi: l terdefinisi }
{ mengembalikan banyak elemen efektif l, 0 jika kosong }
KAMUS LOKAL
count, indeksAwal, indeks: integer
ALGORITMA
count <- 0
indeksAwal <- 0
while (l.contents[indeksAwal] = MARK and indeksAwal < CAPACITY) do
		indeksAwal <- indeksAwal + 1
{ l.contents[indeksAwal] != MARK (terdapat elemen bukan MARK) or indeksAwal = CAPACITY (semua elemen adalah MARK) }
indeks <- indeksAwal
while (l.contents[indeks] != MARK and indeks < CAPACITY) do
		count <- count + 1
		indeks <- indeks + 1
{ l.contents[indeks] = MARK or indeks = CAPACITY }
-> count
```
```
procedure insertAt(input/output l: List, input x: ElType, input idx: integer)
{ memasukkan nilai x pada list l di index tertentu }
{ I.S. l, x, dan idx terdefinisi, l terisi. idx valid pada l}
{ F.S. l.contents[idx] = x tanpa menghilangkan elemen lain di l }
KAMUS LOKAL
i, indeksAwal, indeksAkhir: integer
ALGORITMA
if length(l) < CAPACITY then
while (l.contents[indeksAwal] = MARK) do
indeksAwal <- indeksAwal + 1
{ l.contents[indeksAwal] != MARK (ketemu elemen pertama bukan MARK) }
if idx = 0 and indeksAwal != 0 then
l.contents[indeksAwal-1] <- x
else
		indeksAkhir <- indeksAwal
while l.contents[indeksAkhir+1] != MARK do
		indeksAkhir <- indeksAkhir + 1
	if indeksAkhir < CAPACITY - 1 then
		i <- indeksAkhir
while i >= idx do
			l.contents[i+1] <- l.contents[i]
			i <- i – 1
		{ i < idx }
			else
				i <- indeksAwal
				while i <= idx do
					l.contents[i-1] <- l.contents[i]
					i <- i + 1
				{ i < idx }
l.contents[idx] <- x
```
```
function indexOf(l: List, x: ElType) -> integer
{ Prekondisi: l dan x terdefinisi }
{ Mengembalikan indeks elemen pertama l yang bernilai x jika ada atau mengembalikan IDX_UNDEF jika tidak ada }
KAMUS LOKAL
	i: integer
ALGORITMA
	i <- 0
	while l.contents[i] != x and i < CAPACITY do
		i <- i + 1
	{ l.contents[i] = x (x ditemukan di list) or i = CAPACITY (x tidak ditemukan) }
	if i = CAPACITY then
		-> IDX_UNDEF
	else
		-> i
```
```
function concat(l1, l2: List) -> List
{ Prekondisi: l1 dan l2 terdefinisi, mungkin kosong }
{ Mengembalikan hasil konkatenasi (menyambung) dua buah list, l2 ditaruh di belakang l1 }
KAMUS LOKAL
	i, idx, idxToInput: integer
ALGORITMA
	i traversal [0..CAPACITY-1]
		l.contents[i] = MARK
	idxToInput <- 0
	if length(l1) != 0 then
		idx <- 0
	while (l1.contents[idx] = MARK) do
			idx <- idx + 1
{ l1.contents[idx] != MARK (ketemu elemen pertama bukan MARK) }
while (l1.contents[idx] != MARK and idx < CAPACITY and idxToInput < CAPACITY) do
			l1.contents[idxToInput] <- l1.contents[idx]
			idxToInput <- idxToInput + 1
idx <- idx + 1
{ l1.contents[indeks] = MARK or idx = CAPACITY or idxToInput = CAPACITY }
	if length(l2) != 0 then
		idx <- 0
	while (l2.contents[idx] = MARK) do
			idx <- idx + 1
{ l2.contents[idx] != MARK (ketemu elemen pertama bukan MARK) }
while (l2.contents[idx] != MARK and idx < CAPACITY and idxToInput < CAPACITY) do
			l2.contents[idxToInput] <- l2.contents[idx]
			idxToInput <- idxToInput + 1
idx <- idx + 1
{ l2.contents[idx] = MARK or idx = CAPACITY or idxToInput = CAPACITY }
	-> l
```
### alt 2b
```
function length(l: List) -> integer
{ Prekondisi: l terdefinisi }
{ mengembalikan banyak elemen efektif l, 0 jika kosong }
KAMUS LOKAL
ALGORITMA
-> nEff
```
```
procedure insertAt(input/output l: List, input x: ElType, input idx: integer)
{ memasukkan nilai x pada list l di index tertentu }
{ I.S. l, x, dan idx terdefinisi, l terisi. idx valid pada l}
{ F.S. l.contents[idx] = x tanpa menghilangkan elemen lain di l }
KAMUS LOKAL
i: integer
ALGORITMA
if length(l) < CAPACITY then
if idx = 0 and l.firstIndex != 0 then
l.contents[l.firstIndex-1] <- x
l.firstIndex <- l.firstIndex - 1
else
	if l.firstIndex + l.nEff < CAPACITY then
		i <- l.firstIndex + l.nEff – 1
		while i <= idx do
	l.contents[i+1] <- l.contents[i]
	i <- i - 1
			else
		i <- l.firstIndex + l.nEff – 1
		while i <= idx do
	l.contents[i+1] <- l.contents[i]
	i <- i - 1
				l.firstIndex <- l.firstIndex - 1
			l.contents[idx] <- x
		l.nEff <- l.nEff + 1
```
```
function indexOf(l: List, x: ElType) -> integer
{ Prekondisi: l dan x terdefinisi }
{ Mengembalikan indeks elemen pertama l yang bernilai x jika ada atau mengembalikan IDX_UNDEF jika tidak ada }
KAMUS LOKAL
	i: integer
ALGORITMA
	i <- firstIndex
	while l.contents[i] != x and i < l.firstIndex + l.nEff do
		i <- i + 1
	{ l.contents[i] = x (x ditemukan di list pada indeks i) or i = l.firstIndex + l.nEff (x tidak ditemukan) }
	if i = l.firstIndex + l.nEff then
		-> IDX_UNDEF
	else
		-> i
```
```
function concat(l1, l2: List) -> List
{ Prekondisi: l1 dan l2 terdefinisi, mungkin kosong }
{ Mengembalikan hasil konkatenasi (menyambung) dua buah list, l2 ditaruh di belakang l1 }
KAMUS LOKAL
	i, idx, idxToInput: integer
	l: List
ALGORITMA
	i traversal [0..CAPACITY-1]
		l.contents[i] = MARK
	idxToInput <- 0
	if length(l1) != 0 then
		idx <- l1.firstIndex
while (l1.contents[idx] != MARK and idx < l1.firstIndex + l1.nEff and idxToInput < CAPACITY) do
			l.contents[idxToInput] <- l1.contents[idx]
			idxToInput <- idxToInput + 1
idx <- idx + 1
{ l.contents[idx] = MARK or idx = l1.firstIndex + l1.nEff or idxToInput = CAPACITY }
	if length(l2) != 0 then
		idx <- l2.firstIndex
while (l2.contents[idx] != MARK and idx < l2.firstIndex + l2.nEff and idxToInput < CAPACITY) do
			l.contents[idxToInput] <- l2.contents[idx]
			idxToInput <- idxToInput + 1
idx <- idx + 1
{ l.contents[indeks] = MARK or indeks = l2.firstIndex + l2.nEff or idxToInput = CAPACITY }
	-> l
```