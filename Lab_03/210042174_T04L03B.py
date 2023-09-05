def find_next_seniors(ranks):
    n = len(ranks)
    next_seniors = [-1] * n
    stack = []

    for i in range(n):
        while stack and ranks[stack[-1]] < ranks[i]:
            next_seniors[stack.pop()] = ranks[i]
        stack.append(i)

    return next_seniors


if __name__ == "__main__":
    ranks = []
    print("Enter ranks (terminate with -1):")
    while True:
        rank = input()
        if rank == "-1":
            break
        ranks.append(int(rank))

    next_seniors = find_next_seniors(ranks)

    print("Next seniors by rank:")
    for i in range(len(ranks)):
        print(
            f"Person with rank {ranks[i]} is senior to Person with rank {next_seniors[i] if next_seniors[i] != -1 else 'None'}")
