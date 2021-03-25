/**
 * Driver file for assignment 1
 * By: Deon Fourie
 *
 */

#include "tagstruct.h"

int main(int argc, char **argv)
{
	const std::string menuDisplay = "r: Read and process tag file\n"
									"p: Print all tags to the terminal\n"
									"d: Dump/Write tags and data to a file called tag.txt\n"
									"l: List/print tag data for a given tag to the terminal\n"
									"q: Quit\n\n"
									"Enter an option(r, p, d, l) or q to quit, and press return\n";
	char choice = ' ';
	std::string fileName = " ";
	std::string tagName = " ";
	do
	{
		std::cout << menuDisplay << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case ('r'):
			system("clear");
			std::cout << "Please enter the name of the file you want to read" << std::endl;
			std::cout << "All assignment examples are located in the examples directory" << std::endl;
			std::cout << "to read in 'long_nested.txt', for example, type long_nested.txt and press return" << std::endl;
			std::cin >> fileName;
			FRXDEO001::read(fileName);
			break;
		case ('p'):
			system("clear");
			if (fileName == " ")
			{
				std::cout << "Please enter the name of the file you want to read" << std::endl;
				std::cout << "All assignment examples are located in the examples directory" << std::endl;
				std::cout << "to read in 'long_nested.txt', for example, type long_nested.txt and press return" << std::endl;
				std::cin >> fileName;
				FRXDEO001::read(fileName);
				break;
			}
			else
			{
				FRXDEO001::print();
				break;
			}
		case ('d'):
			system("clear");
			if (fileName == " ")
			{
				std::cout << "Please enter the name of the file you want to read" << std::endl;
				std::cout << "All assignment examples are located in the examples directory" << std::endl;
				std::cout << "to read in 'long_nested.txt', for example, type long_nested.txt and press return" << std::endl;
				std::cin >> fileName;
				FRXDEO001::read(fileName);
				break;
			}
			else
			{
				FRXDEO001::write();
				break;
			}
		case ('l'):
			system("clear");
			if (fileName == " ")
			{
				std::cout << "Please enter the name of the file you want to read" << std::endl;
				std::cout << "All assignment examples are located in the examples directory" << std::endl;
				std::cout << "to read in 'long_nested.txt', for example, type long_nested.txt and press return" << std::endl;
				std::cin >> fileName;
				FRXDEO001::read(fileName);
				break;
			}
			else
			{
				std::cout << "Enter a tag you would like to list on the terminal" << std::endl;
				std::cin >> tagName;
				FRXDEO001::list(tagName);
				break;
			}

		case ('q'):
			system("clear");
			std::cout << "Thanks for checking out my tag parser :)" << std::endl;
			exit(0);
		default:
			system("clear");
			std::cout << choice << " is not a valid choice. Enter again or press 'q' to quit\n"
					  << std::endl;
			break;
		}
		choice = ' ';
	}

	while (true);
	return 0;
}
