def xor_bytes(data, key_bytes):
    block_size = len(key_bytes)
    padded_data = data + b'\x00' * ((block_size - len(data) % block_size) % block_size)
    return bytes(data[i] ^ key_bytes[i % block_size] for i in range(len(padded_data)))

def xor_cipher(message, key):
    message_bytes = message.encode('utf-8')[::-1]
    key_bytes = bytes.fromhex(key)
    cipher_bytes = xor_bytes(message_bytes, key_bytes)
    return cipher_bytes.hex()

def xor_decipher(cipher_hex, key):
    cipher_bytes = bytes.fromhex(cipher_hex)
    key_bytes = bytes.fromhex(key)
    decrypted_bytes = xor_bytes(cipher_bytes, key_bytes)
    return decrypted_bytes.rstrip(b'\x00')[::-1].decode('utf-8')
