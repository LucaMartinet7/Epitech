from aes_encrypt import aes_encrypt
from aes_decrypt import aes_decrypt
from error import handle_error

def hex2revmatrix(hex_string):
    hex_list = [hex_string[i:i+2] for i in range(0, len(hex_string), 2)]
    if len(hex_list) != 16 and len(hex_list) != 32:
        handle_error("Hex string must represent exactly 16 bytes")
    hex_list.reverse()
    block_matrix = []
    for i in range(4):
        block_matrix.append(hex_list[i*4:(i+1)*4])
    for i in range(2):
        block_matrix[i], block_matrix[3 - i] = block_matrix[3 - i], block_matrix[i]
    return block_matrix

def revmatrix2hex(matrix):
    for i in range(2):
        matrix[i], matrix[3 - i] = matrix[3 - i], matrix[i]
    hex_list = [item for sublist in matrix for item in sublist]
    hex_list.reverse()
    return ''.join(hex_list)

def rev_matrix(matrix):
    for row in matrix:
        row.reverse()
    return matrix

def hex2matrix(hex_string):
    hex_list = [hex_string[i:i+2] for i in range(0, len(hex_string), 2)]
    if len(hex_list) != 16 and len(hex_list) != 32:
        handle_error("Invalid hex string")
    block_matrix = []
    for i in range(4):
        block_matrix.append(hex_list[i*4:(i+1)*4])
    return block_matrix

def reverse_hex(s):
    result = []
    for i in range(0, len(s), 2):
        pair = s[i:i+2]
        result.insert(0, pair)
    return ''.join(result)

def pad_message(message1, message2):
    len1 = len(message1)
    len2 = len(message2)
    if len1 == len2:
        return message1, message2
    elif len1 > len2:
        padding_length = len1 - len2
        padding = '0' * padding_length
        return message1, message2 + padding
    else:
        padding_length = len2 - len1
        padding = '0' * padding_length
        return message1 + padding, message2

def str2hex(input_string):
    hex_string = ''.join(format(ord(c), 'x') for c in input_string)
    return hex_string

def hex_to_string(hex_string):
    bytes_object = bytes.fromhex(hex_string)
    return bytes_object.decode("latin-1")

def matrix2hex(matrix):
    hex_string = ''.join([''.join(row) for row in matrix])
    return hex_string

def aes_cipher(message, key, mode, block_mode):
    if mode == "-c":
        hex_message = str2hex(message)
        if block_mode:
            hex_message, key = pad_message(hex_message, key)
        key = hex2revmatrix(key)
        hex_message = hex2matrix(hex_message)
        crypt = aes_encrypt(hex_message, key)
        crypt_hex = revmatrix2hex(crypt)
        print(crypt_hex)
    elif mode == "-d":
        if block_mode:
            message, key = pad_message(message, key)
        key = hex2revmatrix(key)
        message = hex2matrix(message)
        message = rev_matrix(message)
        decrypted_matrix = aes_decrypt(message, key)
        decrypted_hex = matrix2hex(decrypted_matrix)
        print(hex_to_string(decrypted_hex))
    else:
        handle_error("Invalid mode")