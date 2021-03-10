#ifndef PROGRAM_H
#define PROGRAM_H
#include <fstream>
#include <string>
using namespace std;
namespace type_plants {

    enum type {TREE, BUSH}; //  Тип растения: Дерево или кустарник

    // Значение месяца цветения кустарников
    enum month {JAN, FEB, MAR, APR, MAY, JUNE, JULY, AUG, SEPT, OCT, NOV, DEC};
    //  Деревья
    struct tree
    {
        type key;
        string name;    //  имя
        long age;       //  возраст
    };

    //  Кустарники
    struct bush
    {
        type key;
        string name;    //  имя
        month m;        //  Месяц цветения
    };

    //  Структура обощающая все растения
    struct plant
    {
        type key;
        string name;
    };

    struct node
    {
        plant *plt;
        node *next;
        node *prev;
    };

    struct container
    {
        long size;
        node *head;

    };

    void init_list(struct container *newList);
    void clear_node(struct node *startNode, int pos);
    void clear_list(struct container *listToClear);
    void fill_list(struct container *listToFill, ifstream &ifst);
    void output_list(struct container *listToOutput, ofstream &ofst);

    bool add_node(struct container *currentList, ifstream &ifst);
    bool output_node(struct node *headNode, int pos, ofstream &ofst);

    tree* tree_input(ifstream &ifst);
    bush* bush_input(ifstream &ifst);
    void tree_output(struct tree *t, ofstream &ofst);
    void bush_output(struct bush *b, ofstream &ofst);

    int get_consonant(plant *p);
    plant* plant_input(ifstream &ifst);
    bool plant_output(plant *p, ofstream &ofst);

}   // end type_plants namespace
#endif // PROGRAM_H
