#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;
using ull = unsigned long long int;

/* Initializes the given value with the soundex values given in the
 * problem prompt.
 * The key of the table is the english alphabet letters
 * The value is the soundex value for that character/letter
 */
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
    /* Initializing container, 
     * Stores the soundex value for each letter in the english
     * alphabet.
     * 
     * The key is the English letter
     * The value is the Soundex value
     */
    unordered_map<char, string> table;

    //Initializing table with values given in problem prompt
    intializeTable(table);

    /* Initializing variables, 
     * word, stores the word we're determining the soundex value for
     * soundexValue, used to construct the soundex value of word
     */
    string word, soundexValue;

    //Goes through all of the values in the given input
    while(getline(cin, word)) {
        //Sets the initial value for soundexValue with the soundex value of the first character in word
        soundexValue = table.at(word[0]);

        //Goes through the rest of the characters in word. If the current character is not a part of the same soundex value group as the previous letter, it appends the current character's soundex value to soundexValue
        for(int index = 1; index < word.size(); index++) 
            if(table.at(word[index]) != table.at(word[index-1]))
                soundexValue += table.at(word[index]);

        //Outputs the current word's soundex value
        cout << soundexValue << endl;
    }
    
    return 0;
}