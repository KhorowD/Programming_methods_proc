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
    ifst >> t->name >> t->age;
    return t;
}

bush *bush_input(ifstream &ifst)
{
    bush *b = new bush;
    int mnth;
    ifst >> b->name >> mnth;
    b->m = month(mnth);
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

    default:
        return 0;
    }
    return plt_new;
}

void tree_output(struct tree *t, ofstream &ofst)
{
    ofst << "It is tree named: " << t->name
         << " and it's age: " << t->age << endl;
}

void bush_output(struct bush *b, ofstream &ofst)
{
    ofst << "It is bush named: " << b->name
         << " and it's month flowering: " << b->m + 1<< endl;
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

int get_consonant(tree *t)
{
    int count = 0;
        string vowels = "aeiouy";

        for(unsigned int i = 0; i < vowels.size(); i++)
        {
            for(unsigned int j = 0; j < t->name.size(); j++)
            {
                if(vowels[i] == t->name[j])
                {
                    count++;
                }
            }
        }

        return (t->name.size() - count); //возвращаем число (длина - гласные)
}

int get_consonant(bush *b)
{
    int count = 0;
        string vowels = "aeiouy";

        for(unsigned int i = 0; i < vowels.size(); i++)
        {
            for(unsigned int j = 0; j < b->name.size(); j++)
            {
                if(vowels[i] == b->name[j])
                {
                    count++;
                }
            }
        }

        return (b->name.size() - count); //возвращаем число (длина - гласные)

}

int get_consonant(plant *p)
{
    if (p->key == TREE)
    {
        return get_consonant((tree*)p);
    }
    if (p->key == BUSH)
    {
        return get_consonant((bush*)p);
    }

    return -1;
}

bool compare(plant *plt1, plant *plt2)
{
    return get_consonant(plt1) < get_consonant(plt2);
}

node *get_node(node *head, int index)
{
    struct node *returnNode = head;

    for(int i = 0; i < index; i++)
    {
        returnNode = returnNode->next;
    }
    return returnNode;
}

void swap(node *head, int index_first, int index_second)
{
    struct node *temp = new node;

    temp->plt = get_node(head,index_first)->plt;
    get_node(head,index_first)->plt = get_node(head,index_second)->plt;
    get_node(head,index_second)->plt = temp->plt;
}

void sort(int size,struct node *head)
{
    for(int i = 0; i < size -1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(compare(get_node(head,i)->plt, get_node(head,j)->plt))
            {
                swap(head,i,j);
            }
        }
    }
}

} // end type_plants namespace
