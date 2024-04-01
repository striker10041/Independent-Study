#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool isMatch(const std::string& text, int start, const std::string& pattern) {
    int textLength = text.length() - start;
    int patternLength = pattern.length();
    int i = start;
    int j = 0;
    int startIndex = -1;
    int match = start;
    bool flag = true;

    while (i < text.length()) {
        if (j < patternLength && (pattern[j] == '?' || pattern[j] == text[i])) {
            i++;
            j++;
        }
        else if (j < patternLength && pattern[j] == '*') {
            startIndex = j;
            match = i;
            j++;
        }
        else if (startIndex != -1) {
            j = startIndex + 1;
            match++;
            i = match;
        }
        else {
            flag = false;
            break;
        }
    }

    while (flag && j < patternLength && pattern[j] == '*') {
        j++;
    }
    return flag && j == patternLength;
}

void findMatch(const std::string& text, const std::string& pattern) {
    std::vector<std::string> matches;
    for (int i = 0; i < text.length(); ++i) {
        if (isMatch(text, i, pattern)) {
            for (int len = 1; len <= text.length() - i; ++len) {
                if (isMatch(text.substr(i, len), 0, pattern)) {
                    matches.push_back(text.substr(i, len));
                }
            }
        }
    }

    std::sort(matches.begin(), matches.end());
    matches.erase(unique(matches.begin(), matches.end()), matches.end());
    for (const auto& match : matches) {
        std::cout << match << std::endl;
    }
}

int main() {
    std::string text, pattern;
    std::cout << "Enter text (example: helloworld): ";
    std::cin >> text;
    std::cout << std::endl <<  "Enter pattern (example: hel**?rl***): ";
    std::cin >> pattern;
    int i = 0, j = 0, startIndex = -1, match = 0;
    bool flag = true;
    for (int ind = 0; ind + 1 < pattern.length(); ) {
        if (pattern[ind] == '*' && pattern[ind + 1] == '*')
            pattern.erase(ind, 1);
        else
            ++ind;
    }   

    findMatch(text, pattern);

    return 0;
}
