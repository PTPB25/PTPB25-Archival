
module ThreeTree where

-- DEFINISI DAN SPESIFIKASI LIST

-- type List of integer: [] atau [e o List of integer]
-- Definisi type List of integer:
-- Basis: List of integer kosong adalah List of integer
-- Rekurens: List of integer tidak kosong dibuat dengan menambahkan elemen bertipe integer ke awal List of integer


-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR

konso :: Int -> [Int] -> [Int]
-- konso(e, li) menghasilkan list yang merupakan hasil penambahan elemen e ke awal list li
-- REALISASI
konso e li = [e] ++ li


-- DEFINISI DAN SPESIFIKASI PREDIKAT

isEmpty :: [Int] -> Bool
-- isEmpty(li) mengembalikan true jika List of integer "li" kosong, selain itu mengembalikan false
-- REALISASI
isEmpty li = null li


-- DEFINISI DAN SPESIFIKASI UTAMA

threeTree :: [Int] -> [Int]
-- threeTree(li) menghasilkan List of integer baru yang merupakan list li yang telah dihilangkan semua elemen integer yang bukan kelipatan tiga, urutan relatif tetap sama
threeTree li =
    if isEmpty(li) then
        []
    else
        if mod (head li) 3 == 0 then
            konso (head li) (threeTree (tail li))
        else
            threeTree (tail li)

