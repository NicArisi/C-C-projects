#include <iostream>
#include "PipeLineNode.h"
#ifndef PipelineNodeList_h
#define PipelineNodeList_h
class PipelineNodeList {
  private:
    static PipeLineNode* headNode;
    static PipeLineNode* tailNode;
  public:
    PipelineNodeList();
    static void append(int pos, std::string descr);
    void traverseAndPrint();
    void getNode(int i);
    PipeLineNode* getNodeData(int i);
    int PipelineSize();
    void PipelineAdd(int pos, std::string descr, int index);
    void PipelineAdd(int pos, std::string descr);
    PipeLineNode* PipelineSubtract(int index);
    PipeLineNode* PipelineSubtract();
    void PipelineAddFront(int pos, std::string descr);
    void insertionSort();
    void insertInOrder(PipeLineNode* m, int index);
    ~PipelineNodeList();
};
#endif

