#include <iostream>
#include <vector>
#ifndef File_h
#define File_h
class File {
public:
	int MotorAngle; //should take up space in the hard drive book, not the drives themselves
	std::string data;
	std::string Name;
	std::vector<File*> Files; //only use if this file is actaully a collection of files
	File(std::string Data, std::string Name);
	File(std::string Name);
	void changeData(std::string Data);
	void addFiles(File *file);
	void RemoveFiles(File *file);
	~File();
};
#endif
