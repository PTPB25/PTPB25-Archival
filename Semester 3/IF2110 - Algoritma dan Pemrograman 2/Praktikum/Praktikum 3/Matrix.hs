module Matrix where 

-- UTILITY FUNCTIONS
konsdot :: [Int] -> Int -> [Int]
konso :: Int -> [Int] -> [Int]
isEmpty :: [Int] -> Bool

konso e l = [e] ++ l
konsdot l e = l ++ [e]
isEmpty l = null l

konsdotMatrix :: [[Int]] -> [Int] -> [[Int]]
konsoMatrix :: [Int] -> [[Int]] -> [[Int]]
isEmptyMatrix :: [[Int]] -> Bool

konsoMatrix e l = [e] ++ l
konsdotMatrix l e = l ++ [e]
isEmptyMatrix l = null l

-- NOTES: Semua Index dipastikan valid, yaitu tidak negatif dan tidak melebihi panjang list/Matrix

-- MATRIX MANIPULATION FUNCTIONS
-- TYPE: Matrix adalah [[Int]]
-- Dengan definisi type sebagai berikut, kita dapat mensubstitusi [[Int]] dengan Matrix
type Matrix = [[Int]]

-- addAtIndex :: Int -> [Int] -> Int -> [Int]
-- {addAtIndex x l i menambahkan elemen x pada posisi i dalam l}
-- 
-- Note: list l mungkin kosong
--       Mengembalikan [x] apabila l kosong
addAtIndex :: Int -> [Int] -> Int -> [Int]
addAtIndex x li idx
    | isEmpty(li) = [x]
    | (idx == 0) = konso (x) (li)
    | otherwise = konso (head li) (addAtIndex (x) (tail li) (idx - 1))

-- deleteAtIndex :: [Int] -> Int -> [Int]
-- {deleteAtIndex l i menghapus elemen pada posisi i dalam l}
-- 
-- Note: list l mungkin kosong
--       Mengembalikan [] apabila l kosong
deleteAtIndex :: [Int] -> Int -> [Int]
deleteAtIndex li idx
    | isEmpty(li) = []
    | (idx == 0) = tail (li)
    | otherwise = konso (head li) (deleteAtIndex (tail li) (idx - 1))


-- editAtIndex :: [Int] -> Int -> Int -> [Int]
-- {editAtIndex l i newValue mengubah elemen l pada posisi i dengan newValue}
-- 
-- Note: list l mungkin kosong
--       Mengembalikan [] apabila l kosong
editAtIndex :: [Int] -> Int -> Int -> [Int]
editAtIndex li idx val
    | isEmpty(li) = []
    | (idx == 0) = konso (val) (tail li)
    | otherwise = konso (head li) (editAtIndex (tail li) (idx - 1) (val))

-- getIndex :: [Int] -> Int -> Int
-- {getIndex li idx mengambil value pada indeks ke-idx pada list li}
--
-- Note: List li mungkin kosong, mengembalikan 0 jika li kosong
-- 
getIndex :: [Int] -> Int -> Int
getIndex li idx
    | isEmpty(li) = 0
    | (idx == 0) = (head li)
    | otherwise = getIndex (tail li) (idx - 1)

-- addMatrixElement :: Matrix -> Int -> Int -> Int -> Matrix
-- {addMatrixElement m row col value menambahkan value pada posisi (row,col) dalam m}
-- 
-- Note: Matrix m mungkin kosong
--       Mengembalikan [] apabila m kosong
addMatrixElement :: Matrix -> Int -> Int -> Int -> Matrix
addMatrixElement m row col val
    | isEmptyMatrix (m) = []
    | (row == 0) = konsoMatrix (addAtIndex (val) (head m) (col)) (tail m)
    | otherwise = konsoMatrix (head m) (addMatrixElement (tail m) (row - 1) (col) (val))

-- deleteMatrixElement :: Matrix -> Int -> Int -> Matrix  
-- {deleteMatrixElement m row col menghapus elemen pada posisi (row,col) dalam m}
-- 
-- Note: Matrix m mungkin kosong
--       Mengembalikan [] apabila m kosong
deleteMatrixElement :: Matrix -> Int -> Int -> Matrix
deleteMatrixElement m row col
    | isEmptyMatrix (m) = []
    | (row == 0) = konsoMatrix (deleteAtIndex (head m) (col)) (tail m)
    | otherwise = konsoMatrix (head m) (deleteMatrixElement (tail m) (row - 1) (col))

-- editMatrixElement :: Matrix -> Int -> Int -> Int -> Matrix
-- {editMatrixElement m row col newValue mengubah elemen pada posisi (row,col) dengan newValue}
-- 
-- Note: Matrix m mungkin kosong
--       Mengembalikan [] apabila m kosong
editMatrixElement :: Matrix -> Int -> Int -> Int -> Matrix
editMatrixElement m row col val
    | isEmptyMatrix (m) = []
    | (row == 0) = konsoMatrix (editAtIndex (head m) (col) (val)) (tail m)
    | otherwise = konsoMatrix (head m) (editMatrixElement (tail m) (row - 1) (col) (val))

-- getMatrixElement :: Matrix -> Int -> Int -> Int
-- {getMatrixElement m row col mengambil elemen pada posisi (row,col) dalam m}
-- 
-- Note: Matrix m mungkin kosong
--       Mengembalikan 0 apabila m kosong
getMatrixElement :: Matrix -> Int -> Int -> Int
getMatrixElement m row col
    | isEmptyMatrix (m) = 0
    | (row == 0) = getIndex (head m) (col)
    | otherwise = getMatrixElement (tail m) (row - 1) (col)

-- printMatrix :: Matrix -> IO ()
-- {printMatrix m mencetak m dalam format yang mudah dibaca}
printMatrix :: Matrix -> IO ()
printMatrix [] = putStrLn "Empty m"
printMatrix m = mapM_ print m
