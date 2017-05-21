#include <string>
#include <sstream>
#include <vector>
#include <iterator>

/*
Small function to split strings (http://stackoverflow.com/questions/236129/split-a-string-in-c).
*/
template<typename Out>
void strsplit(const std::string &s, const char delim, Out result)
{
	std::stringstream ss;

	ss.str(s);
	std::string item;

	while (std::getline(ss, item, delim))
	{
		*(result++) = item;
	}
}

/*
Function to convert a container of std::strings to an array of C-style strings.
*/
template<typename List>
size_t get_C_strings(const List &l, char ***arrays)
{
	char **ptr = (char **)malloc(sizeof(char *)*l.size());

	*arrays = ptr;

	for (auto i = l.cbegin(); i != l.cend(); ++i, ++ptr)
	{
		*ptr = (char *)malloc(i->size() + 1);
		memcpy(*ptr, i->data(), i->size());
		(*ptr)[i->size()] = 0;
	}

	return l.size();
}