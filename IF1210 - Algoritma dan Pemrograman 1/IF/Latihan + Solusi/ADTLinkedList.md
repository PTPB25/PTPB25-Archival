# Soal
## 1
Buatlah fungsi **countPos** yang menghitung banyaknya kemunculan bilangan positif (>0) dari sebuah list of integer
```
function countPos(l: list) -> integer
```

## 2
Buatlah fungsi **max** yang menghasilkan nilai maksimum dari sebuah list of integer yang tidak kosong
```
function max(l: list) -> integer
```

## 3
Buatlah fungsi **searchPos** yang menghasilkan address di mana nilai positif pertama kali ditemukan di list of integer
```
function searchPos(l: list) -> address
```

# Solusi
## 1
```
function countPos(l: List) → integer
{ menghitung banyaknya kemunculan bilangan positif
  (>0) dari sebuah list of integer l }
KAMUS LOKAL
    p : address
    count : integer
ALGORITMA
    p <- l
    count <- 0
    while p != NIL do
        if p↑.info > 0 then
            count <- count + 1
        p <- p↑.next
    -> count
```

## 2
```
function max(l: List) → integer
{ menghasilkan nilai maksimum dari
  suatu list of integer l yang tidak kosong }
KAMUS LOKAL
    p : address
    max : integer
ALGORITMA
    p <- l
    max <- p↑.info
    while p != NIL do
        if p↑.info > max then
            max <- p↑.info
        p <- p↑.next
    -> max
```

## 3
```
function searchPos(l: List) → address
{ menghasilkan address di mana nilai positif
  pertama kali ditemukan di list of integer l }
KAMUS LOKAL
    p : address
    found : boolean
ALGORITMA
    p <- l
    found <- false
    while p != NIL and not found do
        if p↑.info > 0 then
            found <- true
        else
            p <- p↑.next
    -> p
```