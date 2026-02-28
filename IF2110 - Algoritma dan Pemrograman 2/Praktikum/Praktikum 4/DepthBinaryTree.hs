module DepthBinaryTree where

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

-- DESKRIPSI SOAL
-- Diberikan akar dari binary tree, kembalikan kedalamannya.
-- Kedalaman binary tree adalah jumlah node sepanjang jalur terpanjang
-- dari node akar sampai ke node daun yang terjauh.
--
-- Contoh:
-- Input:
--        3
--       / \
--      9   20
--         /  \
--        15   7
-- Output: 3
--
-- Input:
--        1
--         \
--          2
-- Output: 2
--
-- Batasan:
-- - Jumlah node dalam tree berada dalam rentang [0, 10^4]
-- - -100 <= nilai Node <= 100
--
-- Tugas Anda:
-- Mengimplementasikan fungsi depth yang menghitung kedalaman dari binary tree secara rekursif.

-- DEFINISI DAN SPESIFIKASI UTAMA
-- depth: BinTree Int -> Int
-- {depth(tree) mengembalikan kedalaman (depth) dari binary tree.
--  Jika tree kosong (Empty), maka kedalaman adalah 0.
--  Jika tree hanya memiliki satu node, maka kedalaman adalah 1.
--  Untuk tree yang tidak kosong, kedalaman adalah 1 + max(kedalaman kiri, kedalaman kanan).}
depth :: BinTree Int -> Int
-- TODO: Implementasikan fungsi depth secara rekursif

-- NOTE: CARA TESTING DAN DEBUGGING TREE DENGAN GHCi:
-- 1. Buka terminal dan jalankan: ghci [Soal]\ DepthBinaryTree.hs
-- 2. Misal test dengan contoh tree dari soal:
--    ghci> let tree1 = makeBinTree 3 (makeBinTree 9 Empty Empty) (makeBinTree 20 (makeBinTree 15 Empty Empty) (makeBinTree 7 Empty Empty))
--    ghci> depth tree1
--    Hasil yang diharapkan: 3
--
--    Penjelasan tree1:
--        3      <- level 1
--       / \
--      9   20   <- level 2
--         /  \
--        15   7 <- level 3
--
-- 3. Test dengan tree sederhana:
--    ghci> let tree2 = makeBinTree 1 Empty (makeBinTree 2 Empty Empty)
--    ghci> depth tree2
--    Hasil yang diharapkan: 2
--
--    Penjelasan tree2:
--        1      <- level 1
--         \
--          2    <- level 2
--
-- 4. Test edge cases:
--    a) Empty tree:
--       ghci> depth Empty
--       Hasil yang diharapkan: 0
--
--       Penjelasan: Tree kosong (tidak ada node)
--       (empty)
--
--    b) Single node:
--       ghci> depth (makeBinTree 5 Empty Empty)
--       Hasil yang diharapkan: 1
--
--       Penjelasan: Tree dengan satu node saja
--           5      <- level 1

-- REALISASI
depth tree
    | isTreeEmpty tree = 0
    | otherwise =
        let
            l = (depth (left tree))
            r = (depth (right tree))
        in
            1 + (if l < r then r else l)