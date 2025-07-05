#ifndef FUNCTII_H
#define FUNCTII_H
#include "structuri.h"

biblioteca* aloc_bibl();
void init_bibl(biblioteca* b, int nr_carti, int nr_genuri, char* nume);
void free_bibl(biblioteca* bibl);

#endif