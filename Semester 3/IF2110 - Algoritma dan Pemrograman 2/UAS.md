# UAS IF2110 - Algoritma dan Pemrograman 2
### *credit to: Acads HMIF*

## List Berkait Rekursif
```haskell
type ElType: integer
type Address: pointer to Node
type Node:< info: ElType, next: Address >
type List : Address {alamat elemen pertama list}

{ *** Selektor *** }
{ jika L: List dan P: address, L untuk mengakses elemen pertama L;
Next(P) untuk mengakses P↑.next; dan Info(P) untuk mengakses P↑.info }


{*** predikat pemeriksaan *** }
function IsEmpty (L: List) → boolean
{ mengirimkan true jika list kosong, false jika tidak kosong }

function IsOneElmt (L: List) → boolean
{ mengirimkan true jika list hanya berisi satu elemen, false jika tidak }

function head(L: List) → ElType
{ mengirimkan elemen pertama sebuah list l yang tidak kosong }

function tail(l: List) → List 
{ mengirimkan list l tanpa elemen pertamanya, mungkin yang dikirimkan adalah sebuah list kosong }

function konso(e: ElType, l: List) → List 
{ mengirimkan list l dengan tambahan e sebagai elemen pertamanya } { jika alokasi gagal, mengirimkan l }

function kons●(l: List, e: ElType) → List 
{ mengirimkan list l dengan tambahan e sebagai elemen terakhir } { jika alokasi gagal, mengirimkan l }

function findX (l: List, x : ElType) -> boolean
{ mengirimkan true apabila x ada dalam l (bisa kosong), dan false apabila sebaliknya }

procedure splitUnique (input L : List, output L1, L2 : List)
{ prosedur memecah List L (bisa kosong) menjadi L1 dan L2 dengan elemen yang unik masuk ke L1, sedangkan elemen yang tidak unik masuk ke L2.
contoh : L = {1,2,2,3,4,4} -> L1 = {1,3}; L2 = {2,4} }

function mergeZigzag (L1 : List, L2 : List) -> List
{ fungsi menggabungkan isi elemen dari L1 dan L2 (boleh kosong) secara zigzag.
contoh : L1 = {1,2,3,4,5}; L2 = {6,7,8} -> hasil = {1,6,2,7,3,8,4,5} }
```
Buatlah implementasi dari fungsi-fungsi berikut, spesifikasi tidak perlu ditulis ulang:
1. Fungsi `findX`
2. Prosedur `splitUnique`
3. Fungsi `mergeZigzag`

## Binary Search Tree
```haskell
constant Nil: ... { terdefinisi }
type Infotype: <id: integer, count: integer>
type Node: <info: Infotype, Left: BSTree, Right: BSTree >
type adrNode: pointer to Node
type BSTree: adrNode

{ Selektor: jika P adalah BSTree:
Id(P) untuk mengakses bagian P↑.Info.Value;
Count(P) untuk mengakses bagian P↑.Info.Count;
Left(P) untuk mengakses bagian P↑.Left;
Right(P) untuk mengakses bagian P↑.Right }

{*** Predikat ***}
function IsTreeEmpty (P: BSTree) → boolean
{ mengirimkan true jika P kosong, false jika tidak }

function IsTreeOneElmt (P: BSTree) → boolean
{ mengirimkan true jika P tidak kosong dan hanya terdiri atas 1 elemen }

function IsUnerLeft (P: BSTree) → boolean
{ mengirimkan true jika P hanya memiliki subpohon kiri. Prekondisi: P tidak kosong }

function IsUnerRight (P: BSTree) → boolean
{ mengirimkan true jika P hanya memiliki subpohon kanan. Prekondisi: P tidak kosong }

function IsBiner (P: BSTree) → boolean
{ mengirimkan true jika P memiliki subpohon kiri dan kanan. Prekondisi: P 
tidak kosong }

procedure insertBook (input/output P : BSTree, input newBook : ElType)
{ menambahkan newBook ke dalam P (bisa kosong). Apabila id dari newBook sudah ada di P, maka tambahkan count-nya, apabila id newBook belum ada di P, maka buat node baru (tentu harus terurut secara BST) }

function countBookPos (P : BSTree, idMin : integer, idMax : integer) -> integer
{ fungsi menghitung jumlah buku yang id nya berada di antara idMin dan idMax (inklusif) }

function findBookPos (P : BSTree, bookId : integer) -> integer
{ fungsi mengembalikan posisi urutan dari buku dengan id bookId pada pohon P jika diurutkan secara inorder apabila bookId ada di P. Apabila bookId tidak ada di P kembalikan 0 }
```
Buatlah implementasi dari fungsi-fungsi berikut, spesifikasi tidak perlu ditulis ulang:
1. Prosedur `insertBook`
2. Fungsi `countBookPos`
3. Fungsi `findBookPos`

