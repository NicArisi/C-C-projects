#include <iostream>
#include "File.h"
#include "HardDrive.h"
int main() {
	File *file6 = new File("Monkeys");
	File *file7 =
			new File(
					"2343242354345346456534223423453452131223123234523445354234234234543634653453453445643564345",
					"StrongMonkey.png");
	File *file8 =
			new File(
					"123123123124235423543412312312312312312423452345345634654523342342342354365344534534523423523453452432134234523534532",
					"RotatingMonkey.png");
	File *file1 = new File("Junk");
	File *file2 = new File("Hello World", "HW.txt");
	File *file3 = new File("h", "h.txt");
	File *file4 = new File("1020203039", "nums.txt");
	File *file5 = new File("23424324", "nums.txt");
	file6->addFiles(file7);
	file6->addFiles(file8);
	file1->addFiles(file2);
	file1->addFiles(file3);
	file1->addFiles(file4);
	file1->addFiles(file5);
	file6->addFiles(file1);
	std::cout << file1->Files.size() << std::endl;
	std::cout << file1->Files[0]->data << std::endl;
	std::cout << file1->Files[1]->data << std::endl;
	std::cout << file1->Files[2]->data << std::endl;
	std::cout << "The size of file1 is " << sizeof(file2) << " bytes"
			<< std::endl;
	HardDrive *NUm1 = new HardDrive(1, 1000, 4);
	NUm1->AppendFile(file6);
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
	std::cout << "The size of NUm1 is " << NUm1->SpaceInBytes << " bytes"
			<< std::endl;
	NUm1->RemoveFileOrFiles(file1);//should remove junk which contains, h.txt, nums.txt files
	std::cout << "The size of NUm1 is " << NUm1->SpaceInBytes << " bytes"
				<< std::endl;
	for (int i = 0; i < NUm1->fileBook.size(); i++) {
			std::cout << "The Name of " << i << " index is "
					<< NUm1->fileBook[i]->Name << std::endl;
	}
	//imagine you are in the file explorer of file 6 and want to delete the junk file
	//delete (NUm1);
}
