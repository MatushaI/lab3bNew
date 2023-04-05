#ifndef Tablehd_h
#define Tablehd_h

#include <stdio.h>

typedef struct NodeHD {
    unsigned long long infoOffset;
    unsigned long long nextOffset;
    int version;
    int lenght;
} NodeHD;

typedef struct KeySpaceHD {
    unsigned long long latestVersionOffset;
    int key;
} KeySpaceHD;

typedef struct TableHD {
    unsigned long long maxOffset;
    int maxSize;
    int size;
    FILE *file;
    KeySpaceHD *ks;
} TableHD;

typedef struct Node{
    int version;
    char *info;
    struct Node *prev;
} Node;

typedef struct KeySpace{
    int key;
    char isActive;
    Node *node;
} KeySpace;

typedef struct Table{
    KeySpace *ks;
    int maxSize;
    int realSize;
} Table;

TableHD *importTableHD(FILE *file);
int searchPlaceHD(TableHD *table, int key);
void printTableHD(TableHD *table);
int addInfoHD(TableHD *table, int key, char *info);
int deleteKeyHD(TableHD *table, int key);
int deleteKeyVersionHD(TableHD *table, int key, int version);
int searchKeyDialog(TableHD *table, Table *search, int key);
Table *tableCreate(int size);
void printTable(Table *table);
int searchKeyVersionDialog(TableHD *table, Table *search, int key, unsigned int version);

#endif
