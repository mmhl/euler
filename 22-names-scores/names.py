import string
def sort():
    f_input = open("names.txt", "r")
    line = f_input.read()
    ret = line.replace('"', "").replace(',', " ").split()
    ret.sort()
    return ret
def main():
    _sorted = sort()
    total_sum = 0
    offset = 1 #
    for idx, name in enumerate(_sorted):
        position = idx + offset
        letter_sum = sum(string.lowercase.index(x)+offset for x in name.lower())
        score = position*letter_sum
        #print name, position, letter_sum, score
        total_sum += score
    return total_sum

if __name__ == "__main__":
    total = main()
    print total
    
