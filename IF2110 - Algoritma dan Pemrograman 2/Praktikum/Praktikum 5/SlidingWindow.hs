module SlidingWindow where
 
konso:: a -> [a] -> [a]
konso e l = e : l
 
konsDot:: [a] -> a -> [a]
konsDot l e = l ++ [e]
 
 
isEmpty:: [a] -> Bool
isEmpty l = null l
 
nbElement:: [a] -> Int
nbElement l = if isEmpty l then 0 else 1 + nbElement (tail l)
 
{-|
  TakeN menerima sebuah integer n dan sebuah list l, dan menghasilkan sebuah list yang berisi n elemen pertama dari l. Jika n lebih besar dari panjang l, maka dihasilkan l itu sendiri.
  Prekondisi: n >= 0, l bisa kosong.
-}
takeN:: Int -> [a] -> [a]
takeN n li
    | (n == 0) || (isEmpty li) = []
    | otherwise = konso (head li) (takeN (n-1) (tail li))
 
{-|
  Deskripsi:
  Fungsi slidingWindow menerima sebuah integer ukuran window n prekondisi : 0 < n <= panjang xs,
  sebuah fungsi pemroses f, dan sebuah list xs, prekondisi : panjang xs > 0. Fungsi ini akan
  menghasilkan sebuah list baru yang berisi hasil dari penerapan
  fungsi f ke setiap window dengan ukuran n. Dapat menggunakan fungsi takeN.
 
  Contoh:
  slidingWindow 3 windowRange [1, 2, 3, 4, 5] akan menghasilkan [2, 2, 2]
-}
slidingWindow :: Int -> ([a] -> b) -> [a] -> [b]
slidingWindow n func li
    | (nbElement li) < n = [] 
    | otherwise = konso (func (takeN n li)) (slidingWindow n func (tail li))
 
{-|
  Deskripsi:
  Fungsi windowRange menghasilkan selisih antara nilai maksimum dan nilai minimum dari list tersebut.
  nilai minimum dari list tersebut.
 
  Contoh:
  windowRange [1, 2, 3, 4, 5] akan menghasilkan 4
-}
windowRange :: [Int] -> Int
windowRange li
    | (isEmpty li || isEmpty (tail li)) = 0
    | (isEmpty (tail (tail li))) =
        let
            a = (head li) - (head (tail li))
            b = (head (tail li)) - (head li)
        in
            (if a < 0 then b else a)
    | otherwise =
        let
            a = (head li)
            b = (head (tail li))
            c = (head (tail (tail li)))
        in
            if (a <= b && b <= c) || (c <= b && b <= a) then
                windowRange (konso (a) (tail (tail li)))
            else
                if (b <= a && a <= c) || (c <= a && a <= b) then
                    windowRange (konso (b) (tail (tail li)))
                else
                    windowRange (konso (a) (konso (b) (tail (tail (tail li)))))