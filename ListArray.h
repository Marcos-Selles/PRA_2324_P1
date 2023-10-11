#ifndef LISTARRAY_H
#define LISTARRAY_H
#include "List.h"
#include <ostream>   // Para que la sobrecarga del operador funcione correctamente 
#include <iostream>  // Para std::ostream
#include <stdexcept>  // Para std::out_of_range

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;  // Puntero al inicio del array
    int max; // Tamaño actual del array
    int n;   // Número de elementos
    static const int MINSIZE = 2; // Tamaño mínimo del array

public:
    ListArray() : max(MINSIZE), n(0) {
        arr = new T[max];
    }

    ~ListArray() {
        delete[] arr;
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición no válida");
        }

        return arr[pos];
    }

    // Redimensiona el array al tamaño especificado
    void resize(int new_size) {
        T* new_arr = new T[new_size];
        for (int i = 0; i < n; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

    // Resto de las funciones heredadas de la clase List
    void insert(int pos, T e) {
        // Implementación de insert
    }

    void append(T e) {
        // Implementación de append
    }

    void prepend(T e) {
        // Implementación de prepend
    }

    T remove(int pos) {
        // Implementación de remove
    }

    T get(int pos) {
        // Implementación de get
    }

    int search(T e) {
        // Implementación de search
    }

    bool empty() {
        // Implementación de empty
    }

    int size() {
        // Implementación de size
    }

    // Sobrecarga global del operador <<
    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        for (int i = 0; i < list.n; i++) {
            out << list.arr[i] << ' ';
        }
        return out;
    }
};
#endif

