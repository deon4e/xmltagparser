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

std::vector<TagStruct> record;

void FRXDEO001::read(std::string fileName)
{
	fileName = "../../examples/" + fileName;
	std::ifstream ifs(fileName);
	std::string line;
	std::string fileStr = "";

	if (!ifs)
	{
		std::cerr << "File failed to open" << std::endl;
	}

	while (std::getline(ifs, line))
	{
		fileStr.append(line);
	}

	std::stack<std::string> openTag;
	std::stack<int> closeTag;

	int open = -1;
	int close = -1; 
	int closingTag = 0;
	int i = 0;
 	int	size = fileStr.size(); 

	while (i < size)
	{
		if (fileStr.substr(i, 1) == ">")
		{

			if (close < open)
			{
				close = i;
				if (fileStr.substr(open + 1, 1) != "/")
				{
					closingTag = close;
					closeTag.push(closingTag);
					openTag.push(fileStr.substr(open + 1, close - open - 1));
				}
				else
				{
					std::string tagName = openTag.top();
					openTag.pop();

					int closingTag = closeTag.top();
					closeTag.pop();

					std::string content = fileStr.substr(closingTag + 1, open - closingTag - 1);
					tag(tagName, content);

					if (!openTag.empty())
					{
						int start = closingTag - tagName.size() - 1;
						fileStr.erase(start, close - start + 1);
						i = start - 1;
						close = closeTag.top();
					}
				}
			}
		}
		else if (fileStr.substr(i, 1) == "<")
		{
			open = i;
		}
		size = fileStr.size();
		i++;
	}

	ifs.close();
}

void FRXDEO001::tag(std::string tagName, std::string content)
{
	bool found = false;
	int i = 0;
	while (!found && i < record.size())
	{
		if (record[i++].tagName == tagName)
		{
			found = true;
		}
	}

	if (found)
	{
		record[i - 1].content = record[i - 1].content + ":" + content;
		record[i - 1].numPairs++;
	}
	else
	{
		TagStruct ts = {tagName, 1, content};
		record.push_back(ts);
	}
}

void FRXDEO001::write()
{
	system("clear");
	char hold;
	std::ofstream ofs("../../tag.txt");
	for (int i = 0; i < record.size(); i++)
	{
		ofs << record[i].tagName << ", " << record[i].numPairs << ", " << record[i].content << std::endl;
	}
	ofs.close();
	std::cout << "Printed data to tag.txt in the root directory" << std::endl;
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

void FRXDEO001::list(std::string tagName)
{
	system("clear");
	char hold = 1;
	for (int i = 0; i < record.size(); i++)
	{
		if (!record[i].tagName.compare(tagName))
		{
			std::cout << record[i].tagName << ", " << record[i].numPairs << ", " << record[i].content << std::endl;
			hold = 0;
			break;
		}
	}

	if (hold)
	{
		std::cout << "There are no tags matching: " << tagName << std::endl;
	}

	std::cout << "\nPress 1 to continue" << std::endl;
	std::cin >> hold;
}
