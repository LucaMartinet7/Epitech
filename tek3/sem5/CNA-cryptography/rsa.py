import math

import math

MAX_PRIME_COMPARISON = 181358386295828890784790396749914598494021005743692864945805614932638907

def is_prime(n: int) -> bool:
    if n > MAX_PRIME_COMPARISON:
        return True
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def get_phi(p, q):
    return (p - 1) * (q - 1)

def get_e(phi):
    fermat_primes = [65537, 257, 17, 5, 3]
    valid_es = []
    for prime in fermat_primes:
        if (math.gcd(prime, phi) == 1 and prime < phi):
            valid_es.append(prime)
    if valid_es:
        chosen_e = valid_es[0]
        return chosen_e
    raise ValueError("Failed to find a valid e")

def generate_rsa_keys(p, q):
    n = p * q
    phi = get_phi(p, q)
    e = get_e(phi)
    d = pow(e, -1, phi)
    return (e, n), (d, n)

def reverse_pairs(s):
    result = []
    for i in range(0, len(s), 2):
        pair = s[i:i+2]
        result.insert(0, pair)
    return ''.join(result)

def int_to_bytes(n, length=None):
    if length is None:
        length = (n.bit_length() + 7) // 8
    return n.to_bytes(length, byteorder='little')

def format_key(e, n):
    e_bytes = int_to_bytes(e)
    n_bytes = int_to_bytes(n)
    return f"{e_bytes.hex()}-{n_bytes.hex()}"

def little_endian(n : str) -> str:
    return "".join([n[i:i+2] for i in range(0, len(n), 2)][::-1])

def to_little_endian(hex_str):
    return int.from_bytes(bytes.fromhex(hex_str)[::-1], byteorder='big')

def rsa_cipher(message, public_key):
    e, n = public_key.split('-')
    e_lil = to_little_endian(e)
    n_lil = to_little_endian(n)
    message_bytes = message.encode()[::-1]
    message_int = int.from_bytes(message_bytes, byteorder='big')
    power = pow(message_int, e_lil, n_lil)
    power_bytes = power.to_bytes((power.bit_length() + 7) // 8, byteorder='big')[::-1]
    return power_bytes.hex()

def rsa_decrypt(ciphertext, private_key):
    d, n = private_key.split('-')
    d_lil = to_little_endian(d)
    n_lil = to_little_endian(n)
    ciphertext_bytes = bytes.fromhex(ciphertext)[::-1]
    ciphertext_int = int.from_bytes(ciphertext_bytes, byteorder='big')
    power = pow(ciphertext_int, d_lil, n_lil)
    power_bytes = power.to_bytes((power.bit_length() + 7) // 8, byteorder='big')[::-1]
    return power_bytes.decode()
