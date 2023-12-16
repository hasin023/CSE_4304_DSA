class Stack:
    def __init__(self, size):
        self.items = []
        self.size = size

    def push(self, item):
        length = 0

        for i in self.items:
            length += 1

        if length == self.size:
            print("Overflow")
        else:
            self.items = [item] + self.items

    def pop(self):
        if not self.is_empty():
            item = self.items[-1]
            del self.items[-1]
            return item
        else:
            return "Underflow"

    def top(self):
        if self.isEmpty():
            return "Underflow"
        else:
            return self.items[0]

    def isEmpty(self):
        if self.items == []:
            return True
        else:
            return False

    def isFull(self):
        length = 0

        for i in self.items:
            length += 1

        if length == self.size:
            return True
        else:
            return False

    def size(self):
        count = 0
        for i in self.items:
            count += 1
        return count


myStack = Stack(5)
myStack.push(1)
myStack.push(2)
myStack.push(3)

print(myStack.pop())

print(myStack.top())

print(myStack.isEmpty())
print(myStack.isFull())

print(myStack.size())


print(myStack.items)
