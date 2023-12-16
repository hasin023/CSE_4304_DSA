def CheckParenthesis(s):
    stack = []
    for i in s:
        if i == "(" or i == "{" or i == "[":
            stack.append(i)
        elif i == ")" or i == "}" or i == "]":
            if len(stack) == 0:
                print("No")
                return
            elif i == ")" and stack[-1] == "(":
                stack.pop()
            elif i == "}" and stack[-1] == "{":
                stack.pop()
            elif i == "]" and stack[-1] == "[":
                stack.pop()
            else:
                print("No")
                return

    if len(stack) == 0:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":

    testCases = int(input())

    for i in range(testCases):
        s = input()
        CheckParenthesis(s)
