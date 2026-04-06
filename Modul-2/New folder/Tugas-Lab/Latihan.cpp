#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::string reverseWords(std::string sentence) {
    std::stringstream ss(sentence);
    std::string word;
    std::vector<std::string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    std::string result = "";
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i != 0) result += " ";
    }

    return result;
}

int main() {
    std::string input = "Halo Dunia C++";
    std::string output = reverseWords(input);

    std::cout << "Input  : " << input << std::endl;
    std::cout << "Output : " << output << std::endl;

    return 0;
}