#include <iostream>
#include <fstream>
#include "program.h"
namespace type_plants {

void init_list(container *init_list)
{
    init_list->size = 0;
    init_list->head = NULL;
}

void clear_node(struct node *start_node, int pos)
{
    node *curr_node = start_node;

    for(int i = 0; i < pos - 1; i++)
    {
        curr_node = curr_node->next;
    }

    free(curr_node);
}

void clear_list(container *list_to_clear)
{
    if (list_to_clear->head == NULL)
    {
        return;
    }
    else
    {
        for(int i = list_to_clear->size; i > 0; i--)
        {
            clear_node(list_to_clear->head, i);
        }
        list_to_clear->head = NULL;
    }

    list_to_clear->size = 0;
}

tree* tree_input(ifstream &ifst)
{
    tree *t = new tree;
    t->name = "";
    int place = 0;
    string tmp_name = "";
    long tmp_age = 0;

    ifst >> tmp_name;
    if (ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);

    }
    t->name = tmp_name;

    ifst >> tmp_age;
    if (ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }

    if (tmp_age < 0)
    {
        cout << "Error! Age cant be negative!" << endl;
        exit(1);
    }
    t->age = tmp_age;

    ifst >> place;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }

    if(place < 0 || place > 5)
    {
        cout << "Error! Location number should be value from range <0-5>!" << endl;
        exit(1);
    }
    t->location_name = location(place);

//    ifst >> t->name >> t->age >> place;
//    t->location_name = location(place);
    return t;
}

bush *bush_input(ifstream &ifst)
{
    bush *b = new bush;
    int mnth = 0;
    int place = 0;
    string tmp_name = "";

    ifst >> tmp_name;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }
    b->name = tmp_name;

    ifst >> mnth;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }

    if(mnth < 0 || mnth > 11)
    {
        cout << "Error! Month should be value from range <0-11>" << endl;
        exit(1);
    }
    b->m = month(mnth);

    ifst >> place;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }

    if(place < 0 || place > 5)
    {
        cout << "Error! Location number should be value from range <0-5>!";
        exit(1);
    }
    b->location_name = location(place);
//    ifst >> b->name >> mnth >> place;
//    b->m = month(mnth);
//    b->location_name = location(place);
    return b;
}

bool add_node(container *current_list, ifstream &ifst)
{
    struct node *new_node = new node();
    new_node->plt = plant_input(ifst);

    if(new_node->plt == 0)
    {
        delete (new_node);
        return false;
    }

    if(current_list->head == NULL)
    {
        current_list->head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else
    {
        new_node->next = current_list->head;
        new_node->prev = current_list->head->prev;
        current_list->head->prev->next = new_node;
        current_list->head->prev = new_node;
    }
    return true;
}

void fill_list(struct container *list_to_fill,ifstream &ifst)
{
    if (list_to_fill->head != NULL)
    {
        cout << "LIST IS NOT EMPTY!" << endl;
        return;
    }

    while (!ifst.eof())
    {
        if(add_node(list_to_fill, ifst))
        {
            (list_to_fill->size)++;
        }
    }


}

plant *plant_input(ifstream &ifst)
{
    plant *plt_new;
    int k;
    ifst >> k;
    if(ifst.eof())
    {
        return 0;
    }
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }
    if(k < 1 || k > 3)
    {
        cout << "Error! Key should be value from range <1-3>!" << endl;
        exit(1);
    }
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
         << ", and location name: "<< t->location_name + 1 << endl
         << ", Number of consonants: " << get_consonant(t) << endl;
}

