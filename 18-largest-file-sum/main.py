file_name = "input.txt"

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

#sum biggest number neighbours
def sum_biggest(numbers):
  last_index = 0
  neighbour_left = 0
  neighbour_right = 0
  for line in numbers:
    for number in line:
      last_index = line.index(number)
      neighbour_left = last_index
      neighbour_right = neighbour_left + 1
      print "New neighbours for number " + str(number) +" are here: ", neighbour_left, neighbour_right
  

def main():
  sum_biggest(read_input())
  
  
  
  
if __name__ == "__main__":
  main()