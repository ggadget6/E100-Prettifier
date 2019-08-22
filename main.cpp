#include "Prettifier.h"
#include <fstream>
#include <cassert>

using namespace std;

int main(int argc, char* argv[]) {    
    assert(argc == 3);
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    Page toFix(infile, outfile);
    toFix.writeToFile();
}