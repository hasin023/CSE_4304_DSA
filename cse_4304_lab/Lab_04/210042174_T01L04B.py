class Queue:
    def __init__(self, maxSize):
        self.items = maxSize * [None]
        self.maxSize = maxSize
        self.start = -1
        self.end = -1

    def __str__(self):
        values = [str(x) for x in self.items]
        return ' '.join(values)

    def isFull(self):
        if self.end + 1 == self.start:
            return True
        elif self.start == 0 and self.end + 1 == self.maxSize:
            return True
        else:
            return False

    def isEmpty(self):
        if self.end == -1:
            return True
        else:
            return False

    def Enqueue(self, value):
        if self.isFull():
            return "The queue is full"
        else:
            if self.end + 1 == self.maxSize:
                self.end = 0
            else:
                self.end += 1
                if self.start == -1:
                    self.start = 0
            self.items[self.end] = value
            return "The element is inserted at the end of Queue"

    def Dequeue(self):
        if self.isEmpty():
            return "There is no element in the Queue"
        else:
            firstElement = self.items[self.start]
            start = self.start
            if self.start == self.end:
                self.start = -1
                self.end = -1
            elif self.start + 1 == self.maxSize:
                self.start = 0
            else:
                self.start += 1
            self.items[start] = None
            return firstElement

    def Front(self):
        if self.isEmpty():
            return "There is no element in the Queue"
        else:
            return self.items[self.start]

    def Rear(self):
        if self.isEmpty():
            return "There is no element in the Queue"
        else:
            return self.items[self.end]


myQueue = Queue(6)
myQueue.Enqueue(1)
myQueue.Enqueue(2)
myQueue.Enqueue(3)
myQueue.Enqueue(4)
myQueue.Enqueue(5)
myQueue.Enqueue(6)

myQueue.Dequeue()
myQueue.Dequeue()

print(myQueue)

print("Front: " + str(myQueue.Front()))
print("Rear: " + str(myQueue.Rear()))

print("Is Full? " + str(myQueue.isFull()))
print("Is Empty? " + str(myQueue.isEmpty()))
