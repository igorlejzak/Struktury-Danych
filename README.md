# Data Structures — University Project

C++ implementations of data structures from scratch (no STL), with benchmarking
and performance analysis. Built as part of the Data Structures course at
Wrocław University of Technology.

Developed in pairs with [Damian](https://github.com/damian5066).

---

## Mini-project 1 — Lists
Dynamic array, singly linked list, and doubly linked list.
Operations: add/remove at front, back, random position, search.
Benchmark: 20 averaged measurements per operation per size (5k–100k elements).

## Mini-project 2 — Priority Queue *(in progress)*
MAX priority queue implemented with two data structures (one must be a heap).
Operations: insert, extract-max, find-max, modify-key, return-size.

## Mini-project 3 — Hash Table *(in progress)*
Dictionary based on hash tables with collision resolution.
Operations: insert, remove.

---

## How to run (Mini-project 1)
```bash
g++ -O2 -o main main.cpp ArrayList.cpp SinglyList.cpp DoublyList.cpp
./main
```
