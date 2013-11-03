
def find_k(numbers):
    k = -1
    for idx, number in enumerate(numbers):
        if idx == len(numbers)-1: # len is from 1 idx is from 0
            break
        if numbers[idx] < numbers[idx+1]:
            k = idx
    return k

def find_l(k, numbers):
    l = -1
    for idx, number in enumerate(numbers):
        if numbers[k] < numbers[idx]:
            l = idx
    return l

def swap(k, l, numbers):
    tmp = numbers[k]
    numbers[k] = numbers[l]
    numbers[l] = tmp
    return numbers

def permute(numbers):
    k = -1
    l = -1
    k = find_k(numbers)
    if k == -1: # we've found everything
        return None
    l = find_l(k, numbers)
    numbers = swap(k, l, numbers)
    numbers[k+1:len(numbers)] = reversed(numbers[k+1:len(numbers)])
    return numbers          

def main():
    numbers = [x for x in range(10)]
    it = 1
    print numbers
    ret = numbers
    while ret is not None:
        if it == 1000000:
            print it, ''.join(map(str,ret))
        ret = permute(ret)
        it += 1
    


if __name__ == "__main__":
    main()
 
