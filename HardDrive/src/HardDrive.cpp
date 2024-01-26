#include "HardDrive.h"
std::vector<File*> fileBook;
HardDrive::HardDrive(int numDisks, int spacePerDisk, int colums) {
	this->numDisks = numDisks;
	this->spacePerDisk = spacePerDisk;
	this->colums = colums;
}
void HardDrive::FileBookLinkedFileAppender(File *file) {
	for (int i = 0; i < file->Files.size(); i++) {
		fileBook.insert(fileBook.begin() + IndexFinder(file->Files[i]->Name),
				file->Files[i]);
		SpaceInBytes = SpaceInBytes + sizeof(file->Files[i]->data);
		if (file->Files[i]->Files.size() > 0) {
			FileBookLinkedFileAppender(file->Files[i]);
		}
	}
}
void HardDrive::AppendFile(File *file) {
	fileBook.insert(fileBook.begin() + IndexFinder(file->Name), file);
	SpaceInBytes = SpaceInBytes + sizeof(file->data);
	if (file->Files.size() > 0) {
		for (int i = 0; i < file->Files.size(); i++) {
			fileBook.insert(
					fileBook.begin() + IndexFinder(file->Files[i]->Name),
					file->Files[i]);
			if (file->Files[i]->Files.size() > 0) {
				FileBookLinkedFileAppender(file->Files[i]);
			}
		}
	}
}
std::vector<File*> HardDrive::ReturnFilesOfName(std::string name) { //searches through for strings that have substrings of name
	std::vector<File*> fileCollection;
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);
	for (int i = 0; i < fileBook.size(); i++) {
		std::string fileI = fileBook[i]->Name;
		std::transform(fileI.begin(), fileI.end(), fileI.begin(), ::tolower);
		if (fileI.find(name) != std::string::npos) {
			fileCollection.push_back(fileBook[i]);
		}
	}
	return fileCollection;
}
int HardDrive::IndexFinder(std::string input) {
	std::transform(input.begin(), input.end(), input.begin(), ::tolower);
	int size = fileBook.size();
	if (size <= 0) {
		return 0;
	}
	int lowerBound = 0;
	int upperBound = size - 1;
	while (lowerBound < upperBound) {
		int midPoint = (lowerBound + upperBound) / 2;
		std::string MidPoint = fileBook[midPoint]->Name;
		std::transform(MidPoint.begin(), MidPoint.end(), MidPoint.begin(),
				::tolower);
		if (MidPoint.compare(input) < 0) {
			lowerBound = midPoint + 1;
		} else {
			upperBound = midPoint;
		}
	}
	std::string UpperStr = fileBook[upperBound]->Name;
	std::transform(UpperStr.begin(), UpperStr.end(), UpperStr.begin(),
			::tolower);
	if (UpperStr.compare(input) > 0) {
		return lowerBound;
	} else {
		return upperBound + 1;
	}

}
void HardDrive::RemoveFileOrFiles(File *input) {
	//go through filebook and remove the files from it and then delete it.
	int filebookIterator = 0;
	int fileIterator = input->Files.size() - 1; //when have Files within
	if (fileIterator > 0) {
		while (fileIterator >= 0) {
			if (input->Files[fileIterator]->Files.size() == 0) {
				while (fileBook[filebookIterator] != input->Files[fileIterator]) {
					filebookIterator++;
				}
				SpaceInBytes = SpaceInBytes
						- sizeof(input->Files[fileIterator]->data);
				fileBook.erase(fileBook.begin() + filebookIterator);
				File *deleteThis = input->Files[fileIterator];
				input->Files.erase(input->Files.begin() + fileIterator);
				delete (deleteThis);
			} else {
				RemoveFileOrFiles(input->Files[fileIterator]);
			}
			fileIterator--;
			filebookIterator = 0;
		}
		int posOfInput = 0;
		while (fileBook[posOfInput] != input) {
			posOfInput++;
		}
		fileBook.erase(fileBook.begin() + posOfInput);
		delete (input);
	} else {
		while (fileBook[filebookIterator] != input) {
			filebookIterator++;
		}
		fileBook.erase(fileBook.begin() + filebookIterator);
		SpaceInBytes = SpaceInBytes - sizeof(input->data);
		delete (input);
	}
}
HardDrive::~HardDrive() {
	for (int i = 0; i < fileBook.size(); i++) {
		delete (fileBook[i]);
	}
}
