#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/*
 * Empty iterator for checkup iterator end
*/

int
main(int argc, const char *argv[]) {

    istream_iterator<char> eof;

    if (argc < 4) {
        std::cout << "You pass only " << (argc - 1) << " arguments. You should pass 3 paths of files" << std::endl;
        return 1;
    }

    ifstream dataIn1(argv[1], ios::in | ios::binary);
    dataIn1 >> std::noskipws;

    /*
     * Check the existence and accessibility of the first input file
    */
    if (!dataIn1.good()) {
        std::cout << "Input file " << argv[1] << " does not exist!" << std::endl;
        return 1;
    }

    ifstream dataIn2(argv[2], ios::in | ios::binary);
    dataIn2 >> std::noskipws;

    /*
     * Check the existence and accessibility of the second input file
    */
    if (!dataIn2.good()) {
        std::cout << "Input file " << argv[2] << " does not exist!" << std::endl;
        return 1;
    }

    ofstream data_out(argv[3], ios::out | ios::binary);

    /*
     * Check the accessibility of the output file. If file doesn't exists - create new
    */
    if (!data_out.good()) {
        std::cout << "Output file " << argv[3] << " not available!" << std::endl;
        return 1;
    }

    std::istream_iterator<char> dataIn1Iterator(dataIn1);
    std::istream_iterator<char> dataIn2Iterator(dataIn2);
    ostreambuf_iterator<char> outputIterator(data_out);

    bool isPatch = false;

    if (dataIn2Iterator != eof)
        isPatch = (*dataIn2Iterator == 1);

    if (isPatch) dataIn2Iterator++;
    else *outputIterator++ = 1;

    while (dataIn1Iterator != eof || dataIn2Iterator != eof) {
        auto local = static_cast<char>(((dataIn1Iterator != eof) ? *dataIn1Iterator++ : 1) ^
                                       ((dataIn2Iterator != eof) ? *dataIn2Iterator++ : 1));
        if (!isPatch || local != 1) *outputIterator++ = local;
    }

    cout << "Patch successfully " << ((!isPatch) ? "created!" : "applied!") << endl;

    return 0;
}