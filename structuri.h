
typedef struct biblioteca {
    int nr_carti;  // nr actual de carti din biblioteca
    int nr_genuri_literare;   //nr de genuri literare gasit in biblioteca
    char *Nume;   //numele bibliotecii
} biblioteca;

typedef struct carte {
    char *titlu;     // titlul cartii
    char *autor;     // autorul cartii
    char *sectiune;  // in ce sectiune / categorie se incadreaza
    char *editura;   // editura
    int nr_pagini;   //nr de pagini al cartii
} carte;

typedef struct cititor {
    char *nume;
    int varsta;
    int nr_permis_biblioteca;
    int nr_carti_imprumutate;
} cititor;