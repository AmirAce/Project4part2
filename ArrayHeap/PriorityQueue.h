#pragma once

#include "ArrayHeap.h"


class priority_queue
{
   
    void insert(int elem);
    ArrayHeap::priorityData remove();
    ArrayHeap::priorityData Return();
    //std::string ToString();
    //std::string toString();

public:
    priority_queue();
    priority_queue(int capacity);
    int cap;
    ArrayHeap* myqueue;
    

    // ArrayHeap queue;
};


