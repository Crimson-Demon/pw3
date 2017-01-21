#ifndef UTIL_H
#define UTIL_H

typedef struct PairInt {
    int first;
    int second;
} PairInt;

PairInt* createPairInt(int first, int second);

void deletePairInt(PairInt* pairInt);

char** str_split(char* a_str, const char a_delim);

#endif // UTIL_H