class Node:
    def __init__(self, value):
        self.value = value
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def print_list(self):
        temp = self.head
        while temp is not None:
            print(temp.value)
            temp = temp.next

    def print_list_reverse(self):
        temp = self.tail
        while temp is not None:
            print(temp.value)
            temp = temp.prev

    def insert_front(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        self.length += 1
        return True

    def insert_back(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        self.length += 1
        return True

    def insert_after_node(self, key, value):
        temp = self.head
        while temp is not None:
            if temp.value == key:
                new_node = Node(value)
                new_node.prev = temp
                new_node.next = temp.next
                if temp.next:
                    temp.next.prev = new_node
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
        if self.length == 1:
            self.head = None
            self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        self.length -= 1

        return True

    def remove_head(self):
        if self.length == 0:
            return None
        temp = self.head
        self.head = self.head.next
        if self.head:
            self.head.prev = None
        else:
            self.tail = None
        temp.next = None
        self.length -= 1

        return True

    def remove_element(self, key):
        temp = self.head
        prev = None
        while temp is not None:
            if temp.value == key:
                if prev:
                    prev.next = temp.next
                else:
                    self.head = temp.next
                if temp.next:
                    temp.next.prev = prev
                else:
                    self.tail = prev
                temp.next = None
                self.length -= 1
                return True
            prev = temp
            temp = temp.next

        print("Key value not found")
        return False


mLinkedList = DoublyLinkedList()

mLinkedList.insert_front(23)
mLinkedList.insert_front(42)
mLinkedList.insert_front(87)

mLinkedList.insert_back(7)
mLinkedList.insert_back(10)

mLinkedList.insert_after_node(23, 99)

mLinkedList.remove_head()
mLinkedList.remove_element(42)
mLinkedList.print_list()
mLinkedList.print_list_reverse()
