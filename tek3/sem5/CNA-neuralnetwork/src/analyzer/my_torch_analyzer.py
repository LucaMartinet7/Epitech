#!/usr/bin/env python3

import sys

from src.analyzer.analyze import NeuralNetworkAnalyzer

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Error: insufficient arguments.", file=sys.stderr)
        print("Use --help for usage information.", file=sys.stderr)
        sys.exit(84)
    analyze = NeuralNetworkAnalyzer(sys.argv)
    analyze.execute()