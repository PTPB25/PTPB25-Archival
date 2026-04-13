# Soal

## 1
<p align="justify">
Definisikan struktur data yang merepresentasi Queue bertipe ElType 
yang terdiri atas &lt;id: integer, cost: integer> dalam bentuk 
circular buffer, dengan alokasi statik maksimum 100 elemen, dan 
menyimpan informasi indeks head dan count (banyaknya elemen 
dalam Queue)
</p>

## 2
```
function isFull (q: Queue) → boolean
{mengirim true jika q penuh}
```
## 3
```
procedure enqueue (input/output q: Queue, input val: ElType)
{Proses: menambahkan val pada q sebagai Tail baru}
{I.S.: q mungkin kosong, q tidak penuh}
{F.S.: val menjadi Tail baru dengan mekanisme circular buffer}
```
## 4
```
procedure dequeue (input/output q: Queue, output val: ElType)
{Proses: menyimpan nilai Head q ke val dan menghapus Head q}
{I.S.: q tidak kosong}
{F.S.: val adalah nilai elemen Head, Head “bergerak” dengan mekanisme 
circular buffer. q mungkin kosong}
```
## 5
<p align="justify">
Pandanglah Queue pada soal nomor 1 sebagai antrian pekerjaan 
dengan id adalah nomor identifikasi pekerjaan dan “cost” adalah cost 
waktu penyelesaian pekerjaan (time cost).
</p>
Dengan memanfaatkan queue pada soal nomor 1, buatlah procedure roundRobin yang memproses Queue secara Round Robin, yaitu memroses dengan waktu terbatas T: <br>

1. Jika elemen pada HEAD memiliki cost ≤ T, elemen tersebut dihapus dari 
Queue. 
2. Jika elemen pada HEAD memiliki cost > T, maka elemen tersebut dihapus dari 
Queue dan disisipkan kembali sebagai Tail dengan cost yang berkurang 
sebesar T

```
procedure roundRobin (input/output q: Queue, input t: integer)
{Proses: memproses elemen antrian q secara round robin}
{I.S.: q tidak kosong, t adalah waktu yang tersedia untuk memproses 
setiap elemen}
{F.S.: elemen e pada posisi HEAD dihapus dari q. 
Jika cost e ≤ t maka ditampilkan “<id> telah selesai diproses”. 
Jika cost e > t maka e disisipkan kembali sebagai tail q  
dengan cost berkurang sebesar t }
```

## 6
<p align="justify">
Dengan memodifikasi Queue alternatif 2 pada slide materi kuliah, definisikan (algoritmik) struktur data yang merepresentasi Queue yang menggambarkan antrian pekerjaan (job shop). Setiap elemen 
Queue bertipe ElType yang terdiri atas ⟨id: integer, cost: integer⟩. id menunjukkan nomor identifikasi unik dari pekerjaan yang dikelola Queue, dan elemen Queue terurut membesar berdasarkan “cost” waktu memproses pekerjaan. 
</p>

## 7
```
procedure enqueue (input/output q: Queue, input val: ElType)
{Proses: menambahkan val sebagai elemen baru di q,dengan memperhatikan lamanya waktu pekerjaan tsb dapat diselesaikan, yaitu pekerjaan yang lebih cost diletakkan lebih akhir. Jika ada 2 pekerjaan yang cost waktunya sama, pekerjaan terakhir yang baru datang disisipkan lebih belakang}
{I.S.: q mungkin kosong, q tidak penuh}
{F.S.: val menjadi elemen q yang baru dengan urutan waktu pekerjaan 
membesar}
```
## 8
```
procedure dequeue (input/output q: Queue, output
val: ElType)
{Proses: menyimpan IDX_UNDEFa head q pada val dan menghapus head dari q}
{I.S.: q tidak kosong}
{F.S.: elemen pada HEAD dihapus, dan disimpan nilainya pada val}
```
# Solusi
<p style="margin-top: -10px; font-size: 0.9em;">
  credit: Shui
</p>

