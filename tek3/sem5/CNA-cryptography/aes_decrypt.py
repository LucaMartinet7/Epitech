from key_expansion import expand_key
from predefined import inv_sbox, galois
from aes_encrypt import AddRoundKey

def InvSubBytes(state):
    return [[f'{inv_sbox[int(byte, 16)]:02x}' for byte in row] for row in state]

def InvShiftRows(state):
    state_bytes = bytearray()
    for row in state:
        for byte in row:
            state_bytes.append(int(byte, 16))
    t = list(state_bytes)
    t[1], t[5], t[9], t[13] = t[13], t[1], t[5], t[9]
    t[2], t[6], t[10], t[14] = t[10], t[14], t[2], t[6]
    t[3], t[7], t[11], t[15] = t[7], t[11], t[15], t[3]
    r = [[f'{t[i * 4 + j]:02x}' for j in range(4)] for i in range(4)]
    return r


def inv_mix(column):
    return [
        galois(column[0], 14) ^ galois(column[1], 11) ^ galois(column[2], 13) ^ galois(column[3], 9),
        galois(column[0], 9) ^ galois(column[1], 14) ^ galois(column[2], 11) ^ galois(column[3], 13),
        galois(column[0], 13) ^ galois(column[1], 9) ^ galois(column[2], 14) ^ galois(column[3], 11),
        galois(column[0], 11) ^ galois(column[1], 13) ^ galois(column[2], 9) ^ galois(column[3], 14)
    ]

def invMixColumns(block):
    Array = bytearray(16)
    for i in range(4):
        column = [block[i * 4], block[i * 4 + 1], block[i * 4 + 2], block[i * 4 + 3]]
        mixed_column = inv_mix(column)
        Array[i * 4], Array[i * 4 + 1], Array[i * 4 + 2], Array[i * 4 + 3] = mixed_column
    return bytes(Array)

def InvMixColumns(state):
    state_bytes = bytearray()
    for row in state:
        for byte in row:
            state_bytes.append(int(byte, 16))
    mixed_bytes = invMixColumns(state_bytes)
    mixed_state = [[f'{mixed_bytes[i * 4 + j]:02x}' for j in range(4)] for i in range(4)]
    return mixed_state

def aes_decrypt(ciphertext, key):
    sub_key = expand_key(key)
    state = AddRoundKey(ciphertext, sub_key[10])
    state = InvShiftRows(state)
    state = InvSubBytes(state)
    for i in range(9, 0, -1):
        state = AddRoundKey(state, sub_key[i])
        state = InvMixColumns(state)
        state = InvShiftRows(state)
        state = InvSubBytes(state)
    state = AddRoundKey(state, sub_key[0])
    return state