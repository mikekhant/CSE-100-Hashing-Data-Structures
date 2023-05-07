#include <limits>
#include "CountMinSketch.h"
#include "HashFunctions.h"

/**
 * Implement increment() correctly
 */
void CountMinSketch::increment(const string & s) {
    for(unsigned int i=0; i<K; i++) {
        unsigned int hashfunct = hash_functions[i](s);
        hashfunct = hashfunct % M;
        count[i][hashfunct]++;
    }
}

/**
 * Implement find() correctly
 */
unsigned int CountMinSketch::find(const string & s) {
    unsigned int num = 0;
    for(unsigned int i=0; i<K; i++) {
        unsigned int hashfunct = hash_functions[i](s);
        hashfunct = hashfunct % M;
        if(count[i][hashfunct] != 0) {
            if(num < count[i][hashfunct]) {
                num = count[i][hashfunct];
            }
        }
    }
    return num;
}
