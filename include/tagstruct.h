/***********
 * Header file for the Tagstruct C++ project
 * By Deon Fourie
 * 21 March 2021
 */

#ifndef TAGSTRUCT_H
#define TAGSTRUCT_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
namespace FRXDEO001
{
	void read(std::string fileName);
	void write();
	void print();
	void list(std::string tag);
}


#endif
