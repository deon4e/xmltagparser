/***************************
 * Implementation file of the tagstruct project
 * By Deon Fourie
 * 21 March 2021
 */


#include "tagstruct.h"

struct TagStruct 
{    
	std::string tagName;
    	int numPairs;
	std::string content;
};


std::vector <TagStruct> record;

void FRXDEO001::read(std::string fileName)
{

	std::string tagName, content;
	int numPairs;
	int counter = 0;

	std::ifstream ifs(fileName);
	if (!ifs)
	{
		std::cerr << "File failed to open" << std::endl;
	}
	std::string line, ifs_str = "";
	while (getline(ifs, line)) {
		ifs_str.append(line);		
	}

	
	ifs.close();

	TagStruct object1, object2;
	object1.tagName = "TXT";
	object1.numPairs = 2;
	object1.content = "ROFL: TOFL";
	record.push_back(object1);

	object2.tagName = "TAG";
	object2.numPairs = 3;
	object2.content = "HELLO";
	record.push_back(object2);
}

std::string FRXDEO001::findTag(std::string line)
{
	std::string start = "<";
	std::string stop = ">";
	unsigned firstLim = line.find(start);
	unsigned lastLim = line.find(stop);
	std::string tag = line.substr(firstLim, lastLim);
	tag = tag.substr(firstLim + start.size()); 
	std::cout << tag << std::endl;
	return tag;

}

std::string FRXDEO001::findContent(std::string line)
{
	std::string start = ">";
	std::string stop = "</";
	unsigned first_delim_pos = line.find(start);
    	unsigned end_pos_of_first_delim = first_delim_pos + start.length();
    	unsigned last_delim_pos = line.find(stop);
	std::string content = line.substr(end_pos_of_first_delim,
            last_delim_pos - end_pos_of_first_delim);
	std::cout << content << std::endl;
	return content;

}

void FRXDEO001::write()
{	
	system("clear");
	char hold;
	std::ofstream ofs("../../output/tag.txt");
	for (int i = 0; i < record.size(); i++)
	{
		ofs << record[i].tagName << ", " << record[i].numPairs << ", " << record[i].content << std::endl;
	}
	ofs.close();
	std::cout << "Printed data to /output/tag.txt" << std::endl;
	std::cout << "\nPress 1 to continue" << std::endl;
	std::cin >> hold;
}


void FRXDEO001::print()
{
	system("clear");
	char hold;
	for (int i = 0; i < record.size(); i++)
	{
		std::cout << record[i].tagName << ", " << record[i].numPairs << ", " << record[i].content << std::endl;
	}

	std::cout << "\nPress 1 to continue" << std::endl;
	std::cin >> hold;
	 
}


void FRXDEO001::list(std::string tag)
{
	system("clear");
	char hold = 1;
	for (int i =0; i<record.size(); i++)
	{
		if (!record[i].tagName.compare(tag))
		{
			std::cout << record[i].tagName << ", " << record[i].numPairs << ", " << record[i].content << std::endl;
			hold = 0;
			break;
		}

	}

	if(hold)
	{
		std::cout << "There are no tags matching: " << tag << std::endl;
	}

	std::cout<<"\nPress 1 to continue" << std::endl;
	std::cin >> hold;

}

