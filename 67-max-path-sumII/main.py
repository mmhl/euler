file_name = "triangle.txt"

# This is main routine for reading file.
# Returs list of lists of numbers read per line
def read_input():
  f = open(file_name, "r")
  lines_list = []
  line_list = []
  int_list = []
  for line in f:
    line_list = line.split()
    for number in line_list:
      int_list.append(int(number))
    lines_list.append(int_list)
    int_list = []
  return lines_list

def print_pyramid(numbers):
	for line in numbers:
		for number in line:
			print number,
		print

#sum biggest number neighbours
def sum_biggest(numbers):
	if len(numbers) == 1:
		return numbers[0]
	current = numbers[-2]
	previous = numbers[-1]
	best_row= []
	for j in range(0, len(current)):
		best = max(current[j]+previous[j], current[j]+previous[j+1])
		best_row.append(best)
	del numbers[-1]
	del numbers[-1]
	numbers.append(best_row)
	return sum_biggest(numbers)
	

def main():
  print sum_biggest(read_input())
  
  
  
  
if __name__ == "__main__":
  main()
