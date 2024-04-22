#ifndef ARRAYHEAP_H
#define ARRAYHEAP_H

#include <iostream>
#include <string>

class ArrayHeap {
public:
    struct priorityData {
        int priorityValue;
        std::string dataValue;
    };

    
    ArrayHeap();  // Declaration of the default constructor
    ArrayHeap(int capacity);
    
    void addElement(int elem);
    priorityData removeMin();
    priorityData returnMin();
   
    std::string toString();
    void bubbleDown(int index);

private:
    int capacity;
    priorityData* heap; 
    
    int size = 0;
};

#endif // ARRAYHEAP_H