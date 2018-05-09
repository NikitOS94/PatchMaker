#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include "picosha2.h"

using namespace std;
using namespace picosha2;

void encryptionDecription(vector<unsigned char> hash, istream_iterator<char> dataIn2Iterator,
                          ostreambuf_iterator<char> outputIterator, bool isSkipSalt);

/*
 * Empty iterator for checkup iterator end
*/
istream_iterator<char> eof;

int
main(int argc, const char *argv[]) {


    ifstream dataIn1(argv[1], ios::binary);

    /*
     * Check the existence and accessibility of the first input file
    */
    if (!dataIn1.good()) {
        std::cout << "Input file " << argv[1] << " does not exist!" << std::endl;
        exit(EXIT_FAILURE);
    }

    ifstream dataIn2(argv[2], ios::binary);

    /*
     * Check the existence and accessibility of the second input file
    */
    if (!dataIn2.good()) {
        std::cout << "Input file " << argv[2] << " does not exist!" << std::endl;
        exit(EXIT_FAILURE);
    }

    ofstream data_out(argv[3], ios::out | ios::binary);

    /*
     * Check the accessibility of the output file. If file doesn't exists - create new
    */
    if (!data_out.good()) {
        std::cout << "Output file " << argv[3] << " not available!" << std::endl;
        exit(EXIT_FAILURE);
    }

    /*
     * Vector for hash of input file 1
    */
    vector<unsigned char> hashSHA256(k_digest_size);
    std::istream_iterator<char> dataIn2Iterator(dataIn2);
    ostreambuf_iterator<char> outputIterator(data_out);

    /*
     * Function from library "picosha2" GitHub: https://github.com/okdshin/PicoSHA2
     * Function receive file iterator and return vector with hash
    */
    hash256(istreambuf_iterator<char>(dataIn1), istreambuf_iterator<char>(), hashSHA256.begin(), hashSHA256.end());

    if (dataIn2Iterator != eof)
        if (*dataIn2Iterator == 0) //Checkup the first byte for detection patch or text file
            encryptionDecription(hashSHA256, ++dataIn2Iterator, outputIterator, true);
        else {
            *outputIterator = 0; //Tag for patch file
            encryptionDecription(hashSHA256, dataIn2Iterator, ++outputIterator, false);
        }

    return 0;
}

/*
 * Function to encrypt and decrypt output data.
 * Each letter encrypted by xor logic operation. As a hash has length = 32(256 bites), if encrypted text length is less
 * than 32 or not multiple of 32 function add 0 byte as a bo meaning salt.
 */
void encryptionDecription(vector<unsigned char> hash, istream_iterator<char> dataIn2Iterator,
                          ostreambuf_iterator<char> outputIterator, bool isSkipSalt) {
    while (dataIn2Iterator != eof)
        for_each(hash.begin(), hash.end(),
                 [&](unsigned char c) {
                     auto local = (char) (c ^ ((dataIn2Iterator != eof) ? (*dataIn2Iterator++) : (0)));
                     if (local != 0 || !isSkipSalt) { //skip 0 values if file is text, because 0 is additional salt
                         cout << local << endl;
                         *outputIterator = local;
                         outputIterator++;
                     }
                 });
}