#include "File.h"
std::vector<File*> Files;
File::File(std::string data, std::string Name) {
	this->data = data;
	this->Name = Name;
}
File::File(std::string Name) {
	this->Name = Name;
}
void File::addFiles(File *file) {
	Files.push_back(file);
}
void File::changeData(std::string data) {
	this->data = data;
}
File::~File() {
	for (int i = 0; i < Files.size(); i++) {
		delete (Files[i]);
	}
}
