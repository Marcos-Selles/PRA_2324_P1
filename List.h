




#ifndef LIST_H
#define LIST_H
#include <stdexcept>  // Para std::out_of_range

template <typename T>
class List {
public:
    // Constructor
    List(int initialCapacity) : capacity(initialCapacity), numElements(0) {
        elements = new T[capacity];
    }

    // Destructor
    ~List() {
        delete[] elements;
    }

    // Inserta el elemento e en la posición pos
    void insert(int pos, T e) {
        if (pos < 0 || pos > numElements) {
            throw std::out_of_range("Posición no válida");
        }

        if (numElements >= capacity) {
            // Redimensiona el array si es necesario
            capacity *= 2;
            T* newElements = new T[capacity];
            for (int i = 0; i < numElements; i++) {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
        }

        // Desplaza los elementos a la derecha para hacer espacio para el nuevo elemento
        for (int i = numElements; i > pos; i--) {
            elements[i] = elements[i - 1];
        }

        // Inserta el nuevo elemento en la posición pos
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

    // Elimina y devuelve el elemento situado en la posición pos
    T remove(int pos) {
        if (pos < 0 || pos >= numElements) {
            throw std::out_of_range("Posición no válida");
        }

        T removedElement = elements[pos];

        // Desplaza los elementos a la izquierda para llenar el espacio dejado por el elemento eliminado
        for (int i = pos; i < numElements - 1; i++) {
            elements[i] = elements[i + 1];
        }

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

private:
    T* elements;  // Array para almacenar los elementos
    int capacity; // Capacidad máxima de la lista
    int numElements; // Número actual de elementos
};
#endif

