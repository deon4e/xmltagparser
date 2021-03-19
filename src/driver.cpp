/**
 * Driver file for assignment 1
 * By: Deon Fourie
 *
 */


#include <iostream>
#include <string>

int main(int argc, char** argv){
    const std::string menuDisplay = "r: Read and process tag file\n"
			       "p: Print all tags to the terminal\n"
			       "d: Dump/Write tags and data to a file called tag.txt\n"
			       "l: List/print tag data for a given tag to the terminal\n"
			       "q: Quit\n\n"
			       "Enter an option(r, p, d, l) or q to quit, and press return";     
    char choice = ' ';

    do
    {
	    std::cout << menuDisplay << std::endl;

	    std::cin >> choice;

	    switch(choice){
		    case('p'):
			    std::cout << "p" << std::endl;
		    	    break;
		    case('d'):
			    std::cout << "d" << std::endl;
		    	    break;
		    case('l'):
			    std::cout << "l" << std::endl;
		    	    break;
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
