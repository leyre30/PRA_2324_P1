#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int capacity;
    int n;

    void resize() {
        int newCap = capacity * 2;
        T* newArr = new T[newCap];
        for (int i = 0; i < n; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
        capacity = newCap;
    }

public:
    ListArray(int cap = 10) {
        capacity = cap;
        arr = new T[capacity];
        n = 0;
    }

    ~ListArray() {
        delete[] arr;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición inválida");

        if (n == capacity)
            resize();

        for (int i = n; i > pos; i--)
            arr[i] = arr[i - 1];

        arr[pos] = e;
        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida");

        T removed = arr[pos];
        for (int i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];
        n--;
        return removed;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida");
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; i++)
            if (arr[i] == e)
                return i;
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }
};

#endif

