module PruneTree where

data BinTree a = Empty | Node a (BinTree a) (BinTree a)
  deriving (Show, Eq)

-- KONSTRUKTOR
-- Definisi dan Spesifikasi utama
makeBinTree :: Int -> (BinTree Int) -> (BinTree Int) -> (BinTree Int)
-- Realisasi
makeBinTree a l r = Node a l r

-- SELEKTOR
akar :: (BinTree Int) -> Int
{- akar p adalah akar dari p. Jika p adalah //L A R\\ maka akar p = A -}
akar (Node a l r) = a
left :: (BinTree Int) -> (BinTree Int)
{- left p adalah sub pohon kiri dari p. Jika p adalah //L A R\\ maka left p = L -}
left (Node a l r) = l
right :: (BinTree Int) -> (BinTree Int)
{- right p adalah sub pohon kanan dari p. Jika p adalah //L A R\\ maka right p = R -}
right (Node a l r) = r

-- PREDIKAT
isTreeEmpty :: (BinTree Int) -> Bool
{- isTreeEmpty p true jika p adalah // \\ -}
isTreeEmpty Empty = True
isTreeEmpty (Node a l r) = False
isOneElmt :: (BinTree Int) -> Bool
{- isOneElmt p true jika p adalah //A\\ -}
isOneElmt p =
  not (isTreeEmpty p) && isTreeEmpty (left p) && isTreeEmpty (right p)

isUnerLeft :: (BinTree Int) -> Bool
{- isUnerLeft p true jika p hanya mengandung sub pohon kiri, P adalah //L A\\ -}
isUnerLeft p = not (isTreeEmpty p) && not (isTreeEmpty (left p)) && isTreeEmpty (right p)
isUnerRight :: (BinTree Int) -> Bool
{- isUnerRight p true jika p hanya mengandung sub pohon kanan, P adalah //A L\\ -}
isUnerRight p = not (isTreeEmpty p) && isTreeEmpty (left p) && not (isTreeEmpty (right p))
isBiner :: (BinTree Int) -> Bool
{- isBiner p true jika p mengandung sub pohon kiri dan sub pohon kanan, p adalah // L A R \\ -}
isBiner p = not (isTreeEmpty p) && not (isTreeEmpty (left p)) && not (isTreeEmpty (right p))

isExistLeft :: (BinTree Int) -> Bool
{- isExistLeft p true jika p mengandung sub pohon kiri -}
isExistLeft p = not (isTreeEmpty p) && not (isTreeEmpty (left p))
isExistRight :: (BinTree Int) -> Bool
{- isExistRight p true jika p mengandung sub pohon kanan -}
isExistRight p = not (isTreeEmpty p) && not (isTreeEmpty (right p))

-- Definisi dan Spesifikasi Utama
pruneTree :: BinTree Int -> Int -> BinTree Int
{- pruneTree p d menghasilkan pohon p yang dipangkas sehingga 
   kedalaman pohon tidak lebih dari d.
   Kedalaman akar adalah 1.
-}

-- TODO: implementasikan fungsi pruneTree

-- REALISASI
pruneTree tree maxDepth
    | (maxDepth == 0 || isTreeEmpty tree) = Empty
    | isUnerLeft tree = makeBinTree (akar tree) (pruneTree (left tree) (maxDepth-1)) Empty
    | isUnerRight tree = makeBinTree (akar tree) Empty (pruneTree (right tree) (maxDepth-1))
    | otherwise = 
        makeBinTree 
            (akar tree) 
            (pruneTree (left tree) (maxDepth-1)) 
            (pruneTree (right tree) (maxDepth-1))