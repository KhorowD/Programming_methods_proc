#include <iostream>
#include <fstream>
#include "program.h"
namespace type_plants {

void init_list(container *initList)
{
    initList->size = 0;
    initList->head = NULL;
}

void clear_node(struct node *startNode, int pos)
{
    node *currNode = startNode;

    for(int i = 0; i < pos - 1; i++)
    {
        currNode = currNode->next;
    }

    free(currNode);
}

void clear_list(container *listToClear)
{
    if (listToClear->head == NULL)
    {
        return;
    }
    else
    {
        for(int i = listToClear->size; i > 0; i--)
        {
            clear_node(listToClear->head, i);
        }
        listToClear->head = NULL;
    }

    listToClear->size = 0;
}

tree* tree_input(ifstream &ifst)
{
    tree *t = new tree;
    t->name = "";
    int place = 0;
    ifst >> t->name >> t->age >> place;
    t->location_name = location(place);
    return t;
}

bush *bush_input(ifstream &ifst)
{
    bush *b = new bush;
    int mnth;
    int place = 0;
    ifst >> b->name >> mnth >> place;
    b->m = month(mnth);
    b->location_name = location(place);
    return b;
}

bool add_node(container *currentList, ifstream &ifst)
{
    struct node *newNode = new node();
    newNode->plt = plant_input(ifst);

    if(newNode->plt == 0)
    {
        delete (newNode);
        return false;
    }

    if(currentList->head == NULL)
    {
        currentList->head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        newNode->next = currentList->head;
        newNode->prev = currentList->head->prev;
        currentList->head->prev->next = newNode;
        currentList->head->prev = newNode;
    }
    return true;
}

void fill_list(struct container *listToFill,ifstream &ifst)
{
    if (listToFill->head != NULL)
    {
        cout << "LIST IS NOT EMPTY!" << endl;
        return;
    }

    while (!ifst.eof())
    {
        if(add_node(listToFill, ifst))
        {
            (listToFill->size)++;
        }
    }


}

plant *plant_input(ifstream &ifst)
{
    plant *plt_new;
    int k;
    ifst >> k;
    switch (k)
    {
    case 1:
        plt_new = (plant*)tree_input(ifst);
        plt_new->key = TREE;
        break;
    case 2:
        plt_new = (plant*)bush_input(ifst);
        plt_new->key = BUSH;
        break;
    case 3:
        plt_new = (plant*)flower_input(ifst);
        plt_new->key = FLOWER;
        break;

    default:
        return 0;
    }
    return plt_new;
}

void tree_output(struct tree *t, ofstream &ofst)
{
    ofst << "It is tree named: " << t->name
         << " and it's age: " << t->age
         << ", and location name: "<< t->location_name + 1 << endl;
}

void bush_output(struct bush *b, ofstream &ofst)
{
    ofst << "It is bush named: " << b->name
         << " and it's month flowering: " << b->m + 1
         << ", and location name: "<< b->location_name + 1 << endl;
}

bool plant_output(plant *p, ofstream &ofst)
{

    if(p->key == TREE)
    {
        tree_output((tree*)p, ofst);
        return true;
    }
    else if(p->key == BUSH)
    {
        bush_output((bush*)p, ofst);
        return true;
    }
    else if(p->key == FLOWER)
    {
        flower_output((flower*)p, ofst);
        return true;
    }
    else
    {
        ofst << "Incorrect plant!" << endl;
        return false;
    }
}

bool output_node(struct node *headNode, int pos, ofstream &ofst)
{
    node *currentNode = headNode;

    for(int i = 0; i < pos; i++)
    {
        currentNode = currentNode->next;
    }

    if(!plant_output(currentNode->plt, ofst))
    {
        cout << "Cannot to output plant!" << endl;
        return false;
    }

    return true;
}

void output_list(struct container *listToOutput, ofstream &ofst)
{
    if(listToOutput->size == 0)
    {
        cout << "LIST IS EMPTY!" << endl;
        return;
    }

    ofst << "Container contains " << listToOutput->size << " elements. "<<endl;
    for(int i = 0; i < listToOutput->size; i++)
    {
        if(!output_node(listToOutput->head, i, ofst))
        {
            cout << "Node is broken!" << endl;
        }
    }
}

flower *flower_input(ifstream &ifst)
{
    flower *f = new flower;
    int type = 0;
    ifst >> f->name >> type;
    f->flower_kind = kind(type);
    return f;
}

void flower_output(flower *f, ofstream &ofst)
{
    cout << f->flower_kind + 1 << endl;
        ofst << "It is flower named: " << f->name
             << " and it's kind: " << f->flower_kind + 1 << endl;
}

} // end type_plants namespace
