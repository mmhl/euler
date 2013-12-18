def main():
	for x in range(1,10000000):
		digits = str(x)
		powers = [pow(int(p), 5) for p in digits]
		for power in reversed(powers):
			if power >= x:
				continue
		if sum(powers) == x:
			print x 
			
  
  
  
  
if __name__ == "__main__":
  main()
