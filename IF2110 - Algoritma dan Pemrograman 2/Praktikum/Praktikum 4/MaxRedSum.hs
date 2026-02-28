module MaxRedSum where

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
isExistLeft p =
  not (isTreeEmpty p) && not (isTreeEmpty (left p))
isExistRight :: (BinTree Int) -> Bool
{- isExistRight p true jika p mengandung sub pohon kanan -}
isExistRight p =
  not (isTreeEmpty p) && not (isTreeEmpty (right p))

-- Definisi dan Spesifikasi utama
maxRedSum :: (BinTree Int) -> Int
-- maxRedSum menghitung jumlah maksimum nilai node berwarna merah dengan aturan pewarnaan sebagai berikut:
--   - Awalnya setiap node pada binary tree berwarna putih
--   - Anda dapat mewarnai sebuah node menjadi merah dengan syarat 
--     tidak ada node tetangganya (parent atau child) yang diwarnai merah. 
--     Dengan kata lain, tidak ada dua node warna merah yang bertetanggaan.
--   - Operasi pewarnaan node dapat dilakukan sebanyak mungkin selama tidak melanggar syarat lain
--
-- Batasan:
--   - Nilai dari sebuah node dipastikan bernilai positif
--   - 1 <= n <= 12 dengan n adalah banyak node
--
-- Contoh:
-- Diberikan pohon:
--       3
--      / \
--     1   4
--        / \
--       2   6
-- Dapat dibuktikan bahwa jumlah maksimum nilai node berwarna merah akan diperoleh
-- jika kita mewarnai node-node berikut menjadi merah: [3, 2, 6]
-- sehingga jawabannya adalah 3 + 2 + 6 = 11
--
-- Keterangan:
--   - Anda diperbolehkan menggunakan fungsi helper

-- REALISASI
maxRedSum tree
    | isTreeEmpty(tree) = 0
    | otherwise = 
        let 
            val1 =
                akar(tree) + 
                (if isExistLeft(tree) then maxRedSum (left(left tree)) + maxRedSum (right(left tree)) else 0) +
                (if isExistRight(tree) then maxRedSum (left(right tree)) + maxRedSum (right(right tree)) else 0)
            val2 = 
                (maxRedSum (left tree)) +
                (maxRedSum (right tree))
        in
            (if val1 < val2 then val2 else val1)

