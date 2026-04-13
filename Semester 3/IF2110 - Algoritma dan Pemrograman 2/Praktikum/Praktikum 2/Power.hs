module Power where

-- DEFINISI DAN SPESIFIKASI UTAMA

isPowerOf :: Int -> Int -> Bool
-- isPowerOf n base bernilai True jika n = base ^ k
-- dengan n dan base adalah bilangan asli
-- dan k adalah bilangan bulat nonnegatif
-- contoh: isPowerOf 27 3 = True (3^3 = 27)
-- contoh: isPowerOf 1 5 = True (5^0 = 1)
-- contoh: isPowerOf 5 10 = False

-- REALISASI
isPowerOf n base =
    if (base == 1) || (mod n base /= 0) then
        (n == 1)
    else
        isPowerOf (div n base) (base)

