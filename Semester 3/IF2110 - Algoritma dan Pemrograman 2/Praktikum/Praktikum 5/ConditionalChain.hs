module ConditionalChain where
 
isEmpty :: [a] -> Bool
isEmpty li = null li
 
konso :: a -> [a] -> [a]
konso e li = [e] ++ li
 
-- Deskripsi:
-- Fungsi `conditionalChain` menerima sebuah pasangan aturan yang terdiri dari
-- kondisi dan fungsi transformasi, serta sebuah list (bisa kosong).
-- Setiap elemen pada list akan dicek terhadap kondisi tersebut.
-- Jika elemen memenuhi kondisi, maka elemen tersebut akan diubah
-- menggunakan fungsi transformasi. Jika tidak, elemen dibiarkan tetap.
 
-- Contoh:
-- conditionalChain ((\x -> x < 0), (\x -> x - 1)) [-2, 0, 4] => [-3, 0, 4]
 
conditionalChain :: (a -> Bool, a -> a) -> [a] -> [a]
conditionalChain (cond, transform) li
    | isEmpty li = []
    | otherwise = 
        konso 
            (if (cond (head li)) then (transform (head li)) else (head li)) 
            (conditionalChain (cond, transform) (tail li))