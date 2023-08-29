def SortArray(newArray, array):
    for i in range(LengthofArray(array)):
        newArray.append(FindMinimum(array))
        array.remove(FindMinimum(array))

    return newArray


def LengthofArray(array):

    length = 0
    for i in array:
        length += 1

    return length


def FindMinimum(array):
    
    # TODO: Implement this function
    
    


if __name__ == "__main__":

    Sorted_Array = []
    SortArray(Sorted_Array, [8, 7, 2, 5, 3, 1, 8, 5])

    print(Sorted_Array)
