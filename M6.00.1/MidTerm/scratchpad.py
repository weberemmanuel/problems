def is_list_permutation(L1, L2):
    '''
    L1 and L2: lists containing integers and strings
    Returns False if L1 and L2 are not permutations of each other.
            If they are permutations of each other, returns a
            tuple of 3 items in this order:
            the element occurring most, how many times it occurs, and its type
    '''
    L3 = L2[:]
    for a in L1:
        if a in L3:
            L3.remove(a)
        else:
            return False
    if len(L3) >0:
        return False

    dir = {}
    for elem in L1:
        count = dir.get(elem,0)
        dir[elem]=count+1
    max_val  = None
    max_elem = None
    max_type = None
    for entry in dir.keys():
        if max_val == None or dir[entry] > max_val:
            max_val = dir[entry]
            max_elem = entry
            max_type = type(entry)
    return (max_elem,max_val,max_type)

print(is_list_permutation(['a', 'a', 'b'],['a', 'b']))
print(is_list_permutation([1, 'b', 1, 'c', 'c', 1],['c', 1, 'b', 1, 1, 'c']))

def general_poly (L):
    """ L, a list of numbers (n0, n1, n2, ... nk)
    Returns a function, which when applied to a value x, returns the value
    n0 * x^k + n1 * x^(k-1) + ... nk * x^0 """
    def poly_func(x):
        val = 0
        degree = len(L)
        for k in range(degree):
            val += L[k] * x**(degree-k-1)
        return val
    return poly_func

#print(general_poly([1, 2, 3, 4])(10))


def dict_invert(d):
    '''
    d: dict
    Returns an inverted dictionary according to the instructions above
    '''
    id = {}
    for val in set(d.values()):
        id[val] = []

    for key in d.keys():
        id[d[key]].append(key)

    for key in id.keys():
        id[key].sort()

    return id

#print(dict_invert({1:10, 2:20, 3:30}))
#print(dict_invert({1:10, 2:20, 3:30, 4:30}))
#print(dict_invert({4:True, 2:True, 0:True}))

def largest_odd_times(L):
    """ Assumes L is a non-empty list of ints
        Returns the largest element of L that occurs an odd number
        of times in L. If no such element exists, returns None """

    max_elem = None
    for e in L:
        if L.count(e) % 2 == 1 and (max_elem == None or e > max_elem):
            max_elem = e
    return max_elem

#print(largest_odd_times([2,2,4,4]))
#print(largest_odd_times([3,9,5,3,5,3]))


def print_without_vowels(s):
    '''
    s: the string to convert
    Finds a version of s without vowels and whose characters appear in the
    same order they appear in s. Prints this version of s.
    Does not return anything
    '''
    print(''.join([x for x in s if x not in ['a','e','i','o','u','A','E','I','O','U']]))

#print_without_vowels('')
#print_without_vowels('a')
#print_without_vowels('b')
#print_without_vowels('This is a funny function')


def is_triangular(k):
    """
    k, a positive integer
    returns True if k is triangular and False if not
    """
    for n in range(k+1):
        count = 0
        for i in range(n+1):
            count +=i
        if count == k:
            return True
    return False

#print(is_triangular(1))
#print(is_triangular(2))
#print(is_triangular(3))
#print(is_triangular(9))
#print(is_triangular(10))
