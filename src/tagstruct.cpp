/***************************
 * Implementation file of the tagstruct project
 * By Deon Fourie
 * 21 March 2021
 */


#include "tagstruct.h"
#include <string>
#include <iostream>
#include <vector>


struct TagStruct 
{    
	std::string tagName;
    	int numPairs;
	std::string content;
};


std::vector <TagStruct> record;

void FRXDEO001::read(std::string fileName)
{
	std::cout << "read + filename: " << fileName << std::endl;
}


void FRXDEO001::write()
{
	std::cout << "write" << std::endl;		
}


void FRXDEO001::print()
{
	std::cout << "print" << std::endl;
}


void FRXDEO001::list()
{
	std::cout << "list" << std::endl;
}

