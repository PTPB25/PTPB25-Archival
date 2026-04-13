module CountPathSum where

-- DEFINISI DATA STRUKTUR
-- Binary Tree dengan konstruktor Node dan Empty
data BinTree a = Empty | Node a (BinTree a) (BinTree a)
  deriving (Show, Eq)

-- KONSTRUKTOR
-- Definisi dan Spesifikasi utama
makeBinTree :: Int -> (BinTree Int) -> (BinTree Int) -> (BinTree Int)
-- Realisasi
makeBinTree a l r = Node a l r

-- SELEKTOR
-- Definisi dan Spesifikasi utama
akar  :: BinTree Int -> Int
left  :: BinTree Int -> BinTree Int
right :: BinTree Int -> BinTree Int

-- Realisasi
akar Empty          = error "akar: pohon kosong tidak punya akar"
akar (Node v _ _)   = v

left Empty          = error "left: pohon kosong tidak punya subpohon kiri"
left (Node _ l _)   = l

right Empty         = error "right: pohon kosong tidak punya subpohon kanan"
right (Node _ _ r)  = r

-- PREDIKAT
-- Definisi dan Spesifikasi utama
isTreeEmpty  :: BinTree a -> Bool
isOneElmt    :: BinTree a -> Bool
isExistLeft  :: BinTree a -> Bool
isExistRight :: BinTree a -> Bool
isUnerLeft   :: BinTree a -> Bool
isUnerRight  :: BinTree a -> Bool
isBiner      :: BinTree a -> Bool

-- Realisasi
isTreeEmpty Empty                = True
isTreeEmpty _                    = False

isOneElmt (Node _ Empty Empty)   = True
isOneElmt _                      = False

isExistLeft (Node _ l _)         = not (isTreeEmpty l)
isExistLeft _                    = False

isExistRight (Node _ _ r)        = not (isTreeEmpty r)
isExistRight _                   = False

isUnerLeft (Node _ l r)          = not (isTreeEmpty l) && isTreeEmpty r
isUnerLeft _                     = False

isUnerRight (Node _ l r)         = isTreeEmpty l && not (isTreeEmpty r)
isUnerRight _                    = False

isBiner (Node _ l r)             = not (isTreeEmpty l) && not (isTreeEmpty r)
isBiner _                        = False


-- TODO: Lengkapi fungsi countPathSum
-- Fungsi ini akan menghitung berapa banyak path dari root ke leaf yang jumlahnya sama dengan target
countPathSum :: BinTree Int -> Int -> Int
{-
Contoh 1:
Pohon:
         5
        / \
       4   8
     /   /  \
    11  13   4
    / \     / \
   7   2  5   1

countPathSum tree 22 == 2
-- Dua path yang cocok:
-- 5 → 4 → 11 → 2
-- 5 → 8 → 4 → 5
-}

{-
Contoh cara testing di GHCi:
1. Definisikan tree
    let tree =
            Node 5
            (Node 4
                (Node 11 (Node 7 Empty Empty) (Node 2 Empty Empty))
                Empty)
            (Node 8
                (Node 13 Empty Empty)
                (Node 4 (Node 5 Empty Empty) (Node 1 Empty Empty)))

2. Jalankan fungsi:
    countPathSum tree 22
-}

-- Batasan:
-- - Jumlah node pada pohon berada dalam rentang [0, 10^4]
-- - Nilai pada setiap node berada dalam rentang [-100, 100]

-- REALISASI
countPathSum tree target
    | isTreeEmpty tree = 0
    | isOneElmt tree = (if akar(tree) == target then 1 else 0)
    | isUnerLeft tree = countPathSum (left tree) (target - akar(tree))
    | isUnerRight tree = countPathSum (right tree) (target - akar(tree))
    | otherwise = 
        countPathSum (left tree) (target - akar(tree)) +
        countPathSum (right tree) (target - akar(tree))
    