#include "PriorityQueue.h"

#include <fstream>
#include <queue>

priority_queue::priority_queue()
{
   myqueue = new ArrayHeap(cap);
}

priority_queue::priority_queue(int cap)
{
     this->cap = cap;
    
    myqueue = new ArrayHeap(cap);
}

void priority_queue::insert(int elem)
{
    ArrayHeap::priorityData temp;
    temp.priorityValue = elem;
    myqueue->addElement(elem);
}

ArrayHeap::priorityData priority_queue::remove()
{
    return myqueue->removeMin();
}

ArrayHeap::priorityData priority_queue::Return()
{
  return myqueue->returnMin();
}

int main()
{
    int capacity; // default capacity
    std::string initFile, actionFile, outputFile, input;
    int actionMode;
   
    std::cout << "Enter the capacity of the priority queue (or enter n for default): ";
    std::getline(std::cin, input);
    if (!input.empty())
    {
        capacity = std::stoi(input);
    }
    else{
    capacity = 10;
    }
    priority_queue list(capacity);
    std::cout << "Enter the name of initialization input file (empty for none): ";
       std::getline(std::cin, input);
       if(!initFile.empty())
       {
           std::ifstream file(initFile);
           int x =0;
           file.open(initFile);
           if (file.is_open()) {
               while (!file.eof() && x != NULL)
               {
                   ArrayHeap::priorityData tempData;
                   file>>x;
                   tempData.priorityValue = x;
                   list.myqueue->addElement(x);
               }
       }
      
    }
       else if(initFile.empty())
       {
           srand(time(NULL));  // Seed the random number generator
           for (int i = 0; i < 10; i++) {
               int randomInt = rand() % 100;  // Generate a random integer
               ArrayHeap::priorityData tempData;
               tempData.priorityValue = randomInt;
               list.myqueue->addElement(randomInt);
           } 
       }
    std::string action;
       while(action!= "Q")
       {
           std::cout << "Select action mode:\n"
          "I[nsert] \"string of data\" priority\n"
          "R[emove]\n"
          "S[ee top element]\n"
          "A[ll items in string]\n";
           std::cin>>action;
           if (action == "I") {

                int i;
               std::cout << "Enter the int ";
               std::cin >> i;
               ArrayHeap::priorityData tempData;
               tempData.priorityValue = i;
               list.myqueue->addElement(i);
           }
           else if(action == "R")
           {
               int i;
               std::cout << "Enter the int ";
               std::cin >> i;
               list.myqueue->removeMin();
           }
           else if(action == "r")
           {
               int i;
               std::cout << "Enter the int ";
               std::cin >> i;
               list.myqueue->returnMin();
           }
           else if(action == "A")
           {
               list.myqueue->toString();
           }
           else if(action == "Q")
           {
               std::cout<<"Enter Name of Output File:";
               std::string outname;
               std::cin>>outname;
               std::ofstream outFile(outname);  // Open an output file stream
               if (outFile.is_open()) {
                   outFile << list.myqueue->toString();  // Write the heap's string representation to the file
                   outFile.close();  // Close the file stream
               } else {
                   std::cerr << "Unable to open file";
               }
               std::cout<<"Program will now exit"<<std::endl;
               break;
           }
       }

    return 0;
}