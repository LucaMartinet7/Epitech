#!/usr/bin/env python3

import sys
from aes import aes_cipher
from rsa import rsa_cipher, generate_rsa_keys, reverse_pairs, format_key, rsa_decrypt, is_prime
from xor import xor_cipher, xor_decipher

def print_usage():
    print("USAGE")
    print("./my_pgp CRYPTO_SYSTEM MODE [OPTIONS] [key]")
    print("DESCRIPTION")
    print("The MESSAGE is read from standard input")
    print("CRYPTO_SYSTEM")
    print("    xor    computation using XOR algorithm")
    print("    aes    computation using 128-bit AES algorithm")
    print("    rsa    computation using RSA algorithm")
    print("    pgp-xor    computation using both RSA and XOR algorithm")
    print("    pgp-aes    computation using both RSA and 128-bit AES algorithm")
    print("MODE")
    print("    -c    MESSAGE is clear and we want to cipher it")
    print("    -d    MESSAGE is ciphered and we want to decipher it")
    print("    -g    P Q for RSA only: Don't read a MESSAGE, but instead generate a public and private key pair from the prime number P and Q")
    print("OPTIONS")
    print("    -b    for XOR, AES and PGP, only works on one block. The MESSAGE and the symmetric key must be the same size")
    print("key    Key used to cipher/decipher MESSAGE (incompatible with -g MODE)")

def handle_error(message):
    print(f"Error: {message}")
    sys.exit(84)

def validate_arguments_length(expected_length, actual_length):
    if actual_length != expected_length:
        handle_error(f"Expected {expected_length} arguments, but got {actual_length}")

def is_hex_key(key):
    try:
        int(key, 16)
        return True
    except ValueError:
        return False

def main():
    if len(sys.argv) < 3:
        print_usage()
        sys.exit(0)

    crypto_system = sys.argv[1]
    mode = sys.argv[2]

    if crypto_system not in ['xor', 'aes', 'rsa']:
        handle_error("Invalid CRYPTO_SYSTEM. Must be 'xor', 'aes', or 'rsa'.")

    if mode not in ['-c', '-d', '-g']:
        handle_error("Invalid MODE. Must be '-c', '-d', or '-g'.")

    if mode != '-g':
        message = sys.stdin.read().strip()
        if not message:
            handle_error("Message cannot be empty.")

    if crypto_system in ["xor", "aes"]:
        block_mode = "-b" in sys.argv
        key_index = sys.argv.index("-b") + 1 if block_mode else 3

        try:
            key = sys.argv[key_index]
            if not is_hex_key(key):
                handle_error("Key must be a hexadecimal number.")
        except IndexError:
            handle_error("Key not provided or insufficient arguments.")

        if crypto_system == "xor":

            if mode == "-c":
                print(xor_cipher(message, key))
            elif mode == "-d":
                print(xor_decipher(message, key))
            else:
                handle_error("Invalid MODE for XOR.")
        elif crypto_system == "aes":
            aes_cipher(message, key, mode, block_mode)

    elif crypto_system == "rsa":
        if mode == "-g":
            validate_arguments_length(5, len(sys.argv))
            try:
                p = int(reverse_pairs(sys.argv[3]), 16)
                q = int(reverse_pairs(sys.argv[4]), 16)
                if not is_prime(p) or not is_prime(q):
                    handle_error("Invalid prime numbers for RSA key generation.")
            except ValueError:
                handle_error("Invalid prime numbers for RSA key generation.")
            public_key, private_key = generate_rsa_keys(p, q)
            print("public key:", format_key(*public_key))
            print("private key:", format_key(*private_key))
        elif mode == "-c":
            validate_arguments_length(4, len(sys.argv))
            key = sys.argv[3]
            ciphered_text = rsa_cipher(message, key)
            print(ciphered_text)
        elif mode == "-d":
            validate_arguments_length(4, len(sys.argv))
            key = sys.argv[3]
            decipher_text = rsa_decrypt(message, key)
            print(decipher_text)
        else:
            handle_error("Invalid MODE for RSA.")
    else:
        handle_error("Invalid CRYPTO_SYSTEM selected.")

if __name__ == "__main__":
    main()
