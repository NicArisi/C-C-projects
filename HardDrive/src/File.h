#include <iostream>
#include <vector>
#ifndef File_h
#define File_h
class File{
public:
  int ID;//should take up space in the hard drive book, not the drives themselves
  std::string data;
  std::string Name;
  std::vector<File*> Files;//only use if this file is actaully a collection of files
  int fileSize;//If is folder, don't take up space itself but just return its size in memory, but if a file, take up space,
  File(std::string Data, std::string Name);
  File(std::string Name);
  void changeData(std::string Data);
  void addFiles(File* file);
  ~File();
};
#endif
