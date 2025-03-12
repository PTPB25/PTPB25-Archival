#!/usr/bin/env sage

from Crypto.Util.number import long_to_bytes as l2b

exec(preparse(open("out.txt", "r").read())) # ct, n, e, leak

F.<q> = ZZ[]

for x1 in range(1, 600):
    for x2 in range(1, 600):
        
        poly = leak * q**2 + 2 * q * (leak*x2 - x1) - n

        for factor in poly.factor():
            result = floor(factor[0][0])
            if n % result == 0:
                _q = result
                _p = n // _q
                print(f"[FOUND] p: {_p}")
                print(f"[FOUND] q: {_q}")
                print("[FLAG] ", l2b(pow(ct, pow(e, -1, (_p-1)*(_q-1), ),n)))
                print()
