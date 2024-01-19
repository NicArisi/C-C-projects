//stores pipeline nodes
//need sort and addtofront, and add to end. Getting description is proken in terms of previous node
#include "PipelineNodeList.h"
  PipeLineNode* PipelineNodeList::headNode = nullptr;
  PipeLineNode* PipelineNodeList::tailNode = nullptr;
//these 2 top vars were defined but not defined. The 2 lines above defines
  PipelineNodeList::PipelineNodeList(){
    headNode=nullptr;
    tailNode=nullptr;
  }
  void PipelineNodeList::append(int pos, std::string descr){ //pump highway tank
    PipeLineNode* newNode = new PipeLineNode(pos, descr, nullptr,nullptr);
    PipeLineNode* temp=nullptr;
    if(headNode == nullptr){
      headNode = newNode;
    }else{
      tailNode->setNextNode(newNode);
      temp=tailNode;
    }
    tailNode = newNode; //specify a new tailNode
    tailNode->setPreNode(temp);
  }
  void PipelineNodeList::traverseAndPrint(){
    PipeLineNode* currentNode = headNode;
    int nodeNum = -1;
    do{
      nodeNum++;
      std::cout << "Node number: " << nodeNum<< std::endl;
      std::cout << "Position: " << currentNode->getPosition() << std::endl;
      std::cout << "Description: " << currentNode->getDescription()<< std::endl;
      if(currentNode->getNextNode()!=nullptr)
        std::cout << "next: " << currentNode->getNextNode()->getDescription()<< std::endl;
      if(currentNode->getPreNode()!=nullptr)
        std::cout << "Previous: " << currentNode->getPreNode()->getDescription()<< std::endl;
        std::cout << std::endl;
        currentNode = currentNode->getNextNode();
    }while(currentNode != nullptr);
  }
  void PipelineNodeList::getNode(int i){
    PipeLineNode* currentNode = headNode;
    int nodeNum = -1;
    do{
      nodeNum++;
      if(nodeNum==i){
        std::cout << "Node number: " <<nodeNum << std::endl;
        std::cout << "Position: "<<currentNode->getPosition()<< std::endl;
        std::cout << "Description: "<<currentNode->getDescription()<< std::endl;
        std::cout << std::endl;
        break;
      }currentNode = currentNode->getNextNode();
    }while(currentNode != nullptr);
  }
  PipeLineNode* PipelineNodeList::getNodeData(int i){
    PipeLineNode* currentNode = headNode;
    int nodeNum = -1;
    do{
      nodeNum++;
      if(nodeNum==i){
        break;
      }currentNode = currentNode->getNextNode();
    }while(currentNode != nullptr);
    return currentNode;
  }
  int PipelineNodeList::PipelineSize(){
    PipeLineNode* currentNode = headNode;
    int nodeNum = 0;
    do{
      nodeNum++;
      currentNode = currentNode->getNextNode();
    }while(currentNode != nullptr);
    return nodeNum;
  }
  void PipelineNodeList::PipelineAdd(int pos, std::string descr, int index){
    if(index==0){
      PipelineAddFront(pos, descr);
    }else if(index == PipelineSize()){
      PipelineAdd(pos, descr);
    }else{
      PipeLineNode* currentNode = headNode;
      int nodeNum = -1;
      PipeLineNode* request =  new PipeLineNode(pos, descr,nullptr,nullptr);
      do{
        nodeNum++;
        if(nodeNum+1==index){
          request->setNextNode(currentNode->getNextNode());
          currentNode->getNextNode()->setPreNode(request);
          request->setPreNode(currentNode);
          currentNode->setNextNode(request);
          break;
        }else{
          currentNode = currentNode->getNextNode();
        }
      }while(currentNode->getNextNode() != nullptr);
    }
  }
  void PipelineNodeList::PipelineAdd(int pos, std::string descr){ //this will add to front
    PipeLineNode* request =  new PipeLineNode(pos, descr,nullptr,tailNode);
    tailNode->setNextNode(request);
    tailNode=request;
  }
  PipeLineNode* PipelineNodeList::PipelineSubtract(int index){
    PipeLineNode* Returner=nullptr;
    if(index==0){
      if(headNode->getNextNode()!=tailNode){
        PipeLineNode* tempHead = headNode;
        headNode->getNextNode()->setPreNode(nullptr);
        headNode=headNode->getNextNode();
        Returner=tempHead;
      }else{
        delete headNode;
        headNode=tailNode;
        tailNode=nullptr;
      }
    }else if(index==PipelineSize()-1){
      Returner= PipelineSubtract();
    }else{ //pump, highway, tank    pump tank
      int nodeNum = -1;
      PipeLineNode* currentNode = headNode;//view elimination, view compression of list
      do{
        nodeNum++;
        if(nodeNum+1==index){
          Returner=currentNode->getNextNode();
          currentNode->getNextNode()->getNextNode()->setPreNode(currentNode);//thing, next to remove, thing to make new prenode
          currentNode->setNextNode(currentNode->getNextNode()->getNextNode());
          break;
        }else{
          currentNode = currentNode->getNextNode();
        }
      }while(currentNode->getNextNode() != nullptr);
    }
    return Returner;
  }
  PipeLineNode* PipelineNodeList::PipelineSubtract(){ //get rid of tailnode
    PipeLineNode* tempToReturn = tailNode;
    tailNode=tailNode->getPreNode();
    tailNode->setNextNode(nullptr);
    return tempToReturn;
  }
  void PipelineNodeList::PipelineAddFront(int pos, std::string descr){
      PipeLineNode* currentNode = headNode;
      PipeLineNode* request =  new PipeLineNode(pos, descr,currentNode,nullptr);
      headNode->setPreNode(request);
      headNode=request;
  }
  void PipelineNodeList::insertionSort (){
    PipeLineNode* currentNode=headNode->getNextNode();//this node will progress forward
    int indexer = 0;
    do{
      indexer++;
      insertInOrder (currentNode, indexer);
      currentNode=currentNode->getNextNode();
    }while(currentNode!=nullptr);
  }
  void PipelineNodeList::insertInOrder (PipeLineNode* m, int index){
    PipeLineNode* save=m;
   // PipelineNode saveNext=m.getNextNode();
    //PipelineNode savePre=m.getPreNode();
    int indexWhenFindSmaller=index;
    while(m!=headNode && m->getPreNode()->compareTo(save)>0){ //want to stop when we find a small val, or null such as with starting with 4573
      indexWhenFindSmaller--;
      m=m->getPreNode();
    }
    PipelineSubtract(index);
    PipelineAdd(save->getPosition(), save->getDescription(), indexWhenFindSmaller);
    //getNodeData(indexWhenFindSmaller);
  }
  PipelineNodeList :: ~PipelineNodeList() {
    int size = PipelineSize();
    for(int x=size;x>=0;x--){
      delete(PipelineSubtract(0));
    }
  }
//4573, 0, 3050, 200, 6000 start at 0, 4573 is greater, indexsmaller is now 0, enter loop conditions again with m being the headnode of 4573, exit with false, remove 0, add 0 back into index 0




