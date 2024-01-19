#include <iostream>
#ifndef PipeLineNode_h
#define PipeLineNode_h
class PipeLineNode{
  private:
    int position;
    std::string description;
    PipeLineNode* nextNode;
    PipeLineNode* PreviousNode;
  public:
    PipeLineNode(int pos, std::string descr, PipeLineNode* ptr, PipeLineNode* Pre);
    int getPosition();
    std::string getDescription();
    PipeLineNode* getNextNode();
    PipeLineNode* getPreNode();
    void setPreNode(PipeLineNode* input);
    void setNextNode(PipeLineNode* input);
    int compareTo(PipeLineNode* input);
    ~PipeLineNode();
};
#endif
