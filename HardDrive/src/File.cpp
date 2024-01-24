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
std::vector<File*> File::RemoveFiles(File *file) {
	std::vector<File*> A;
	std::vector<File*> B;
	int i=0;
	while(Files[i]!=file){
		i++;
	}
	if(Files[i]->Files.size()!=0){
		int initialSizeOfFileSubI=Files[i]->Files.size();
		while(initialSizeOfFileSubI>=0){
			B=Files[i]->RemoveFiles(Files[initialSizeOfFileSubI]);//this is structured in a way to return the files that don't point to a file first and then place the file that points to files last. Gives a set of files that are pointed from a folder
		}
	}else{
		A.push_back(Files[i]);
		Files.erase(Files.begin()+i);
		B.push_back(A[0]);
	}
	return B;
}
void File::changeData(std::string data) {
	this->data = data;
}
File::~File() {
	for (int i = 0; i < Files.size(); i++) {
		delete (Files[i]);
	}
}
