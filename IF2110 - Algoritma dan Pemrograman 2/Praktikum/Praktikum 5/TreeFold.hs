module TreeFold where
 
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
 
-- SPESIFIKASI
-- treeFoldPost f b t menghasilkan akumulasi nilai pohon t dengan fold post-order menggunakan f dan basis b.
-- Definisi: proses subpohon kiri, lalu subpohon kanan, terakhir akar.
-- Contoh:
--   Pohon t:
--         2
--        / \
--       1   3
--   treeFoldPost (\l r x -> l ++ r ++ [x]) [] t == [1,3,2]
--   treeFoldPost (\l r x -> l + r + x) 0 t == 6
--   Pohon u:
--         4
--        / \
--       2   5
--      /     \
--     1       7
--   treeFoldPost (\l r x -> l ++ r ++ [x]) [] u == [1,2,7,5,4]
--   treeFoldPost (\l r x -> l + r + x) 0 u == 19
-- TODO: Lengkapi fungsi fold post-order sesuai spesifikasi.
treeFoldPost :: (a -> a -> Int -> a) -> a -> BinTree Int -> a
treeFoldPost func base tree 
    | isTreeEmpty tree = base
    | otherwise = 
        func  
            (treeFoldPost func base (left tree))
            (treeFoldPost func base (right tree))
            (akar tree)
 
-- SPESIFIKASI
-- treeFoldPre f b t menghasilkan akumulasi nilai pohon t dengan fold pre-order menggunakan f dan basis b.
-- Definisi: proses akar terlebih dahulu, lalu subpohon kiri dan subpohon kanan.
-- Contoh:
--   Pohon t:
--         2
--        / \
--       1   3
--   treeFoldPre (\x l r -> [x] ++ l ++ r) [] t == [2,1,3]
--   treeFoldPre (\x l r -> x + l + r) 0 t == 6
--   Pohon u:
--         4
--        / \
--       2   5
--      /     \
--     1       7
--   treeFoldPre (\x l r -> [x] ++ l ++ r) [] u == [4,2,1,5,7]
--   treeFoldPre (\x l r -> x + l + r) 0 u == 19
-- TODO: Lengkapi fungsi fold pre-order sesuai spesifikasi.
treeFoldPre :: (Int -> a -> a -> a) -> a -> BinTree Int -> a
treeFoldPre func base tree 
    | isTreeEmpty tree = base
    | otherwise = 
        func 
            (akar tree) 
            (treeFoldPre func base (left tree))
            (treeFoldPre func base (right tree))
 
-- SPESIFIKASI
-- treeFoldIn f b t menghasilkan akumulasi nilai pohon t dengan fold in-order menggunakan f dan basis b.
-- Definisi: proses subpohon kiri, kemudian akar, dan terakhir subpohon kanan.
-- Contoh:
--   Pohon t:
--         2
--        / \
--       1   3
--   treeFoldIn (\l x r -> l ++ [x] ++ r) [] t == [1,2,3]
--   treeFoldIn (\l x r -> l + x + r) 0 t == 6
--   Pohon u:
--         4
--        / \
--       2   5
--      /     \
--     1       7
--   treeFoldIn (\l x r -> l ++ [x] ++ r) [] u == [1,2,4,5,7]
--   treeFoldIn (\l x r -> l + x + r) 0 u == 19
-- TODO: Lengkapi fungsi fold in-order sesuai spesifikasi.
treeFoldIn :: (a -> Int -> a -> a) -> a -> BinTree Int -> a
treeFoldIn func base tree 
    | isTreeEmpty tree = base
    | otherwise = 
        func 
            (treeFoldIn func base (left tree))
            (akar tree) 
            (treeFoldIn func base (right tree))