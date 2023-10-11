




#ifndef LIST_H
#define LIST_H
#include <stdexcept>  // Para std::out_of_range

template <typename T>
class List {
private:
    T* elements;  // Array para almacenar los elementos
    int numElements; // Número actual de elementos
public:
    // Inserta el elemento e en la posición pos
    void insert(int pos, T e) {
        if (pos < 0 || pos > numElements) {
            throw std::out_of_range("Posición no válida");
        }

       
        elements[pos] = e;
        numElements++;
    }

    // Inserta el elemento e al final de la lista
    void append(T e) {
        insert(numElements, e);
    }

    // Inserta el elemento e al principio de la lista
    void prepend(T e) {
        insert(0, e);
    }

    // Elimina el elemento en la posición pos
    T remove(int pos) {
    if (pos < 0 || pos >= numElements) {
        throw std::out_of_range("Posición no válida");
    }

    T removedElement = elements[pos];

    numElements--;

    return removedElement;
}


    // Devuelve el elemento situado en la posición pos
    T get(int pos) {
        if (pos < 0 || pos >= numElements) {
            throw std::out_of_range("Posición no válida");
        }

        return elements[pos];
    }

    // Devuelve la posición en la que se encuentra la primera ocurrencia del elemento e, o -1 si no se encuentra
    int search(T e) {
        for (int i = 0; i < numElements; i++) {
            if (elements[i] == e) {
                return i;
            }
        }
        return -1;  // No se encontró el elemento
    }

    // Indica si la lista está vacía
    bool empty() {
        return numElements == 0;
    }

    // Devuelve el número de elementos de la lista
    int size() {
        return numElements;
    }

    
};
#endif

