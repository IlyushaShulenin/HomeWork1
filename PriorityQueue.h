#pragma once

#include <vector>
#include <iostream>

using std::cout;
using std::vector;

template <typename T>
class PriorityQueue {
private:
    vector<T> elements;
    void shift_up(int);
    void shift_down(int);

    void printAsTreeInner(T pos, int level);

public:
    PriorityQueue();
    ~PriorityQueue();

    void push(T elem);
    void pop();
    T top();
    void clear();

    void printAsArray();
    void printAsTree();
};


template <typename T>
PriorityQueue<T>::PriorityQueue() = default;

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    clear();
}

template <typename T>
void PriorityQueue<T>::shift_up(int pos) {
    if (elements.size() > 1) {
        int i = pos;
        int parent = (i - 1) / 2;
        while (elements[i] > elements[parent]) {
            std::swap(elements[i], elements[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }
}

template <typename T>
void PriorityQueue<T>::shift_down(int pos) {
    int i = 0;
    int left = 1, right = 2;
    bool isLeaf = false;
    int size = elements.size();

    int child = elements[left] > elements[right] ? right : left;

    while (!isLeaf && elements[i] < elements[child]) {
        std::swap(elements[i], elements[child]);
        i = child;

        left = 2 * i - 1;
        right = 2 * i;

        if (left >= size || right >= size)
            isLeaf = true;
        else
            child = elements[left] > elements[right] ? right : left;
    }
}

template <typename T>
void PriorityQueue<T>::push(T elem) {
    elements.push_back(elem);
    shift_up(elements.size() - 1);
}

template <typename T>
void PriorityQueue<T>::pop() {
    elements[0] = elements.back();
    elements.erase(elements.begin() + elements.size() - 1);
    shift_down(0);
}

template <typename T>
T PriorityQueue<T>::top() {
    return elements[0];
}

template <typename T>
void PriorityQueue<T>::clear() {
    elements.clear();
}

template <typename T>
void PriorityQueue<T>::printAsArray() {
    for (int elem : elements)
        cout << elem << ' ';
}

template<typename T>
void PriorityQueue<T>::printAsTreeInner(T pos, int level) {
    if (pos - 1 < elements.size()) {
        printAsTreeInner(pos * 2 + 1, level + 1);

        for (int i = 0; i < level; ++i) {
            cout << "\t";
        }
        cout << elements[pos - 1] << '\n';
        printAsTreeInner(pos * 2, level + 1);
    }
}

template<typename T>
void PriorityQueue<T>::printAsTree() {
    printAsTreeInner(1, 0);
}
