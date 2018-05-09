#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include "picosha2.h"

using namespace std;
using namespace picosha2;

void encryptionDecription(vector<unsigned char> hash, istream_iterator<byte_t> dataIn2Iterator,
                          ostreambuf_iterator<char> outputIterator, bool isSkipSalt);

/*
 * Empty iterator for checkup iterator end
*/
istream_iterator<byte_t> eof;

int
main(int argc, const char *argv[]) {

    if (argc < 4) {
        std::cout << "You pass only " << (argc - 1) << " arguments. You should pass 3 paths of files" << std::endl;
        exit(EXIT_FAILURE);
    }

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
    std::istream_iterator<byte_t> dataIn1Iterator(dataIn1);
    std::istream_iterator<byte_t> dataIn2Iterator(dataIn2);
    ostreambuf_iterator<char> outputIterator(data_out);

    bool isPatch = false;

    while(dataIn1Iterator != eof || dataIn2Iterator != eof){

    }

    if (dataIn2Iterator != eof) {
        if (*dataIn2Iterator == 0) { //Checkup the first byte for detection patch or text file
            encryptionDecription(hashSHA256, ++dataIn2Iterator, outputIterator, true);
            return 0;
        }
    }

    *outputIterator = 0; //Tag for patch file
    encryptionDecription(hashSHA256, dataIn2Iterator, ++outputIterator, false);

    return 0;
}

/*
 * Function to encrypt and decrypt output data.
 * Each letter encrypted by xor logic operation. As a hash has length = 32(256 bites), if encrypted text length is less
 * than 32 or not multiple of 32 function add 0 byte as a bo meaning salt.
 */
void encryptionDecription(vector<unsigned char> hash, istream_iterator<byte_t> dataIn2Iterator,
                          ostreambuf_iterator<char> outputIterator, bool isSkipSalt) {
    do {
        for_each(hash.begin(), hash.end(),
                 [&](unsigned char c) {
                     cout<<(int)*dataIn2Iterator;
                     auto local = (char) (c ^ ((dataIn2Iterator != eof) ? (*dataIn2Iterator++) : 1));
                     if (local != 1 || !isSkipSalt) //skip 0 values if file is text, because 0 is additional salt
                         *outputIterator++ = local;
                 });
    } while (dataIn2Iterator != eof);

    if (!isSkipSalt)
        cout << "Patch successfully created!"<<endl;
    else
        cout << "Patch successfully applied!"<<endl;
}