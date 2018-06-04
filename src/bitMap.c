//
// Created by puzankova 02.06.18
//
#include <math.h>
#include <printf.h>
#include "bitMap.h"

void setBitByNumber(int *array, int bit, int position) {
    // array - pointer to the begining of the array
    // position - number of the bit in the 'array'
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit with number 'position' to the 'bit'

    /* YOUR CODE */

    if (position < 0) {
        printf("Position < 0, error");
        return;
    }
    if (bit > 1 || bit < 0) {
        printf("Wrong bit, error");
        return;
    }
    if (array[position] > 1 || array[position] < 0) {
        printf("Wrong position, error");
        return;
    }
    array[position] = bit;
}

int getBitByNumber(int *array, int position) {
    // this function returns position's bit from the array

    /* YOUR CODE */

    if (array[position] > 1 || array[position] < 0) {
        return -INFINITY;
    }
    return position >= 0 ? array[position] : -INFINITY;
}

void setBitByAddress(void *position, int bit) {
    // position - pointer to the bit to change
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit by memory address to 'bit'

    /* YOUR CODE */

    if (position < 0) {
        printf("Position < 0, error");
        return;
    }
    if (bit > 1 || bit < 0) {
        printf("Wrong bit, error");
        return;
    }
    if (*(int *) position > 1 || *(int *) position < 0) {
        printf("Wrong position, error");
        return;
    }
    *(int *) position = bit;
}

int getBitByAddress(void *position) {
    // this function returns first bit by memory address 'position'

    /* YOUR CODE */

    if (*(int *) position > 1 || *(int *) position < 0) {
        return -INFINITY;
    }
    return position >= 0 ? *(int *) position : -INFINITY;
}