module ListSplit where

-- DEFINISI DAN SPESIFIKASI LIST

-- type List of integer: [] atau [e o List of Integer]
-- Definisi type List of integer:
-- Basis: List of integer kosong adalah List of integer
-- Rekurens: List of integer tidak kosong dapat dibuat dengan menambahkan elemen integer ke awal List of integer


-- DEFINISI DAN SPESIFIKASI FUNGSI

splitHead :: [Int] -> (Int,[Int])
-- {splitHead(l) menghasilkan pasangan (head, rest) dari list l, l tidak kosong}
-- Contoh : splitHead [1,2,3,4,5] = (1,[2,3,4,5])
-- REALISASI
splitHead li = (head li, tail li)

splitTail :: [Int] -> ([Int],Int)
-- {splitTail(l) menghasilkan pasangan (rest, tail) dari list l, l tidak kosong}
-- Contoh : splitTail [1,2,3,4,5] = ([1,2,3,4],5)
-- REALISASI
splitTail li = (init li, last li)
