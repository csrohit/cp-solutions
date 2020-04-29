# class SinglyLinkedListNode:
#     def __init__(self, data):
#         self.data = data
#         self.next = None
#
# class SinglyLinkedList:
#     def __init__(self):
#         self.head = None
#         self.tail = None
#
#     def insertNode(self, data):
#         node = SinglyLinkedListNode(data)
#         if self.head is None:
#             self.head = node
#         else:
#             self.tail.next = node
#         self.tail = node
#
# def printLinkedList(head):
#     curr = head
#     while curr is not None:
#         print(curr.data)
#         curr = curr.next
#
#
# def reverse(head):
#     prev = None
#     curr = head
#
#     while curr is not  None:
#         nxt = curr.next
#         curr.next = prev
#         prev = curr
#         curr = nxt
#     return prev
#
# if __name__ == '__main__':
#
#     ll = SinglyLinkedList()
#     for i in range(4):
#         ll.insertNode(i)
#
#     # printLinkedList(ll.head)
#     head1 = reverse(ll.head)
#     printLinkedList(head1)


#!/bin/python3

import math
import os
import random
import re
import sys

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node


        self.tail = node

def print_singly_linked_list(node, sep, fptr):
    while node:
        fptr.write(str(node.data))

        node = node.next

        if node:
            fptr.write(sep)

# Complete the reverse function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def reverse(head):
    prev = None
    curr = head
    while curr is not None:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next
    return prev

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    tests = int(input())

    for tests_itr in range(tests):
        llist_count = int(input())

        llist = SinglyLinkedList()

        for _ in range(llist_count):
            llist_item = int(input())
            llist.insert_node(llist_item)

        llist1 = reverse(llist.head)

        print_singly_linked_list(llist1, ' ', fptr)
        fptr.write('\n')

    fptr.close()
