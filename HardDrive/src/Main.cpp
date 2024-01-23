#include <iostream>
#include "File.h"
#include "HardDrive.h"
int main() {
	File *file1 = new File("Junk");
	File *file2 = new File("Hello World", "HW.txt");
	File *file3 = new File("h", "h.txt");
	File *file4 = new File("1020203039", "nums.txt");
	File *file5 = new File("23424324", "nums.txt");
	file1->addFiles(file2);
	file1->addFiles(file3);
	file1->addFiles(file4);
	file1->addFiles(file5);
	 std::cout << file1->Files.size() << std::endl;
	 std::cout << file1->Files[0]->data << std::endl;
	 std::cout << file1->Files[1]->data << std::endl;
	 std::cout << file1->Files[2]->data << std::endl;
	 std::cout << "The size of file1 is " << sizeof(file2)<< std::endl << " bytes";
	HardDrive *NUm1 = new HardDrive(1, 1000, 4);
	NUm1->AppendFile(file1);
	std::cout << NUm1->fileBook.size() << std::endl;
	std::vector<File*> fileCollectionMain = NUm1->ReturnFilesOfName("txt");
	for (int i = 0; i < fileCollectionMain.size(); i++) {
		std::cout << "The Data of this name index is "
				<< fileCollectionMain[i]->data << std::endl;
	}
	for (int i = 0; i < NUm1->fileBook.size(); i++) {
		std::cout << "The Name of " << i << " index is "
				<< NUm1->fileBook[i]->Name << std::endl;
	}
	std::cout << "The size of NUm1 is " << NUm1->SpaceInBytes<< std::endl << " bytes";
	//delete (NUm1);
}
