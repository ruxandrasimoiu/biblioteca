
typedef struct book {
    char *titlu;     // titlul cartii
    char *autor;     // autorul cartii
    char *sectiune;  // in ce sectiune / categorie se incadreaza
    char *editura;   // editura
    int nr_pagini;   //nr de pagini al cartii
    int index_biblioteca;
} *carte;

typedef struct sect {
    char* nume;
    int nr_carti;
    carte* carti;
} *sectiune;

typedef struct bibl {
    int nr_carti;  // nr actual de carti din biblioteca
    int nr_genuri_literare;   //nr de genuri literare gasit in biblioteca
    char *Nume;   //numele bibliotecii
    carte *toate_cartile;
    sectiune *sectiuni;
} *biblioteca;

typedef struct reader {
    char *nume;  //numele cititorului
    int varsta;  //varsta cititorului
    int nr_permis_biblioteca;   //nr permisului de biblioteca
    int nr_carti_imprumutate;   // cate carti a imprumutat
    carte *carti_imprumutate;   // vector cu carile imprumutate
} *cititor;