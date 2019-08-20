#include "Prettifier.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;


//Line constructor, takes in string and vector of maximums. 
//updates vector of maximums while adding words
//if leading whitespace, push a space.
//constructor must deal with comments correctly--easy
//if at end of line, not as easy other areas
Page::Line::Line(string in, vector<int>& maxes) {
    if(in.size() == 0) {
        return;
    }
    if(isspace(in.at(0))) {
        words.push_back(" ");
    }
    istringstream input(in);
    string temporary;
    while(input >> temporary) {
        //deals with comment lines differently--if at beginning of line, leave them be.
        //If not, adjust them to the end
        if(temporary.find("//") != string::npos) {
            //ostringstream os;
            //adjusts comment lines to the end if they aren't at the beginning
            //could be buggy
            if(words.size() > 0) {
                while(words.size() < 5) {
                    words.push_back(" ");
                }
            }
            //add just extracted word back into stream so it can be included in getline
            int lengthUnget = temporary.size();
            for(int i = 0; i < lengthUnget; ++i) {
                input.unget();
            }
            getline(input, temporary);
            words.push_back(temporary);
            //input >> os.rdbuf(); //might be able to use getline!!
            //words.push_back(os.str());
            return;
        }
        //if nothing special, just add in the word and update length
        words.push_back(temporary);
        if(temporary.size() > maxes.at(words.size() - 1)) {
            maxes.at(words.size() - 1) = temporary.size();
        }
        //if there have already been 5 words (label, opcode, and three arguments)
        //then the rest of the line should not be counted toward the max and 
        //should be added as one string 
        if(words.size() > 4) {
            if(getline(input, temporary)) {
                words.push_back(temporary); 
            }                    
            return;
        }
    }
}

int Page::Line::size() {
    return words.size();
}

string Page::Line::at(int pos) {
    return words.at(pos);
}
string Page::Line::operator[](int pos) {
    return words[pos];
}
    
//Page constructor. It should take in a filename and start parsing lines
Page::Page(string infile, string outfile): infileName(infile), outfileName(outfile) {
    ifstream in(infileName);
    string input;
    while(getline(in, input)) {
        pageLines.push_back(Line(input, maximums));
    }
}
//REQUIRES: all file parsing must already be complete
//MODIFIES: ofstream out
//EFFECTS: writes the pretty version out to the file
void Page::writeToFile(ofstream& out) {
    string toAdd;
    //loop through all Lines and then each word
    for(int i = 0; i < pageLines.size(); ++i) {
        Line& currentLine = pageLines.at(i);
        int lineLength = currentLine.size();
        for(int j = 0; j < lineLength; ++j) {
            toAdd = currentLine.at(j);
            //add spaces until correct length
            while(toAdd.size() < maximums.at(j) + 4) {
                toAdd += " ";
            }
            out << toAdd;
        }
        out << endl;
    }
}
