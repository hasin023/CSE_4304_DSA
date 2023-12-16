def FindPair(array, target):

    pair_dictionary = {}
    arrayLength = LengthofArray(array)

    for i in range(arrayLength):
        if (target - array[i]) in pair_dictionary:
            return [pair_dictionary[(target - array[i])], i]
        else:
            pair_dictionary[array[i]] = i

    return -1


def LengthofArray(array):

    length = 0
    for i in array:
        length += 1

    return length


if __name__ == "__main__":

    givenArray = [8, 7, 2, 5, 3, 1]
    target = 10

    print(FindPair(givenArray, target))
