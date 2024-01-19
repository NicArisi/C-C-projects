#include <iostream>
#include "PipelineNodeList.h"
//https://www.geeksforgeeks.org/cpp-pointers/
//https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/
//-> to point to other objects which are pointers
//* initialize a pointer object
//& make an object a pointer
//use pointers when refering to other objects, managing dynamic memory
//NULL for nonpointers, nullptr for pointers
//example from lowlevelcoder
//int x=4, interger named x is set to 4
//int* pX=&x; integer pointer named pX is set to the address of x
//static memory, fixed size when compiled
//dynamic memory, changed in size when running program
int main() {
  std::cout << "PA Pipeline \n";
  PipelineNodeList* Pa= new PipelineNodeList();
  Pa->append(4573, "Tank farm");
  Pa->append(0, "Pump station");
  Pa->append(3050, "Hwy 35");
  Pa->append(200, "bopbop");
  Pa->append(6000, "11kj");
  Pa->traverseAndPrint();
  std::cout << Pa->PipelineSize()<< "\n";
  Pa->insertionSort();
  Pa->traverseAndPrint();
  std::cout << Pa->getNodeData(2)->getDescription() << "\n";
  std::cout << "Alaskan Pipeline \n";
  PipelineNodeList* alaskan= new PipelineNodeList();
  alaskan->append(0, "Pump station");
  alaskan->append(3050, "Hwy 35");
  alaskan->append(4573, "Tank farm");
  alaskan->traverseAndPrint();
  //std::cout<< "Broken delete";
  delete(alaskan->PipelineSubtract(0));
  delete(alaskan->PipelineSubtract(0));
  std::cout<< "Your request is \n";
  alaskan->getNode(0);
  alaskan->PipelineAdd(-1000, "bonk", 0);
  alaskan->traverseAndPrint();
  delete(alaskan);
}
