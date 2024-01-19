#include "PipeLineNode.h"
  PipeLineNode::PipeLineNode(int pos, std::string descr, PipeLineNode* ptr, PipeLineNode* Pre){
    position = pos;
    description = descr;
    nextNode = ptr;
    PreviousNode=Pre;
  }
  int PipeLineNode::getPosition(){
    return position;
  }
  std::string PipeLineNode::getDescription(){
    return description;
  }
  PipeLineNode* PipeLineNode::getNextNode(){
    return nextNode;
  }
  PipeLineNode* PipeLineNode::getPreNode(){
    return PreviousNode;
  }
  void PipeLineNode::setPreNode(PipeLineNode* input){
    PreviousNode=input;
  }
  void PipeLineNode::setNextNode(PipeLineNode* input){
    nextNode=input;
  }
  int PipeLineNode::compareTo(PipeLineNode* input){
    return position-input->getPosition();
  }
  PipeLineNode :: ~PipeLineNode() {
    nextNode = nullptr;
    PreviousNode=nullptr;
  }


