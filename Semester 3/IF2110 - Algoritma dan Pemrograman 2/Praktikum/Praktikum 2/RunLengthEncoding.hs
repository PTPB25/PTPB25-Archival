
module RunLengthEncoding where

-- DEFINISI DAN SPESIFIKASI LIST

-- type List of character: [] atau [e o List of character]
-- Definisi type List of character:
-- Basis: List of character kosong adalah List of character
-- Rekurens: List of character tidak kosong dibentuk dengan menambahkan elemen character ke awal List of character

-- type List of <character, integer> : [] atau [e o List of <character, integer>]
-- Definisi type List of <character, integer>:
-- Basis: List of <character, integer> kosong adalah List of <character, integer>
-- Rekurens: List of <character, integer> tidak kosong dibentuk dengan menambahkan elemen character ke awal List of <character, integer>


-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR

konso :: (Char, Int) -> [(Char, Int)] -> [(Char, Int)]
-- konso(e, li) menghasilkan List of <character, integer> baru yang merupakan hasil penambahan elemen e ke bagian awal list li
-- REALISASI
konso e li = [e] ++ li


-- DEFINISI DAN SPESIFIKASI PREDIKAT

isEmpty :: String -> Bool
-- isEmpty(s) mengembalikan true jika string s kosong, selain itu mengembalikan false
-- REALISASI
isEmpty li = null li


-- DEFINISI DAN SPESIFIKASI UTAMA

consecutiveLength :: String -> Char -> Int
-- consecutiveLength(s, chr) mengembalikan banyaknya kemunculan character chr secara konsekutif dari awal string s
-- REALISASI
consecutiveLength s chr =
    if isEmpty s || (head s) /= chr then
        0
    else
        1 + consecutiveLength (tail s) (chr)


removeConsecutive :: String -> Int -> String
-- removeConsecutive(s, cnt) menghilangkan cnt buah elemen secara konsekutif dari awal string s, prekondisi yaitu cnt <= banyak elemen di string s
-- REALISASI
removeConsecutive s cnt =
    if cnt == 0 then
        s
    else
        removeConsecutive (tail s) (cnt - 1)


runLengthEncoding :: String -> [(Char, Int)]
-- runLengthEncoding(s) menghasilkan run length encoding dari string s dalam format List of <character, integer>
-- REALISASI
runLengthEncoding s =
    if isEmpty s then
       []
    else
        let cnt = consecutiveLength s (head s) 
        in
            konso
                (head s, cnt)
                (runLengthEncoding (removeConsecutive s cnt))


