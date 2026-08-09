import sys

class BotState:
    def __init__(self):
        self.stacks = {}
        self.charts = {}

    def update_settings(self, key, value):
        if key == "timebank":
            self.timebank = int(value)
        elif key == "initial_stack":
            self.initial_stack = int(value)
        elif key == "candles_given":
            self.candles_given = int(value)

    def update_game(self, key, value):
        if key == "stacks":
            for stack in value.split(","):
                currency, amount = stack.split(":")
                self.stacks[currency] = float(amount)
        elif key == "next_candles":
            candles_info = value.split(";")
            for candle_info in candles_info:
                candle_data = candle_info.split(",")
                pair = candle_data[0]
                if pair not in self.charts:
                    self.charts[pair] = Chart()
                candle = Candle(candle_data)
                self.charts[pair].add_candle(candle)

class Bot:
    def __init__(self):
        self.botState = BotState()

    def run(self):
        while True:
            reading = input()
            if reading:
                self.parse(reading)

    def parse(self, info):
        tmp = info.split(" ")
        if tmp[0] == "settings":
            self.botState.update_settings(tmp[1], tmp[2])
        elif tmp[0] == "update" and tmp[1] == "game":
            self.botState.update_game(tmp[2], tmp[3])
        elif tmp[0] == "action":
            dollars = self.botState.stacks.get("USDT", 0)
            btc_chart = self.botState.charts.get("USDT_BTC")
            if btc_chart:
                current_closing_price = btc_chart.closes[-1]
                affordable = dollars / current_closing_price
                print(f'My stacks are {dollars}. The current closing price is {current_closing_price}. So I can afford {affordable}', file=sys.stderr)
                if all(btc_chart.opens[-i] > btc_chart.opens[-i-1] for i in range(1, 6)):
                    self.buy_btc(0.87 * affordable)
                else:
                    self.sell_btc()

    def buy_btc(self, amount):
        if amount > 0:
            print(f'buy USDT_BTC {amount}', flush=True)

    def sell_btc(self):
        if self.botState.stacks.get("BTC", 0) > 0:
            print(f'sell USDT_BTC {self.botState.stacks["BTC"]}', flush=True)
        else:
            print(f'no_moves', flush=True)

class Candle:
    def __init__(self, data):
        self.pair = data[0]
        self.date = int(data[1])
        self.high = float(data[2])
        self.low = float(data[3])
        self.open = float(data[4])
        self.close = float(data[5])
        self.volume = float(data[6])

class Chart:
    def __init__(self):
        self.opens = []
        self.closes = []

    def add_candle(self, candle):
        self.opens.append(candle.open)
        self.closes.append(candle.close)

if __name__ == "__main__":
    mybot = Bot()
    mybot.run()