## Graf
### Spesifikasi
- Graf terdiri dari 2 list terpisah, yaitu **list node** dan **list edge**
- **list node** hanya memiliki info dan next
- **list edge** memiliki info, next, nodeAsal, dan nodeTujuan

1. Buatlah ADT graf sesuai spesifikasi dilengkapi dengan definisi dan spesifikasi konstruktor, manajemen memori (alokasi dan dealokasi), serta fungsi untuk pencarian, penambahan, dan penghapusan node dan edge (kembalian dari fungsi pencarian node atau edge adalah address ke node atau edge tersebut, bukan hanya boolean true atau false)
2. Realisasikan fungsi searchEdge
3. Realisasikan prosedur delNode

## Studi Kasus
```haskell
type Film:< nama: string, next: AdrFIlm >
type Studio:< nama: string, next: AdrStudio >
type Penayangan:< film: AdrFilm, studio: AdrStudio, jamTayang : string, next : AdrPenayangan>

type AdrFilm : pointer to Film 
type AdrStudio : pointer to Studio
type AdrPenayangan : pointer to Penayangan

type ListFilm : AdrFilm
type ListStudio   : AdrStudio
type ListPenayangan  : AdrPenayangan


{  Manajemen Memori  }

function newFilmNode (nama : string) -> AdrFilm
-- { fungsi mengalokasikan film baru }

function newStudioNode (nama : string) -> AdrStudio
{ fungsi mengalokasikan studio baru }

function newPenayanganNode (film: AdrFilm, studio: AdrStudio, jamTayang : string) -> AdrPenayangan
{ fungsi mengalokasikan penayangan baru }

function searchFilm (LPenayangan : ListPenayangan, nama : string) 
-> AdrFilm
{ fungsi mengembalikan Address dari film yang berjudul nama pada LPenayangan apabila ada. Apabila tidak ada mengembalikan NIL }

function countFilmInPenayangan (nama : string, LPenayangan : ListPenayangan) -> integer
{ fungsi mengembalikan jumlah frekuensi tayang suatu film dengan judul nama pada LPenayangan }

procedure tampilJamTayang (input nama : string, input LPenayangan : ListPenayangan, input LFilm : ListFilm)
{ menampilkan semua jam tayang dari film dengan judul nama yang terdapat pada LPenayangan }

function minPenayanganFilm (LPenayangan : ListPenayangan, LFilm : ListFilm) -> AdrFilm
{ fungsi mengembalikan Address dari film yang paling jarang ditanyangkan pada LPenayangan }

procedure makeNewStudio (input/output LStudio : ListStudio, input/output LPenayangan : ListPenayangan, input LFilm : ListFilm)
{ prosedur membuat studio baru dengan menambahkannya ke dalam list studio. kemudian pada studio baru tersebut ditayangkan film yang paling jarang tayang di LPenayangan pada jam 08:00 }
```
Buatlah implementasi dari fungsi-fungsi berikut, spesifikasi tidak perlu ditulis ulang:
1. Prosedur `tampilJamTayang`
2. Fungsi `minPenayanganFilm`
3. Prosedur `makeNewStudio`
