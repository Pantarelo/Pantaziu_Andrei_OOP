#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>

std::vector<std::string> cuvinte(const std::string file) {
    std::vector<std::string> words;
    std::string word;

    for (const char& c : file) {
        if (c == ' ' || c == ',' || c == '?' || c == '!' || c == '.') {
            if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        }
        else
            word += c;
    }

    if (!word.empty())
        words.push_back(word);

    return words;
}

class Words_sort {
    public:
        bool operator()(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
            if (a.first == b.first)
                return a.second > b.second;
            else
                return a.first < b.first;
        } 
};

int main() {
    std::ifstream f("file.txt");
    std::string file;
    getline(f, file)
        for (auto& i : file) {
            i = tolower(i);
        }
    
    std::vector<std::string> words = cuvinte(file);
    std::map<std::string, int> words_count;

    for (auto& c : words) 
        words_count[c]++;

    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, Words_sort> pq;

    for (auto& [cuvant, numar] : words_count)
        pq.push(make_pair(numar, cuvant));

    while (!pq.empty()) {
        const auto& top = pq.top();
        std::cout << top.second << " => " << top.first << std::endl;
        pq.pop();
    }

    f.close();
    return 0;
}
