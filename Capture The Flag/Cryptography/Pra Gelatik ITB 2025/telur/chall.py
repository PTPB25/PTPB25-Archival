from sage.all import next_prime
from sage.all import RealField
from sage.all import ZZ
from Crypto.Util.number import getPrime
from Crypto.Util.number import bytes_to_long as b2l

def get_primes(bit_length):
    return getPrime(bit_length), getPrime(bit_length)

FLAG = b'CTFITB{*}'

p, q = get_primes(512)
n = p * q
e = 0x10001

ct = pow(b2l(FLAG), e, n)

tp = next_prime(p)
tq = next_prime(q)

leak = RealField(2048)(ZZ(tp)/ZZ(tq))

print(f'ct = {ct}')
print(f'e = {e}')
print(f'n = {n}')
print(f'leak = {leak}')