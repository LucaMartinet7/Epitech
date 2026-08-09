from predefined import sbox, rcon

def expand_key(key_matrix):
    key_matrix = [[int(byte, 16) for byte in row] for row in key_matrix]
    N = 4
    R = 11
    expanded_key = [key_matrix[i][:] for i in range(4)]

    for i in range(N, 4 * R):
        temp = expanded_key[-1][:]
        if i % N == 0:
            temp = SubWord(RotWord(temp))
            temp[0] ^= rcon[i // N - 1]
        for j in range(4):
            temp[j] ^= expanded_key[i - N][j]
        expanded_key.append(temp)

    expanded_key_matrix = [expanded_key[i:i + 4] for i in range(0, len(expanded_key), 4)]

    return [[[f'0x{byte:02x}' for byte in row] for row in block] for block in expanded_key_matrix]

def RotWord(word):
    return word[1:] + word[:1]

def SubWord(word):
    return [sbox[byte] for byte in word]
