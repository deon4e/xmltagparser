/**
 * Driver file for assignment 1
 * By: Deon Fourie
 *
 */

#include "tagstruct.h"
#include <iostream>
#include <string>



int main(int argc, char** argv){
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
	    switch(choice){
		    case('r'):
			    std::cout << "Please enter the path of the file you want to read" << std::endl;
			    std::cin >> fileName;
			    FRXDEO001::read(fileName);
		    	    break;
		    case('p'):
			    if (fileName == " "){
			    	std::cout << "Please choose a file to read in first" << std::endl;
				std::cin >> fileName;
				break;
			    }
			    else {
				FRXDEO001::print();
		    	    	break;
			    }
		    case('d'):
			    if (fileName == " "){
			    	std::cout << "Please choose a file to read in first" << std::endl;
				std::cin >> fileName;
				break;
			    }
			    else {
				FRXDEO001::write();
		    	    	break;
			    }
		    case('l'):
			    if (fileName == " "){
			    	std::cout << "Please choose a file to read in first" << std::endl;
				std::cin >> fileName;	
				break;
			    }
			    else {
			    	std::cout << "Enter a tag you would like to list on the terminal" << std::endl;
				std::cin >> tagName;
				FRXDEO001::list();
		    	    	break;
			    }
	
		    case('q'):
			    std::cout << "q" << std::endl;
		    	    exit(0);
		    default:
			    std::cout << choice << " is not a valid choice. Enter again or press 'q' to quit\n" << std::endl;
			    break;
	    }
	    choice = ' ';
    }

    while(true);
    return 0;
    
}
