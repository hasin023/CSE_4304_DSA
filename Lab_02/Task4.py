class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def print_list(self):
        temp = self.head
        while temp is not None:
            print(temp.value)
            temp = temp.next

    def insert_back(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.length += 1
        return True

    def remove_duplicates(self):
        if self.head is None:
            return

        current = self.head
        while current.next:
            if current.value == current.next.value:
                current.next = current.next.next
            else:
                current = current.next


mLinkedList = LinkedList()

while True:
    value = input("Enter a value (-1 to Stop): ")
    if value == "-1":
        break
    mLinkedList.insert_back(value)


mLinkedList.remove_duplicates()
print("Linked list with duplicates removed:")
mLinkedList.print_list()
