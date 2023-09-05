def RemoveRepeated(s):
    stack = []
    for i in s:
        if stack == [] or stack[-1] != i:
            stack.append(i)
        elif stack[-1] == i:
            stack.pop()

    return stack


def StackToString(stack):
    string = ""
    for i in stack:
        string += i
    return "[" + string + "]"


if __name__ == "__main__":

    testCases = int(input())

    for i in range(testCases):
        s = input()

        result = StackToString(RemoveRepeated(s))
        print(result)
