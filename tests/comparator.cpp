//
// Created by Nikita on 10.05.18.
//

#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int
main(int argc, const char *argv[]) {

    istream_iterator<char> eof;

    ifstream dataIn1(argv[1], ios::in | ios::binary);
    dataIn1 >> std::noskipws;

    /*
     * Check the existence and accessibility of the first input file
    */
    if (!dataIn1.good()) {
        std::cout << "Input file " << argv[1] << " does not exist!" << std::endl;
        exit(EXIT_FAILURE);
    }

    ifstream dataIn2(argv[2], ios::in | ios::binary);
    dataIn2 >> std::noskipws;

    /*
     * Check the existence and accessibility of the second input file
    */
    if (!dataIn2.good()) {
        std::cout << "Input file " << argv[2] << " does not exist!" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::istream_iterator<char> dataIn1Iterator(dataIn1);
    std::istream_iterator<char> dataIn2Iterator(dataIn2);

    while (dataIn1Iterator != eof && dataIn2Iterator != eof)
        if (*dataIn1Iterator++ != *dataIn2Iterator++)
            return 1;

    if (dataIn1Iterator != eof || dataIn2Iterator != eof)
        return 1;

    return 0;
}