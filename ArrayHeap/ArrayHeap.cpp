


#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>  
#include <valarray>
#include "ArrayHeap.h"
// class ArrayHeap {
// public:
//     struct priorityData {
//         int priorityValue;
//         std::string dataValue;
//     };
//
//     
//     ArrayHeap();  // Declaration of the default constructor
//     ArrayHeap(int capacity);
//     
//     void addElement(int elem);
//     priorityData removeMin();
//     priorityData returnMin();
//    
//     std::string toString();
//     void bubbleDown(int index);
//
// private:
//     int capacity;
//     priorityData* heap; 
//     
//     int size = 0;
// };

// Definition of the default constructor
ArrayHeap::ArrayHeap() {
    capacity = 10;  // Set the initial capacity
    size = 0;       // Initialize size to 0
    std::cout << "Heap created with a size of: " << capacity << std::endl;
    heap = new ArrayHeap::priorityData[10];
}
ArrayHeap::ArrayHeap(int capacity) {
    this->capacity = capacity;
    std::cout << "Heap created with a size of: " << capacity << std::endl;
    heap = new ArrayHeap::priorityData[capacity];
    
}
void processActions(std::istream& actionStream, ArrayHeap& heap, std::ostream& logStream) {
    // Read and process actions from stream
}


    ArrayHeap myHeap;  // This will call the default constructor
void initializeHeap(const std::string& string, const ArrayHeap& heap);

//    int main(int argc, char* argv[]) {
//     int capacity = 10; // default capacity
//     std::string initFile, actionFile, outputFile, input;
//     int actionMode;
//
//     std::cout << "Enter the capacity of the priority queue (or enter n for default): ";
//     std::getline(std::cin, input);
//     if (!input.empty())
//         capacity = std::stoi(input);
//
//     ArrayHeap heap(capacity);
//
//     std::cout << "Enter the name of initialization input file (empty for none): ";
//        std::getline(std::cin, input);
//        if(!initFile.empty())
//        {
//            std::ifstream file(initFile);
//            int x =0;
//            file.open(initFile);
//            if (file.is_open()) {
//                while (!file.eof() && x != NULL)
//                {
//                    file>>x;
//                    heap.addElement(x);
//                }
//        }
//       
//     }
//        else if(initFile.empty())
//        {
//            //make a for loop to generate 10 random ints and add the to the previosly built heap
//            srand(time(NULL));  // Seed the random number generator
//            for (int i = 0; i < 10; i++) {
//                int randomInt = rand() % 100;  // Generate a random integer
//                heap.addElement(randomInt);  // Add it to the heap
//            } 
//        }
//     std::string action;
//        while(action!= "Q")
//        {
//            std::cout << "Select action mode:\n"
//           "I[nsert] \"string of data\" priority\n"
//           "R[emove]\n"
//           "S[ee top element]\n"
//           "A[ll items in string]\n";
//            std::cin>>action;
//            if (action == "I") {
//
//                 int i;
//                std::cout << "Enter the int ";
//                std::cin >> i;
//                heap.addElement(i);
//            }
//            else if(action == "R")
//            {
//                int i;
//                std::cout << "Enter the int ";
//                std::cin >> i;
//                heap.removeMin();
//            }
//            else if(action == "r")
//            {
//                int i;
//                std::cout << "Enter the int ";
//                std::cin >> i;
//                heap.returnMin();
//            }
//            else if(action == "A")
//            {
//                heap.toString();
//            }
//            else if(action == "Q")
//            {
//                std::cout<<"Program will now exit"<<std::endl;
//                break;
//            }
//        }
//     
//
//     return 0;
// }



void ArrayHeap::addElement(int elem)
{
       if (size >= capacity) {
           std::cout << "Heap is full!" << std::endl;
           return;
       }

       // Place the new element at the end of the heap
       int currentIndex = size;
       heap[currentIndex].priorityValue = elem;
       heap[currentIndex].dataValue = std::to_string(elem);  // Assuming you want to store the same int as a string for dataValue
       size++;
           while (currentIndex > 0) {
               int parentIndex = (currentIndex - 1) / 2;
               if (heap[currentIndex].priorityValue < heap[parentIndex].priorityValue) {
                   // Swap current element with its parent
                   priorityData temp = heap[currentIndex];
                   heap[currentIndex] = heap[parentIndex];
                   heap[parentIndex] = temp;
                   currentIndex = parentIndex;  // Move up to the parent
               } else {
                   break;  // If the parent is smaller, no need to bubble up further
               }
    
       }
   
     
    
}

ArrayHeap::priorityData ArrayHeap::removeMin()
{
       if (size == 0) {
           std::cout << "Heap is empty!" << std::endl;
           return priorityData(); // Return a default-constructed priorityData object
       }

      // bool intfound = false;
       
           
               //intfound = true;
               priorityData temp = heap[0];
               heap[0] = heap[size - 1];  // Replace the removed element with the last element in the heap
               size--;  // Decrease the size of the heap
               //bubbleDown(j);  // Perform a bubble down operation to maintain the heap property
               std::cout<< "The value  " + std::to_string(heap[0].priorityValue) + "was deleted!";
               return temp;
           
           //bubble down
           
       
       // if(intfound == false)
       // {
       //     std::cout<<"no such int was found in the Heap!";
       // }
}
std::string ArrayHeap::toString()
{
    std::string allstr;
    for(int i = 0 ; i < capacity;i++)
    {
         
        std::cout<<"value of " + std::to_string(i) + " is:" + std::to_string(heap[i].priorityValue)<<std::endl;
        std::cout<< "data of " + std::to_string(i) + " is:" + heap[i].dataValue<<std::endl;
       allstr +=   "value of " + std::to_string(i) + " is:\n" + std::to_string(heap[i].priorityValue);
    }
    return   allstr;
}

ArrayHeap::priorityData ArrayHeap::returnMin()
{
    priorityData NoData;
       NoData.dataValue = "No Data";
       NoData.priorityValue = 1;
            if(heap[0].priorityValue != NULL)
            {
                return heap[0];
            }
       else{
           return NoData;
       
}


// void ArrayHeap::bubbleDown(int index) {
//        int leftChildIndex = 2 * index + 1;  // Calculate the index of the left child
//        int rightChildIndex = 2 * index + 2; // Calculate the index of the right child
//        int smallest = index;
//
//        // Check if the left child exists and is smaller than the current element
//        if (leftChildIndex < size && heap[leftChildIndex].priorityValue < heap[smallest].priorityValue) {
//            smallest = leftChildIndex;
//        }
//
//        // Check if the right child exists and is smaller than the current element
//        if (rightChildIndex < size && heap[rightChildIndex].priorityValue < heap[smallest].priorityValue) {
//            smallest = rightChildIndex;
//        }
//
//        // If the smallest element is not the current element, swap them
//        if (smallest != index) {
//            priorityData temp = heap[index];
//            heap[index] = heap[smallest];
//            heap[smallest] = temp;
//
//            // Recursively bubble down from the new position of the swapped element
//            bubbleDown(smallest);
//        }
   }

