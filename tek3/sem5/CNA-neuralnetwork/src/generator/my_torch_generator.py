#!/usr/bin/env python3

import sys

from src.generator.generate import Generator

if __name__ == '__main__':
    gen = Generator(sys.argv)
    gen.run()
