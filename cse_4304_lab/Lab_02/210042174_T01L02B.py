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

    def get(self, index):
        if index < 0 or index >= self.length:
            return None
        temp = self.head
        for _ in range(index):
            temp = temp.next
        return temp

    def insert_front(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head = new_node
        self.length += 1
        return True

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

    def insert_after_node(self, key, value):
        temp = self.head
        while temp is not None:
            if temp.value == key:
                new_node = Node(value)
                new_node.next = temp.next
                temp.next = new_node
                self.length += 1
                return True
            temp = temp.next

        print("Key value not found")
        return False

    def update_node(self, key, value):
        temp = self.head
        while temp is not None:
            if temp.value == key:
                temp.value = value
                return True
            temp = temp.next

        print("Key value not found")
        return False

    def remove_end(self):
        if self.length == 0:
            return None
        temp = self.head
        prev = self.head
        while temp.next is not None:
            prev = temp
            temp = temp.next
        self.tail = prev
        self.tail.next = None
        self.length -= 1

        return True

    def remove_head(self):
        temp = self.head
        self.head = self.head.next
        temp.next = None
        self.length -= 1

        return True

    def remove_element(self, key):
        temp = self.head
        prev = self.head
        while temp is not None:
            if temp.value == key:
                prev.next = temp.next
                temp.next = None
                self.length -= 1
                return True
            prev = temp
            temp = temp.next

        print("Key value not found")
        return False


mLinkedList = LinkedList()

mLinkedList.insert_front(23)
mLinkedList.insert_front(42)
mLinkedList.insert_front(87)

mLinkedList.insert_back(7)
mLinkedList.insert_back(10)

mLinkedList.insert_after_node(23, 99)
mLinkedList.update_node(9, 100)

mLinkedList.remove_end()
mLinkedList.remove_head()
mLinkedList.remove_element(3)

mLinkedList.print_list()
