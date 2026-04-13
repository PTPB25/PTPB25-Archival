module TransposeMatrix where

-- KonsLo(L,S) diberikan sebuah List L dan sebuah List of List S, membentuk list baru dengan L sebagai elemen pertama
-- Example: konsLo [1,2,3] [[4,5,6],[7,8,9]] menghasilkan [[1,2,3],[4,5,6],[7,8,9]]
konsLo :: [Int] -> [[Int]] -> [[Int]]
konsLo l s = l : s

isEmptyL :: [[Int]] -> Bool
isEmptyL m = null m

isEmpty :: [Int] -> Bool
isEmpty li = null li

-- transposeMatrix(m) mengembalikan transpose dari matrix m
-- transposeMatrix([[1,2,3],[4,5,6],[7,8,9]]) menghasilkan [[1,4,7],[2,5,8],[3,6,9]]

-- Hint : Gunakan map untuk menerapkan sebuah fungsi pada setiap elemen list
-- map head m → Mengambil elemen pertama dari setiap list dalam m lalu menyimpannya dalam sebuah list
-- map tail m → Mengambil semua elemen kecuali yang pertama dari setiap list dalam m lalu menyimpannya dalam sebuah list
-- Example:
-- m = [[1,2,3],[4,5,6],[7,8,9]]
-- map head m = [1,4,7]
-- map tail m = [[2,3],[5,6],[8,9]]

transposeMatrix :: [[Int]] -> [[Int]]
transposeMatrix m =
    if isEmptyL (m) || isEmpty (head m) then
        []
    else
        konsLo (map head m) (transposeMatrix (map tail m))