void bush_output(struct bush *b, ofstream &ofst)
{
    ofst << "It is bush named: " << b->name
         << " and it's month flowering: " << b->m + 1
         << ", and location name: "<< b->location_name + 1 << endl
         << ", Number of consonants: " << get_consonant(b) << endl;
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

bool output_node(struct node *head_node, int pos, ofstream &ofst)
{
    node *current_node = head_node;

    for(int i = 0; i < pos; i++)
    {
        current_node = current_node->next;
    }

    if(!plant_output(current_node->plt, ofst))
    {
        cout << "Cannot to output plant!" << endl;
        return false;
    }

    return true;
}

void output_list(struct container *list_to_output, ofstream &ofst)
{
    if(list_to_output->size == 0)
    {
        cout << "LIST IS EMPTY!" << endl;
        return;
    }

    ofst << "Container contains " << list_to_output->size << " elements. "<<endl;
    for(int i = 0; i < list_to_output->size; i++)
    {
        if(!output_node(list_to_output->head, i, ofst))
        {
            cout << "Node is broken!" << endl;
        }
    }
}

flower *flower_input(ifstream &ifst)
{
    flower *f = new flower;
    int type = 0;
    int place = 0;
    string tmp_name = "";

    ifst >> tmp_name;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }
    f->name = tmp_name;

    ifst >> type;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }

    if(type < 0 || type > 2)
    {
        cout << "Error! Type of flower should be value in range <0-2>!" << endl;
        exit(1);
    }
    f->flower_kind = kind(type);

    ifst >> place;
    if(ifst.fail())
    {
        cout << "Error! Unexpected end of input!" << endl;
        exit(1);
    }

    if(place < 0 || place > 5)
    {
        cout << "Error! Location number should be value from range <0-5>!";
        exit(1);
    }
    f->location_name = location(place);

//    ifst >> f->name >> type >> place;
//    f->flower_kind = kind(type);
//    f->location_name = location(place);
    return f;
}

void flower_output(flower *f, ofstream &ofst)
{
    cout << f->flower_kind + 1 << endl;
        ofst << "It is flower named: " << f->name
             << " and it's kind: " << f->flower_kind + 1
             << ", and location name: "<< f->location_name + 1 << endl
             << ", Number of consonants: " << get_consonant(f) << endl;
}


void output_tree(container *list_to_output, ofstream &ofst)
{
    node *current_node;
    if(list_to_output->size == 0)
    {
        cout << "LIST IS EMPTY!" << endl;
        return;
    }

    ofst << "Only trees." << endl;
    for(int i = 0; i < list_to_output->size; i++)
    {
        current_node = list_to_output->head;
        for(int j = 0; j < i; j++)
        {
            current_node = current_node->next;
        }

        if(current_node->plt->key == TREE)
        {
            if (!output_node(list_to_output->head, i,ofst))
            {
                cout << "Node is broken!" << endl;

            }
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
int get_consonant(flower *f)
{
    int count = 0;
    string vowels = "aeiouy";

    for(unsigned int i = 0; i < vowels.size(); i++)
    {
        for(unsigned int j = 0; j < f->name.size(); j++)
        {
             if(vowels[i] == f->name[j])
             {
                 count++;
             }
         }
     }

     return (f->name.size() - count); //возвращаем число (длина - гласные)

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
    if (p->key == FLOWER)
    {
        return get_consonant((flower*)p);
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

void multimethod(struct container *list_to_output, ofstream &ofst)
{
    struct node* curr_node;
    ofst << "Multimethod" << endl;

    for(int i = 0; i < list_to_output->size -1; i++)
    {
        for(int j = i + 1; j < list_to_output->size; j++)
        {
            curr_node = get_node(list_to_output->head, i);
            switch (curr_node->plt->key)
            {
            case TREE:
                curr_node = get_node(list_to_output->head, j);
                switch (curr_node->plt->key) {
                case TREE:
                    ofst << "Tree and tree" << endl;
                    break;
                case BUSH:
                    ofst << "Tree and bush" << endl;
                    break;
                case FLOWER:
                    ofst << "Tree and flower" << endl;
                    break;
                default:
                    ofst << "Unknown key" << endl;
                    break;
                }
                break;
            case BUSH:
                curr_node = get_node(list_to_output->head, j);
                switch (curr_node->plt->key) {
                case TREE:
                    ofst << "Bush and tree" << endl;
                    break;
                case BUSH:
                    ofst << "Bush and bush" << endl;
                    break;
                case FLOWER:
                    ofst << "Bush and flower" << endl;
                    break;
                default:
                    ofst << "Unknown key" << endl;
                    break;
                }
                break;
            case FLOWER:
                curr_node = get_node(list_to_output->head, j);
                switch (curr_node->plt->key) {
                case TREE:
                    ofst << "Flower and tree" << endl;
                    break;
                case BUSH:
                    ofst << "Flower and bush" << endl;
                    break;
                case FLOWER:
                    ofst << "Flower and flower" << endl;
                    break;
                default:
                    ofst << "Unknown key" << endl;
                    break;
                }
                break;
            default:
                ofst << "Unknown key" << endl;
                break;
            }

            output_node(list_to_output->head,i,ofst);
            output_node(list_to_output->head,j,ofst);
        }
    }
}

} // end type_plants namespace
