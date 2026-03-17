# Soal
## 1
Buatlah prosedur **deleteNeg** yang menghapus semua elemen bernilai negatif (<0) pada sebuah list of integer l. List l boleh kosong dan setiap elemen yang dihapus harus dilakukan dealokasi.
```
procedure deleteNeg(input/output l:List)
```

## 2
Buatlah prosedur **copyPos** yang menyalin semua elemen bernilai positif (>0) dari sebuah list of integer l1 menjadi l2
```
procedure copyPos(input l1:List, output l2:List)
```

## 3
Buatlah prosedur **sortedInsert** yang menambahkan sebuah elemen x pada sebuah list of integer l yang terurut menaik
```
procedure sortedInsert(input/output l:List, input x:ElType)
```

## 4
Buatlah prosedur **updateList** yang menerima sebuah infotype x dan y dan sebuah list l dan kemudian mengganti elemen pertama l yang bernilai x dengan y jika x ada di l. Jika x tidak ada di l, l tetap.
```
procedure updateList(input x,y: infotype, input/output l: List)
```

# Solusi
## 1
```
procedure deleteNeg(input/output l:List)
{ menghapus semua elemenbernilai negatif (<0) pada sebuah list of integer l
 dan setiap elemen yang dihapus harus dilakukan dealokasi.
 I.S List l boleh kosong
 F.S List l hanya diisi dengan list positif }
KAMUS LOKAL
    p: Address
    val : ElType
    idx : integer
   
    procedure deleteAt(input/output l : list, input idx : integer , output val : Eltype)
ALGORITMA
    p <-l
    idx <- 0
    while (p != NIL ) do
        if (p↑.info < 0) then
            deleteAt(l , idx, val)
            p <- l
            idx <- 0
        else
            p <- p↑.next
            idx <- idx + 1
```
## 2
```
procedure copyPos(input l1:List, output l2:List)
{menyalin semua elemen bernilai positif (>0)
 dari sebuah list of integer l1 menjadi l2
 I.S l1 List tidak boleh kosong l2 sembarang
 F.S l2 berisi nilai positif dari l1}
KAMUS LOKAL
    p : Address
    procedure CreateList(output l: List)
    { I.S. Sembarang
     F.S. Terbentuk list l kosong: l diinisialisasi dengan NIL
     procedure insertLast(input/output l: List, input val: ElType)
     I.S. l terdefinisi, mungkin kosong.
     F.S. x menjadi elemen terakhir l. }
   
ALGORITMA
    p <- l1
    createlist(l2)
    while (p != NIL) do
        if (p↑.info > 0) then
            insertlast(l2, p↑.info)
        else
            p <- p↑.next
```
## 3
```
procedure sortedInsert(input/output l:List, input x:ElType)
{menambahkan sebuah elemen x pada sebuah list of integer l yang terurut menaik
 I.S l tidak koosong
 F.S menambahkan ElType secara terurut menaik }
KAMUS LOKAL
    p : Address
    idx : integer
   
procedure insertAt(input/output l: List, input val: ElType, input idx: integer)
{ I.S. l terdefinisi, tidak kosong, i merupakan indeks yang valid di l.
 F.S. x disisipkan dalam l pada indeks ke-i (bukan menimpa elemen di i). }
ALGORITMA
    p <- l
    idx <- 0
    while p↑.info != NIL and (x > p↑.info ) do
            idx <- idx + 1
            p <- p↑.next
        { idx = posisi tepat }
    insertAt(l, idx, x)
```
## 4
```
procedure updateList(input x,y: infotype, input/output l: List)
    { menerima sebuah infotype x dan
    y dan sebuah list l dan kemudian mengganti elemen pertama l yang
    bernilai x dengan y jika x ada di l.
    I.S l tidak kosong x,y terdefinisi
    F.S menganti semua input x dengan y pada l,
        Jika x tidak ada di l, l tetap }
KAMUS LOKAL
    p : Address
ALGORITMA
    p <- l
    while p↑.info != NIL  do
        if (x = p↑.info ) then
            p↑.info <- y
        else
            p <- p↑.next 
```