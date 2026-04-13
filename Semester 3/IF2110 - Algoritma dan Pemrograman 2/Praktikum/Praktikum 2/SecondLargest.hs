
module SecondLargest where

-- DEFINISI DAN SPESIFIKASI LIST

-- type List of integer: [] atau [e o List of integer]
-- Definisi type List of integer:
-- Basis: List of integer kosong adalah List of integer
-- Rekurens: List of integer tidak kosong dapat dibuat dengan menambahkan integer ke awal sebuah List of integer


-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR 

konso :: Int -> [Int] -> [Int]
-- konso(e, li) menghasilkan list of Integer yang merupakan hasil menambahkan elemen e ke awal list li
-- REALISASI
konso e li = [e] ++ li


-- DEFINISI DAN SPESIFIKASI PREDIKAT

isEmpty :: [Int] -> Bool
-- isEmpty(li) mengembalikan true jika li kosong, false jika tidak
-- REALISASI
isEmpty li = null li

isOneElement :: [Int] -> Bool
-- isOneElement(li) mengembalikan true jika li berisi tepat satu elemen, false jika tidak
-- REALISASI
isOneElement li = isEmpty (tail li)


-- DEFINISI DAN SPESIFIKASI UTAMA

firstLargest :: [Int] -> Int
-- firstLargest(li) mengembalikan nilai terbesar dari semua integer yang ada di list li
-- REALISASI
firstLargest li =
    if isOneElement li then
        head li
    else
        if head li <  head (tail li) then
            firstLargest (tail li)
        else
            firstLargest (konso (head li) (tail (tail li)))


removeElement :: [Int] -> Int -> [Int]
-- removeElement(li, e) menghilangkan elemen e pada list li, prekondisi yaitu elemen e dijamin ada di list li
-- REALISASI
removeElement li e =
    if head li == e then
        tail li
    else
        konso (head li) (removeElement (tail li) (e))


secondLargest :: [Int] -> Int
-- secondLargest(li) mengembalikan nilai terbesar kedua dari semua intege yang ada di list li
-- REALISASI
secondLargest li = firstLargest (removeElement li (firstLargest li)) 


