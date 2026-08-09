from key_expansion import expand_key
from predefined import sbox, galois

def SubBytes(state):
    return [[f'{sbox[int(byte, 16)]:02x}' for byte in row] for row in state]

def ShiftRows(state):
    state_bytes = bytearray()
    for row in state:
        for byte in row:
            state_bytes.append(int(byte, 16))
    t = list(state_bytes)
    t[1], t[5], t[9], t[13] = t[5], t[9], t[13], t[1]
    t[2], t[6], t[10], t[14] = t[10], t[14], t[2], t[6]
    t[3], t[7], t[11], t[15] = t[15], t[3], t[7], t[11]
    r = [[f'{t[i * 4 + j]:02x}' for j in range(4)] for i in range(4)]
    return r

def mix(column):
    return [
        galois(column[0], 2) ^ galois(column[1], 3) ^ column[2] ^ column[3],
        column[0] ^ galois(column[1], 2) ^ galois(column[2], 3) ^ column[3],
        column[0] ^ column[1] ^ galois(column[2], 2) ^ galois(column[3], 3),
        galois(column[0], 3) ^ column[1] ^ column[2] ^ galois(column[3], 2)
    ]

def mixColumns(block):
    Array = bytearray(16)
    for i in range(4):
        column = [block[i * 4], block[i * 4 + 1], block[i * 4 + 2], block[i * 4 + 3]]
        mixed_column = mix(column)
        Array[i * 4], Array[i * 4 + 1], Array[i * 4 + 2], Array[i * 4 + 3] = mixed_column
    return bytes(Array)

def MixColumns(state):
    state_bytes = bytearray()
    for row in state:
        for byte in row:
            state_bytes.append(int(byte, 16))
    mixed_bytes = mixColumns(state_bytes)
    mixed_state = [[f'{mixed_bytes[i * 4 + j]:02x}' for j in range(4)] for i in range(4)]
    return mixed_state

def AddRoundKey(state, key):
    state_int = [[int(byte, 16) for byte in row] for row in state]
    key_int = [[int(byte, 16) for byte in row] for row in key]
    result = [[state_int[i][j] ^ key_int[i][j] for j in range(4)] for i in range(4)]
    return [[f'{byte:02x}' for byte in row] for row in result]

def aes_encrypt(message, key):
    sub_key = expand_key(key)
    state = AddRoundKey(message, sub_key[0])
    for i in range(1, 10):
        state = SubBytes(state)
        state = ShiftRows(state)
        state = MixColumns(state)
        state = AddRoundKey(state, sub_key[i])
    state = SubBytes(state)
    state = ShiftRows(state)
    state = AddRoundKey(state, sub_key[10])
    return state