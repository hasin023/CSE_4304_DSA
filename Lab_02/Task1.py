class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self, value):
        new_node = Node(value)
        self.head = new_node
        self.tail = new_node
        self.length = 1

    def print_list(self):
        temp = self.head
        while temp is not None:
            print(temp.value)
            temp = temp.next

    def Insert_back(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.length += 1
        return True

    def Insert_front(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head = new_node
        self.length += 1
        return True

    def Insert_after_node(self, key, value):
        new_node = Node(value)
        temp = self.head
        while temp is not None:
            if temp.value == key:
                new_node.next = temp.next
                temp.next = new_node
                self.length += 1
                return True
            temp = temp.next

        print("Key value not found")
        return False

    def Update_node(self, key, value):
        temp = self.head
        while temp is not None:
            if temp.value == key:
                temp.value = value
                return True
            temp = temp.next

        print("Key value not found")
        return False

    def Remove_end(self):
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

    def Remove_head(self):
        temp = self.head
        self.head = self.head.next
        temp.next = None
        self.length -= 1

        return True

    def Remove_element(self, key):
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


mLinkedList = LinkedList(3)

mLinkedList.Insert_front(42)
mLinkedList.Insert_front(87)
mLinkedList.Insert_after_node(7, 99)

mLinkedList.Insert_back(7)
mLinkedList.Insert_back(13)

mLinkedList.Update_node(133, 100)

mLinkedList.Remove_end()
mLinkedList.Remove_head()
mLinkedList.Remove_element(7)

mLinkedList.print_list()
