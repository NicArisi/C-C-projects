#include <iostream>
#include <vector>
#include "File.h"
#ifndef HardDrive_h
#define HardDrive_h
class HardDrive{
public:
  std::vector<File*> fileBook;//should sort the file names alphabetically
  int numDisks;//the number of disks in the hard drive
  int spacePerDisk;//the space avaible per disk
  int colums; //how many lines of data per disk
  HardDrive(int numDisks, int spacePerDisk, int colums);
  void AppendFile(File* input);//add file
  std::vector<File*> ReturnFilesOfName(std::string name);//return the ID of the file of where they are in the drive, binary search function, populate a main's vector, assume that the file directory is in apahabetical order or string number order
  void reorganize();//reorganize so that files in reference of each other are in close proximity or fast to get to  v
  void FileBookLinkedFileAppender(File* file);
  int IndexFinder(std::string input);
  ~HardDrive();
};
#endif
