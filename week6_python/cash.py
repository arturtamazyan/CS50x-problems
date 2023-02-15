money = -1
while (money < 0):
    try:
        money = float(input('Change owed: '))
    except:
        if not isinstance(money, int):
            continue

coins_25 = round(money // 0.25, 3)
money = round(money - 0.25 * coins_25, 3)

coins_10 = round(money // 0.1)
money = round(money - 0.1 * coins_10, 3)

coins_5 = round(money // 0.05, 10)
money = round(money - 0.05 * coins_5, 3)

coins_1 = round(money // 0.01, 10)
money = round(money - 0.01 * coins_1, 3)

print(int(coins_25 + coins_10 + coins_5 + coins_1))
