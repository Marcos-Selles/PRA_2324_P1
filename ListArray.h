#ifndef LISTARRAY_H
#define LISTARRAY_H
#include "List.h"
#include <ostream>   // Para que la sobrecarga del operador funcione correctamente 
#include <iostream>  // Para std::ostream
#include <stdexcept>  // Para std::out_of_range

template <typename T>
class ListArray : private List<T> {
private:
    T* arr;  // Puntero al inicio del array
    int max; // Tamaño actual del array
    int n;   // Número de elementos
    int numElements;
    static const int MINSIZE = 2; // Tamaño mínimo del array
    void resize(int new_size) {
        T* new_arr = new T[new_size];
        for (int i = 0; i < n; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    ListArray() : max(MINSIZE),n(0), numElements(0){
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
    

    // Resto de las funciones heredadas de la clase List
    void insert(int pos, T e) {
        if (pos < 0 || pos > numElements) {
            throw std::out_of_range("Posición no válida");
        } arr[pos] = e;
        numElements++;
    }

    void append(T e) {
        // Implementación de append
        insert(numElements, e);
    
    }

    void prepend(T e) {
        // Implementación de prepend
        insert(0, e);
    }

    T remove(int pos) {
        // Implementación de remove
    if (pos < 0 || pos >= numElements) {
        throw std::out_of_range("Posición no válida");
    }

    T removedElement = arr[pos];

    numElements--;

    return removedElement;
    }

    T get(int pos) {
        // Implementación de get
        
    if (pos < 0 || pos >= numElements) {
            throw std::out_of_range("Posición no válida");
        }

        return arr[pos];
    }

    int search(T e) {
        // Implementación de search
    for (int i = 0; i < numElements; i++) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1;
    }

    bool empty() {
        // Implementación de empty
    return numElements == 0;
    }

    int size() {
        // Implementación de size
    return numElements;
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

