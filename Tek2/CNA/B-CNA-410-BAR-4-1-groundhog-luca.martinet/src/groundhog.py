#!/usr/bin/env python3

##
## EPITECH PROJECT, 2024
## B-CNA-410-BAR-4-1-groundhog-luca.martinet
## File description:
## groundhog
##

import sys
import math

class GroundHog:
    def __init__(self):
        self.tabWeird = []
        self.nb = 0
        self.increment = 0
        self.lastsign = False
        self.switchTime = 0
        self._r = float(0)
        self._g = float(0)
        self._s = float(0)

    def print_weirdest_value(self):
        print(f"Global tendency switched {self.switchTime} times")
        res = 0
        if len(self.tabWeird) - 2 > 4:
            res = 5
        elif len(self.tabWeird) - 2 > 0:
            res = len(self.tabWeird) - 2
        else:
            res = 0
        if len(self.tabWeird) > 2:
            print(f"{res} weirdest values are ", end="")
            self.get_weirdest_value()
        else:
            print("no weirdest value")

    def get_weirdest_value(self):
        weird_val = []
        for third in range(2, min(self.increment, len(self.tabWeird))):
            first = max(0, third - 2)
            predict = (self.tabWeird[first] + self.tabWeird[third]) / 2
            weird_val.append((abs(predict - self.tabWeird[third - 1]), self.tabWeird[third - 1]))
        weird_val.sort(key=lambda x: x[0], reverse=True)
        print("[", end="")
        try:
            if len(weird_val) > 0:
                print(f"{weird_val[0][1]:.1f}", end="")
                for i in range(1, min(len(weird_val), 5)):
                    print(f", {weird_val[i][1]:.1f}", end="")
        except IndexError:
            print("Not enough data to select the top 5 weirdest values.")
        print("]")

    def create_tab(self, number, index):
        self.tabWeird.append(number)
        if self.nb > index:
            del self.tabWeird[0]
        self.increment += 1

    def calc_s(self, index):
        if len(self.tabWeird) >= index:
            if index == 0:
                print("\t\ts=nan", end=' ')
                return
            res_tab = sum(self.tabWeird[-index:]) / index
            x = [(val - res_tab) ** 2 for val in self.tabWeird[-index:]]
            res_x = sum(x)
            result = math.sqrt(res_x / index)
            print(f"\t\ts={result:.2f}", end=' ')
        else:
            print("\t\ts=nan", end=' ')

    def calc_g(self, index):
        total_increase = 0
        for i in range(len(self.tabWeird) - 1, 0, -1):
            increase = self.tabWeird[i] - self.tabWeird[i - 1]
            if increase > 0:
                total_increase += increase
        if index == 0:
            print("g=0", end=' ')
        else:
            average_increase = total_increase / float(index)
            print(f"g={average_increase:.2f}", end=' ')

    def calc_r(self, index):
        difference = self.tabWeird[index] - self.tabWeird[0]
        if self.tabWeird[0] == 0:
            print("\t\tr=0%", end=' ')
            self._r = float(0)
        else:
            self._r = difference / abs(self.tabWeird[0]) * 100
            print(f"\t\tr={self._r:.0f}%", end=' ')
        self.calc_s(index)
        if not math.isinf(self._r) and self._r != -math.inf:
            currentsign = self._r > 0 if self._r != 0 else self.lastsign
            if self.lastsign != currentsign and self.nb > index + 1:
                print("\t\ta switch occurs", end=' ')
                self.switchTime += 1
            self.lastsign = currentsign

    def calculate(self, index, number, verif):
        if index == 0:
            print("g=0\t\tr=0%\t\ts=nan")
            return
        if not verif:
            self.create_tab(number, index)
            if len(self.tabWeird) < index:
                print("g=nan\t\tr=nan%\t\ts=nan")
            elif len(self.tabWeird) == index:
                print("g=nan\t\tr=nan%", end=' ')
                self.calc_s(index)
                print()
            else:
                self.calc_g(index)
                self.calc_r(index)
                print()
            self.nb += 1

    def groundhog(index):
        gh = GroundHog()
        while True:
            try:
                str_input = input()
            except KeyboardInterrupt:
                sys.exit(0)
            except EOFError:
                sys.exit(84)
            except KeyError:
                sys.exit(84)
            if str_input == "STOP":
                if gh.nb < index:
                    print("Not enough values to compute the average", file=sys.stderr)
                    sys.exit(84)
                gh.print_weirdest_value()
                break
            else:
                try:
                    number = float(str_input)
                except ValueError:
                    sys.exit(84)
                gh.calculate(index, number, False)

def parse():
    try:
        period = int(sys.argv[1])
        if period < 0:
            print("Error: Invalid period. Please enter a positive integer.", file=sys.stderr)
            sys.exit(84)
        return period
    except ValueError:
        print("Error: Invalid period. Please enter a positive integer.", file=sys.stderr)
        sys.exit(84)

def main():
    try:
        if len(sys.argv) != 2:
            print("Usage: python3 groundhog.py period", file=sys.stderr)
            sys.exit(84)

        if sys.argv[1] == "-h" or sys.argv[1] == "--help":
            help()
        period = parse()
        GroundHog.groundhog(period)
    except Exception as e:
        print(f"An error occurred: {e} ", file=sys.stderr)
        sys.exit(84)
    sys.exit(0)

if __name__ == "__main__":
    main()
