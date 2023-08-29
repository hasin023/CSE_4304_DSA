import random


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


middleNode = None


def generator():
    random.seed()
    listSize = random.randint(1, 10000)
    start = ListNode(random.randint(0, 10000))
    ptr = start
    for i in range(1, listSize):
        newNode = ListNode(random.randint(0, 10000))
        ptr.next = newNode
        ptr = ptr.next

    middle = listSize // 2
    ptr = start
    for _ in range(middle):
        ptr = ptr.next
    global middleNode
    middleNode = ptr
    return start


def findMiddleNode(head):
    """
    Find the middleNode of the given linked List. If there are two middle nodes, consider the second as middle.
    [1,2,3,4] middle is 3
    [1,2,3] middle is 2
    You can traverse the list only once. No extra data structure like an array or STL.
    Time Complexity O(n), Extra Space Complexity O(1).
    """
    # Write your solution here:


HEAD = generator()
RET = findMiddleNode(HEAD)
if RET == middleNode:
    print("Success")
else:
    print("Failure")
