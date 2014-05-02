

coins = [1, 2, 5, 10, 20, 50, 100, 200]

def get_change(value, coins_amount):
	if(value == 0 ): #hit
		return 1
	if(value < 0):
		return 0
	if(coins_amount <= 0 and value >= 1):
		return 0
	return get_change(value, coins_amount-1) + get_change(value-coins[coins_amount-1], coins_amount)

def main():
	print get_change(200, len(coins))



if __name__ == "__main__": main()