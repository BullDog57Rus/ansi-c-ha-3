//
// Created by puzankova 02.06.18
//
#include <math.h>
#include <printf.h>
#include "bitMap.h"

#define BITE_SIZE 8

void setBitByNumber(int *array, int bit, int position) {
    // array - pointer to the begining of the array
    // position - number of the bit in the 'array'
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit with number 'position' to the 'bit'

    /* YOUR CODE */

    int bitsInt = sizeof(int) * BITE_SIZE;
    int shiftRight = position % bitsInt;
    int elem = position / bitsInt;
    unsigned int mask = (unsigned int) (1 << (bitsInt - 1));
    mask >>= shiftRight;
    if (bit) {
        array[elem] |= mask;
    } else {
        array[elem] &= ~mask;
    }
}

int getBitByNumber(int *array, int position) {
    // this function returns position's bit from the array

    /* YOUR CODE */

    int bitsInt = sizeof(int) * BITE_SIZE;
    int shiftRight = position % bitsInt;
    int elem = position / bitsInt;
    unsigned int mask = (unsigned int) (1 << (bitsInt - 1));
    mask >>= shiftRight;
    mask &= array[elem];
    return mask == 0 ? 0 : 1;
}

void setBitByAddress(void *position, int bit) {
    // position - pointer to the bit to change
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit by memory address to 'bit'

    /* YOUR CODE */

    int bitsInt = sizeof(int) * BITE_SIZE;
    unsigned int mask = (unsigned int) (1 << (bitsInt - 1));
    if (bit) {
        *(int *) position |= mask;
    } else {
        *(int *) position &= ~mask;
    }
}

int getBitByAddress(void *position) {
    // this function returns first bit by memory address 'position'

    /* YOUR CODE */

    int bitsInt = sizeof(int) * BITE_SIZE;
    unsigned int mask = (unsigned int) (1 << (bitsInt - 1));
    mask &= *(int *) position;
    return mask == 0 ? 0 : 1;
}