#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Page {
private:
    class Line {
    private:
        vector<string> words;
        /*bool leadingWhitespace; //alternative solution: if leading whitespace, 
        //just make first element in vector a space*/
    public:
        //constructor here, should take in a string. if leading whitespace, set bool.
        //constructor must deal with comments correctly--easy
        //if at end of line, not as easy other areas
        Line(string in, vector<int>& maxes) {
            if(in.size() == 0) {
                return;
            }
            if(isWhitespace(in.at(0))) {
                words.push_back(" ");
            }
            istringstream input(in);
            string temporary;
            while(input >> temporary) {
                if(temporary.find("//") != string::npos) {
                    //ostringstream os;
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

        int size() {
            return words.size();
        }

        string at(int pos) {
            return words.at(pos);
        }
        string operator[](int pos) {
            return words[pos];
        }
        /*
        //MODIFIES: integer vector input
        //EFFECTS: updates maximum values for lengths of 1st, 2nd, 3rd word etc.
        void updateMax (vector<int>& maxes) {
            
        }*/
        bool isWhitespace(char c) {

        }
    }; 

    
public:
    //constructor here: It should take in a filename and start parsing lines
    Page(string infile, string outfile): infileName(infile), outfileName(outfile) {
        ifstream in(infileName);
        string input;
        while(getline(in, input)) {
            pageLines.push_back(Line(input, maximums));
        }
    }
    //REQUIRES: all file parsing must already be complete
    //MODIFIES: ofstream out
    //EFFECTS: writes the pretty version out to the file
    void writeToFile(ofstream& out) {

    }
private:
    string infileName, outfileName;
    vector<int> maximums = {0, 0, 0, 0, 0};
    vector<Line> pageLines;
};