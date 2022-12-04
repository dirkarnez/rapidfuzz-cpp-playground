#include <rapidfuzz/fuzz.hpp>
#include <string>
#include <algorithm>    // std::sort
#include <iostream>
#include <vector>

int main()
{
  std::vector<std::string> book_names = {
    "HTML How to program",
    "Java How to program",
    "C++ How to program"
  };

  std::string search = "C Language";
  std::sort(book_names.begin(), book_names.end(), [search](std::string a, std::string b) {
    return rapidfuzz::fuzz::ratio(search, a) > rapidfuzz::fuzz::ratio(search, b);
  });

  std::cout << "book_names contains:" << std::endl;
  for (std::vector<std::string>::iterator it = book_names.begin(); it != book_names.end(); ++it)
  {
    std::cout << *it << std::endl;
  }

  std::cout << std::endl;

  std::cin.get();
  return 0;
}