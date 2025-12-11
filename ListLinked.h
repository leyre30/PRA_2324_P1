#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <iostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* head;
    int n;

public:
    ListLinked() {
        head = nullptr;
        n = 0;
    }

    ~ListLinked() {
        while (head != nullptr) {
            Node<T>* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición inválida");

        Node<T>* newNode = new Node<T>(e);

        if (pos == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* curr = head;
            for (int i = 0; i < pos - 1; i++)
                curr = curr->next;

            newNode->next = curr->next;
            curr->next = newNode;
        }
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

        Node<T>* tmp;
        if (pos == 0) {
            tmp = head;
            head = head->next;
        } else {
            Node<T>* curr = head;
            for (int i = 0; i < pos - 1; i++)
                curr = curr->next;
            tmp = curr->next;
            curr->next = tmp->next;
        }

        T removed = tmp->data;
        delete tmp;
        n--;
        return removed;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida");

        Node<T>* curr = head;
        for (int i = 0; i < pos; i++)
            curr = curr->next;

        return curr->data;
    }

    int search(T e) override {
        Node<T>* curr = head;
        int i = 0;
        while (curr != nullptr) {
            if (curr->data == e)
                return i;
            curr = curr->next;
            i++;
        }
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

