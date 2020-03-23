from math import floor

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




this = Count_Sort([9, 1, 6, 7, 6, 2, 1])
print(this)

that = Bucket_Sort([0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1])
print(that)