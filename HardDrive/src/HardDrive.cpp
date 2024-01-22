#include "HardDrive.h"
std::vector<File*> fileBook;
HardDrive::HardDrive(int numDisks, int spacePerDisk, int colums){
  this->numDisks=numDisks;
  this->spacePerDisk=spacePerDisk;
  this->colums=colums;
}
void HardDrive::FileBookLinkedFileAppender(File* file){
  for(int i=0;i<file->Files.size();i++){
      fileBook.insert(fileBook.begin()+IndexFinder(file->Files[i]->Name), file->Files[i]);
    if(file->Files[i]->Files.size()>0){
      FileBookLinkedFileAppender(file->Files[i]);
    }
  }
}
void HardDrive::AppendFile(File* file){
  fileBook.insert(fileBook.begin()+IndexFinder(file->Name), file);
  if(file->Files.size()>0){
    for(int i=0;i<file->Files.size();i++){
        fileBook.insert(fileBook.begin()+IndexFinder(file->Files[i]->Name), file->Files[i]);
      if(file->Files[i]->Files.size()>0){
        FileBookLinkedFileAppender(file->Files[i]);
      }
    }
  }
}
std::vector<File*> HardDrive::ReturnFilesOfName(std::string name){
  std::vector<File*> fileCollection;
  for(int i=0;i<fileBook.size();i++){
    if(fileBook[i]->Name==name){
      fileCollection.push_back(fileBook[i]);
    }
  }
  return fileCollection;
}
int HardDrive::IndexFinder(std::string input){
  int size=fileBook.size();
  if (size <= 0){
    return 0;
  }
  int lowerBound = 0;
  int upperBound = size - 1;
  while (lowerBound < upperBound){
    int midPoint = (lowerBound + upperBound) / 2;
    if (fileBook[midPoint]->Name.compare (input) < 0){
      lowerBound = midPoint + 1;
    }else{
      upperBound = midPoint;
    }
  }
  return abs(fileBook[lowerBound]->Name.compare(input));
}
HardDrive::~HardDrive(){

}
