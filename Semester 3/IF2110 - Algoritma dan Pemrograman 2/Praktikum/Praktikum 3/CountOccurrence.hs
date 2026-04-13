module CountOccurrence where

isEmptyL :: [[Int]] -> Bool
isEmptyL m = null m

isEmpty :: [Int] -> Bool
isEmpty m = null m


countInList :: [Int] -> Int -> Int
-- countInList(li, num) mengembalikan jumlah kemunculan elemen num pada list li
countInList m number =
    if isEmpty (m) then
        0
    else
        (if (head m) == number then 1 else 0) + countInList (tail m) (number)


-- count(ListOfList, n) menghitung berapa kali integer n muncul di dalam sebuah list of list.
-- CONTOH: count [[1,2,1],[3],[1,4]] 1 menghasilkan 3
count :: [[Int]] -> Int -> Int
count m number =
    if isEmptyL (m) then
        0
    else
        countInList (head m) (number) + count (tail m) (number);