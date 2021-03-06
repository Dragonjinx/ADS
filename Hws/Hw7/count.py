from math import floor
from math import log10

def Count_Sort(to_sort):
    
    to_count = [0] * max(to_sort)

    for i in to_sort:
        to_count[(i - 1)] += 1

    elements_before = to_count

    for i in range(1, (len(to_count))):
        elements_before[i] =  to_count[i] + to_count[i-1]

    sarted = [None] * len(to_sort)

    for i in reversed(to_sort):
        sarted [ to_count [ i - 1 ] - 1 ] = i
        to_count[ i - 1 ] -= 1
    
    return sarted

def Bucket_Sort(to_sort):

    bucket = []

    for i in range(len(to_sort)):
        bucket.append([])

    for i in to_sort:
        bucket[ int( floor( i ) ) ].append( i )

    for i in range(len(bucket)):
        bucket[i] = sorted(bucket[i]) #I am allowed to use any sort here

    final = []

    for i in range(len(bucket)):
        for j in bucket[i]:
            final.append(j)

    return final

def Radix_Count_Helper(a, p):
    return (((a % pow(10, p)) - (a % pow(10, (p - 1)))) / pow(10, (p - 1))) #formula to avoid 2 dimentional arrays.

def Radix_Count(to_sort, indx):

    to_count = [0] * 10

    if indx == 1:
        for i in to_sort:
            to_count[ i % 10 ] += 1

    else:
        for i in to_sort:
            to_count[ Radix_Count_Helper(i, indx) ] += 1

    elements_before = to_count

    for i in range(1, (len(to_count))):
        elements_before[i] =  to_count[i] + to_count[i-1]

    sarted = [None] * len(to_sort)

    for i in reversed(to_sort):
        sarted [ to_count [ Radix_Count_Helper(i, indx) ] - 1 ] = i
        to_count[ Radix_Count_Helper(i, indx) ] -= 1
    
    return sarted


def Radix_Sort(to_sort):

    max_iterations = int( floor( log10(max(to_sort)) ) )

    for i in range(1, max_iterations + 2):
        to_sort = Radix_Count(to_sort, i)

    return to_sort


"""
Ignore this please I forgot I had a time complexity limit.
def Radix_String_Num(to_sort):

    storage = []

    for i in to_sort:
        storage.append(list(i))

    for i in storage:
        for j in range(len(i)):
            i[j] = ord(i[j])    

    for i in range(len(storage):
        storage[i] = ''.join(map(str, storage[i]))
        storage[i] = map(int, storage[i])

    for i in range(len(to_sort)):
        storage[i] = [ storage[i], to_sort[i]]

    return to_sort
"""

def Helper(a):
    return ord(a) - 97

def get_val(a, d):
    if len(a) <= d:
        return a[len(a) - 1]
    else:
        return a[d]


def String_Count(to_sort, indx):
    
    to_count = [0] * 26

    for i in range(len(to_sort)):
        to_count[ Helper(get_val(to_sort[i], indx))] += 1

    elements_before = to_count

    for i in range(1, (len(to_count))):
        elements_before[i] =  to_count[i] + to_count[i-1]
    
    for i in range(26):
        if to_count[i] > 0:
           to_count[i] -= 1

    sarted = [None] * len(to_sort)

    for i in to_count:
        if i != 0:
            i -=1

    for i in list(range(len(to_sort))):
        sarted [to_count[Helper(get_val(to_sort[i], indx))]] = to_sort[i]
        to_count[Helper(get_val(to_sort[i], indx))] -= 1
    
    return sarted
    


def Radix_String(to_sort):
    longest = max(to_sort, key=len)
    k = len(longest)
    print(k)

    for i in range(k):
        print(i)
        to_sort = String_Count(to_sort, i)
        print(to_sort)

    return to_sort




a = [9, 1, 6, 7, 6, 2, 1]
b = [0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1]
c = [69420, 420, 69, 129]
d = [ 'word', 'category', 'cat', 'new', 'news', 'world', 'bear', 'at', 'work', 'time', 'hehe']

print 'Count sort on: ', a
this = Count_Sort(a)
print(this)

print 'Bucket sort on: ', b
that = Bucket_Sort(b)
print(that)

print 'Radix sort on: ', c 
theotherONe = Radix_Sort(c)
print(theotherONe)

print 'String sort on: ', d
wallo = Radix_String(d)
print(wallo)