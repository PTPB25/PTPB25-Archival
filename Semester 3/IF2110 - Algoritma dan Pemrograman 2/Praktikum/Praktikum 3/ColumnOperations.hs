module ColumnOperations where 

konsdot :: [Int] -> Int -> [Int]
konso :: Int -> [Int] -> [Int]
isEmpty :: [Int] -> Bool
isOneElement :: [Int] -> Bool
isEmptyMatrix :: [[Int]] -> Bool
isOneElementMatrix :: [[Int]] -> Bool

konso e l = [e] ++ l
konsdot l e = l ++ [e]
isEmpty l = null l
isOneElement l = isEmpty (tail l)
isEmptyMatrix m = null m
isOneElementMatrix m = isEmptyMatrix (tail m)

max2 :: Int -> Int -> Int
max2 a b = (if a > b then a else b)

min2 :: Int -> Int -> Int
min2 a b = (if a < b then a else b)

getIndex :: [Int] -> Int -> Int
getIndex li idx
    | (isOneElement (li) || idx == 0) = head(li)
    | otherwise = getIndex (tail li) (idx - 1)

findMax :: [[Int]] -> Int -> Int
findMax m idx
    | isOneElementMatrix m = (getIndex (head m) idx)
    | otherwise = max2 (getIndex (head m) idx) (findMax (tail m) (idx))

findMin :: [[Int]] -> Int -> Int
findMin m idx
    | isOneElementMatrix m = (getIndex (head m) idx)
    | otherwise = min2 (getIndex (head m) idx) (findMin (tail m) (idx))

findSum :: [[Int]] -> Int -> Int
findSum m idx
    | isOneElementMatrix m = (getIndex (head m) idx)
    | otherwise = (getIndex (head m) idx) + (findSum (tail m) (idx))

listLength :: [Int] -> Int
listLength li 
    | isEmpty li = 0
    | otherwise = 1 + (listLength (tail li))

columnOperationsHelper :: [[Int]] -> Int -> Int -> [Int]
columnOperationsHelper m idx last
    | (idx == last) = []
    | ((mod idx 3) == 0) = konso (findMax m idx) (columnOperationsHelper m (idx+1) last)
    | ((mod idx 3) == 1) = konso (findMin m idx) (columnOperationsHelper m (idx+1) last)
    | otherwise = konso (findSum m idx) (columnOperationsHelper m (idx+1) last)

-- Lengkapi Fungsi di bawah ini
columnOperations :: [[Int]] -> [Int]
columnOperations m
    | (isEmptyMatrix m || isEmpty (head m)) = []
    | otherwise = columnOperationsHelper (m) (0) (length (head m))