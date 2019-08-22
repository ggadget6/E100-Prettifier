#ifndef PRETTIFIER_H
#define PRETTIFIER_H

#include <vector>
#include <string>
class Page {
private:
    //Line is a wrapper class for a vector. It takes in a line from a file and adjusts it
    //for use in the prettifier.
    class Line {
    private:
        std::vector<std::string> words;
        /*bool leadingWhitespace; //alternative solution: if leading whitespace, 
        //just make first element in vector a space*/
    public:
        //Line constructor, takes in string and vector of maximums. 
        //updates vector of maximums while adding words
        //if leading whitespace, push a space.
        //constructor must deal with comments correctly--easy
        //if at end of line, not as easy other areas
        Line(std::string in, std::vector<int>& maxes);

        //returns size of internal vector
        int size() const;

        //returns element at given index, and does boundary check
        std::string at(int pos);

        //returns element at given index
        std::string operator[](int pos);
        /*
        //MODIFIES: integer vector input
        //EFFECTS: updates maximum values for lengths of 1st, 2nd, 3rd word etc.
        void updateMax (vector<int>& maxes) {
            
        }*/
    }; 

    
public:
    //Page constructor takes in a filename and parses each line in the file.
    //each line goes into a "Line" object
    Page(std::ifstream& infile, std::ofstream& outfile);

    //REQUIRES: all file parsing must already be complete
    //MODIFIES: ofstream out
    //EFFECTS: writes the pretty version out to the file
    void writeToFile();
private:
    std::ifstream& infileName;
    std::ofstream& outfileName;
    std::vector<int> maximums = {0, 0, 0, 0, 0, 0};
    std::vector<Line> pageLines;
};
#endif