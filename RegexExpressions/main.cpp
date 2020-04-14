#include <iostream>
#include <string>
#include <regex>

//https://ru.wikipedia.org/wiki/–егул€рные_выражени€
//std::regex - sets a regular expression rule
//std::cmatch - result expression
//std::regex_match(string.c_str(), cmatch_result, regex_regular); //checks the entire string for compliance with the rule
//std::regex_search(string.c_str(), cmatch_result, regex_regular); //searches for the part of the string that matches the condition
//std::regex for_regex_search("email");//searches for the part of the string that matches the condition
//std::regex_replace(str.c_str(), regular, "any_replace_string"); //replaces a regular expression with a string

/*
std::regex regular(
					"(:)"
					"([.]*[^\.]+"
					"[^\.]"
					)


					"(:)" searches for the occurrence of a colon
					"([.]*" any characters, any number || [.]-any character "*" - an unlimited number
					[^\.]+" - exclude everything after the dot, mandatory sign "."
					"+" - whether the previous condition must be met
					"(\.)" - choosing the exact point.
*/

void firstTestRegex()
{
	std::string str = "koska@gmail.com";
	std::cmatch result;
	std::regex regular(
		"([\\w-]+)" //all words
		"(@)" //symbol '@'
		"([\\w-]+)" //all words
		"(\.)" // dot
		"([a-z]{2,6})" //all symbols, size [2,5];
	);

	if (std::regex_match(str.c_str(), result, regular))
		for (size_t i = 0; i < result.size(); ++i)
		{
			std::cout << result[i] << std::endl;
		}

}

void secondTextRegex()
{
	std::string str = "Hello bitches lol@Gmail.com";
	std::cmatch result;
	std::regex regular(
		"([\\w-]+)"
		"(@)"
		"([\\w=]+)"
		"(\.)"
		"([a-z]{2,6})"
	);

	if (std::regex_search(str.c_str(), result, regular))
	{
		for (size_t i = 0; i < result.size(); ++i)
			std::cout << result[i] << std::endl;
	}


}

void thirdTextRegex()
{
	std::string str = "Hello bitches lol@Gmail.com";
	std::cmatch result;
	std::regex regular(
		"([\\w-]+)"
		"(@)"
		"([\\w=]+)"
		"(\.)"
		"([a-z]{2,6})"
	);

	std::cout << std::regex_replace(str.c_str(), regular, "any llol");
}

int main(int argc, char** argv)
{
	
	system("pause >> NULL");
	return 0;
}