## 1
```
constant IDX_UNDEF: integer = -1
constant CAPACITY: integer = 100

type ElType: < id: integer, cost: integer >

{ Queue dengan array statik }
type Queue: 
< buffer  : array [0..CAPACITY-1] of ElType, { penyimpanan elemen }
  idxHead : integer, { indeks elemen terdepan }
  count   : integer { banyak elemen } >
```
## 2
```
function isFull(q: Queue) -> boolean
{ Mengembalikan true jika q penuh }
KAMUS LOKAL
ALGORITMA
	-> q.count = CAPACITY
```
## 3
```
procedure enqueue(input/output q: Queue, input val: ElType)
{ Menambahkan val sebagai elemen Queue q.
I.S. q mungkin kosong, tidak penuh
F.S. q bertambah elemen val pada urutan paling terakhir }
KAMUS LOKAL
	idxTarget: integer
ALGORITMA
	idxTarget <- idxHead+count
	if (idxTarget > CAPACITY-1) then
		idxTarget <- idxTarget – CAPACITY
	q.buffer[idxTarget] <- val
```
## 4
```
procedure dequeue (input/output q: Queue, output val: ElType)
{ Menghapus head dari Queue q.
I.S. q tidak kosong
F.S. val berisi nilai head yang lama.
Jika q tidak menjadi kosong,
q.idxHead berpindah ke elemen berikutnya pada q.
Jika q menjadi kosong,
q.idxHead menjadi bernilai IDX_UNDEF, q.count menjadi 0. }
KAMUS LOKAL
	idxTarget: integer
ALGORITMA
	val <- q.buffer[q.idxHead+count-1]
	if (q.count = 1) then
		q.idxHead <- IDX_UNDEF
		q.count <- 0
	else
		q.idxHead <- q.idxHead + 1
		if (q.idxHead = CAPACITY) then
			q.idxHead <- 0
		q.count <- q.count - 1
```
## 5
```
procedure roundRobin (input/output q: Queue, input t: integer)
{Proses: memproses elemen antrian q secara round robin}
{I.S.: q tidak kosong, t adalah waktu yang tersedia untuk memproses
 setiap elemen}
{F.S.: elemen e pada posisi HEAD dihapus dari q.
Jika cost e ≤ t maka ditampilkan “<id> telah selesai diproses”.
Jika cost e > t maka e disisipkan kembali sebagai tail q
dengan cost berkurang sebesar t }
KAMUS LOKAL
	temp: ElType
ALGORITMA
	dequeue(q, temp)
	if (temp.cost <= t) then
		output(temp.id, ” telah selesai diproses”)
	else
		temp.cost <- temp.cost – 1
		enqueue(q, temp)
```
## 6
```
constant IDX_UNDEF: integer = -1
constant CAPACITY: integer = 100

type ElType: < id: integer, cost: integer >

{ Queue dengan array statik }
type Queue: 
<	buffer: array [0..CAPACITY-1] of ElType, { penyimpanan elemen }
    idxHead: integer, { indeks elemen terdepan }
    idxTail: integer > { indeks elemen terbelakang }
```
## 7
```
procedure enqueue (input/output q: Queue, input val: ElType)
{ Proses: menambahkan val sebagai elemen baru di q, dengan
memperhatikan lamanya waktu pekerjaan tsb dapat
diselesaikan, yaitu pekerjaan yang lebih cost diletakkan
lebih akhir. Jika ada 2 pekerjaan yang cost waktunya sama,
pekerjaan terakhir yang baru datang disisipkan lebih
belakang }
{ I.S.: q mungkin kosong, q tidak penuh }
{ F.S.: val menjadi elemen q yang baru dengan urutan waktu pekerjaan membesar }
KAMUS LOKAL 
	i: integer
	inserted: boolean
ALGORITMA
	if (q.idxTail = CAPACITY-1) then
		i traversal [q.idxHead..q.idxTail]
			q.buffer[i-1] <- q.buffer[i]
		q.idxHead <- q.idxHead-1
		q.idxTail <- q.idxTail-1 
i <- q.idxTail
inserted <- false
	while (i >= q.idxHead and !inserted) do
		if (val.cost < q.buffer[i].cost) then
			q.buffer[i+1] = q.buffer[i]
		else
			q.buffer[i+1] = val
			inserted <- true 
	{ i < q.idxHead (not inserted) or inserted }
if (!inserted) then
	q.buffer[q.idxHead] <- val
	inserted <- true
q.idxTail <- q.idxTail+1
```
## 8
```
procedure dequeue (input/output q: Queue, output val: ElType)
{ Proses: menyimpan IDX_UNDEFa head q pada val dan menghapus head dari q }
{ I.S.: q tidak kosong }
{ F.S.: elemen pada HEAD dihapus, dan disimpan nilainya pada val }
KAMUS LOKAL 
ALGORITMA 
	val <- q.buffer[q.idxHead]
	if (q.idxHead = q.idxTail) then
		q.idxHead = IDX_UNDEF
		q.idxTail = IDX_UNDEF
	else
		q.idxHead <- q.idxHead + 1
```