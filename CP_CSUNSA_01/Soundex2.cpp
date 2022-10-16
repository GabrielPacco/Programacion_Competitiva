#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;
using ull = unsigned long long int;

void intializeTable(unordered_map<char, string>& table) {
    table.insert(make_pair('B', "1"));
    table.insert(make_pair('F', "1"));
    table.insert(make_pair('P', "1"));
    table.insert(make_pair('V', "1"));

    table.insert(make_pair('C', "2"));
    table.insert(make_pair('G', "2"));
    table.insert(make_pair('J', "2"));
    table.insert(make_pair('K', "2"));
    table.insert(make_pair('Q', "2"));
    table.insert(make_pair('S', "2"));
    table.insert(make_pair('X', "2"));
    table.insert(make_pair('Z', "2"));

    table.insert(make_pair('D', "3"));
    table.insert(make_pair('T', "3"));

    table.insert(make_pair('L', "4"));

    table.insert(make_pair('M', "5"));
    table.insert(make_pair('N', "5"));

    table.insert(make_pair('R', "6"));

    table.insert(make_pair('A', ""));
    table.insert(make_pair('E', ""));
    table.insert(make_pair('I', ""));
    table.insert(make_pair('O', ""));
    table.insert(make_pair('U', ""));
    table.insert(make_pair('H', ""));
    table.insert(make_pair('W', ""));
    table.insert(make_pair('Y', ""));
}

int main(int argc, char** argv) {

    unordered_map<char, string> table;

    intializeTable(table);

    string word, soundexValue;

    while(getline(cin, word)) {
        soundexValue = table.at(word[0]);
        for(int index = 1; index < word.size(); index++) 
            if(table.at(word[index]) != table.at(word[index-1]))
                soundexValue += table.at(word[index]);
        cout << soundexValue << endl;
    }
    
    return 0;
}