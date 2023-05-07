#include "BloomFilter.h"
#include "HashFunctions.h"


/**
 * Implement insert() correctly
 */
void BloomFilter::insert(const string & s) {
    for(unsigned int i=0; i<K; i++) {
        unsigned int hashfunct = hash_functions[i](s);
        hashfunct = hashfunct % M;
        bits[hashfunct] = true;
    }
}

/**
 * Implement find() correctly
 */
bool BloomFilter::find(const string & s) {
    for(unsigned int i=0; i<K; i++) {
        unsigned int hashfunct = hash_functions[i](s);
        hashfunct = hashfunct % M;
        if(bits[hashfunct] == false) {
            return false;
        }
    }
    return true;
}
