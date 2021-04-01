#include "test.h"
#include <iostream>
#include <fstream>

void test_plant::test_io_tree()
{
    ifstream ifst("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_tree/io_input_tree.txt");
    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }
    cout << "File is open! " << endl;

    ofstream ofst("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_tree/io_output_tree.txt");

    tree *t = tree_input(ifst);
    tree_output(t, ofst);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_tree/io_output_tree.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_tree/io_example_tree.txt");

    if(!file_in_1.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_2.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;

    QTextStream s_in(&file_in_1);
    QTextStream s_out(&file_in_2);

    QString s1 = s_in.readAll();
    QString s2 = s_out.readAll();

    QCOMPARE(s1,s2);

    file_in_1.close();
    file_in_2.close();

}

void test_plant::test_io_bush()
{
    ifstream ifst("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_bush/io_input_bush.txt");
    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }
    cout << "File is open! " << endl;

    ofstream ofst("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_bush/io_output_bush.txt");

    bush *b = bush_input(ifst);
    bush_output(b, ofst);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_bush/io_output_bush.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_bush/io_example_bush.txt");

    if(!file_in_1.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_2.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;

    QTextStream s_in(&file_in_1);
    QTextStream s_out(&file_in_2);

    QString s1 = s_in.readAll();
    QString s2 = s_out.readAll();

    QCOMPARE(s1,s2);

    file_in_1.close();
    file_in_2.close();
}

void test_plant::test_io_flower()
{
    ifstream ifst("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_flower/io_input_flower.txt");
    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }
    cout << "File is open! " << endl;

    ofstream ofst("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_flower/io_output_flower.txt");

    flower *f = flower_input(ifst);
    flower_output(f, ofst);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_flower/io_output_flower.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_flower/io_example_flower.txt");

    if(!file_in_1.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_2.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;

    QTextStream s_in(&file_in_1);
    QTextStream s_out(&file_in_2);

    QString s1 = s_in.readAll();
    QString s2 = s_out.readAll();

    QCOMPARE(s1,s2);

    file_in_1.close();
    file_in_2.close();
}

void test_plant::test_io_plant()
{
    ifstream ifst_1("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_plant/io_input_tree.txt");
    ifstream ifst_2("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_plant/io_input_bush.txt");
    ifstream ifst_3("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_plant/io_input_flower.txt");

    if(!ifst_1.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }

    if(!ifst_2.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }

    if(!ifst_3.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }

    cout << "Files is open! " << endl;

    ofstream ofst_1("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_plant/io_output_tree.txt");
    ofstream ofst_2("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_plant/io_output_bush.txt");
    ofstream ofst_3("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_plant/io_output_flower.txt");

    plant *p1 = plant_input(ifst_1);
    plant_output(p1, ofst_1);

    plant *p2 = plant_input(ifst_2);
    plant_output(p2, ofst_2);

    plant *p3 = plant_input(ifst_3);
    plant_output(p3, ofst_3);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_plant/io_output_tree.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_plant/io_example_tree.txt");

    QFile file_in_3("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_plant/io_output_bush.txt");
    QFile file_in_4("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_plant/io_example_bush.txt");

    QFile file_in_5("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_plant/io_output_flower.txt");
    QFile file_in_6("D:/Projects/Qt/Programming_methods_proc/test/test_io/io_plant/io_example_flower.txt");

    if(!file_in_1.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_2.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;
    if(!file_in_3.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_4.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;
    if(!file_in_5.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_6.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;

    QTextStream s_1(&file_in_1);
    QTextStream s_2(&file_in_2);
    QTextStream s_3(&file_in_3);
    QTextStream s_4(&file_in_4);
    QTextStream s_5(&file_in_5);
    QTextStream s_6(&file_in_6);

    QString s1 = s_1.readAll();
    QString s2 = s_2.readAll();
    QString s3 = s_3.readAll();
    QString s4 = s_4.readAll();
    QString s5 = s_5.readAll();
    QString s6 = s_6.readAll();

    QCOMPARE(s1,s2);
    QCOMPARE(s3,s4);
    QCOMPARE(s5,s6);

    file_in_1.close();
    file_in_2.close();
    file_in_3.close();
    file_in_4.close();
    file_in_5.close();
    file_in_6.close();
}

void test_plant::test_output_tree()
{
    ifstream ifst("D:/Projects/Qt/Programming_methods_proc/test/test_output_only_trees/only_trees_input.txt");
    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }
    cout << "File is open! " << endl;

    ofstream ofst("D:/Projects/Qt/Programming_methods_proc/test/test_output_only_trees/only_trees_output.txt");

    container *c = new container;
    init_list(c);
    fill_list(c, ifst);
    output_tree(c, ofst);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_proc/test/test_output_only_trees/only_trees_output.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_proc/test/test_output_only_trees/only_trees_example.txt");

    if(!file_in_1.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_2.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;

    QTextStream s_in(&file_in_1);
    QTextStream s_out(&file_in_2);

    QString s1 = s_in.readAll();
    QString s2 = s_out.readAll();

    QCOMPARE(s1,s2);

    file_in_1.close();
    file_in_2.close();
}

void test_plant::test_get_consonant()
{
    tree tr;
    bush bh;
    flower fr;

    tr.name = "dub";
    QCOMPARE(get_consonant(&tr),2);
    tr.name = "db";
    QCOMPARE(get_consonant(&tr),2);
    tr.name = "aaa";
    QCOMPARE(get_consonant(&tr),0);

    bh.name = "kust";
    QCOMPARE(get_consonant(&bh),3);
    bh.name = "kkust";
    QCOMPARE(get_consonant(&bh),4);
    bh.name = "uuu";
    QCOMPARE(get_consonant(&bh),0);

    fr.name = "rose";
    QCOMPARE(get_consonant(&fr),2);
    fr.name = "rrose";
    QCOMPARE(get_consonant(&fr),3);
    fr.name = "oeo";
    QCOMPARE(get_consonant(&fr),0);

}

void test_plant::test_compare()
{
    tree *t1 = new tree;
    tree *t2 = new tree;

    t1->name = "topol";
    t2->name = "dub";

    t1->key = TREE;
    t2->key = TREE;

    plant *plt1 = (plant*)t1;
    plant *plt2 = (plant*)t2;


    QCOMPARE(compare(plt1, plt2), false);

    bush *b1 = new bush;
    bush *b2 = new bush;

    b1->name = "malina";
    b2->name = "mozhevelnik";

    b1->key = BUSH;
    b2->key = BUSH;


    plant *plt3 = (plant*)b1;
    plant *plt4 = (plant*)b2;

    QCOMPARE(compare(plt3, plt4), true);

    flower *f1 = new flower;
    flower *f2 = new flower;

    f1->name = "rose";
    f2->name = "fialka";

    f1->key = FLOWER;
    f2->key = FLOWER;

    plant *plt5 = (plant*)f1;
    plant *plt6 = (plant*)f2;

    QCOMPARE(compare(plt5, plt6), true);

}

void test_plant::test_swap()
{
    ifstream ifst("D:/Projects/Qt/Programming_methods_proc/test/test_swap/swap_input.txt");
    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }
    cout << "File is open! " << endl;

    ofstream ofst("D:/Projects/Qt/Programming_methods_proc/test/test_swap/swap_output.txt");

    container *c = new container;
    init_list(c);
    fill_list(c, ifst);

    swap(c->head,0,2);
    swap(c->head,1,3);

    output_list(c, ofst);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_proc/test/test_swap/swap_output.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_proc/test/test_swap/swap_example.txt");

    if(!file_in_1.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_2.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;

    QTextStream s_in(&file_in_1);
    QTextStream s_out(&file_in_2);

    QString s1 = s_in.readAll();
    QString s2 = s_out.readAll();

    QCOMPARE(s1,s2);

    file_in_1.close();
    file_in_2.close();

}

void test_plant::test_sort()
{
    ifstream ifst("D:/Projects/Qt/Programming_methods_proc/test/test_sort/sort_input.txt");
    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        exit(1);
    }
    cout << "File is open! " << endl;

    ofstream ofst("D:/Projects/Qt/Programming_methods_proc/test/test_sort/sort_output.txt");

    container *c = new container;
    init_list(c);
    fill_list(c, ifst);

    sort(c->size, c->head);

    output_list(c, ofst);

    QFile file_in_1("D:/Projects/Qt/Programming_methods_proc/test/test_sort/sort_output.txt");
    QFile file_in_2("D:/Projects/Qt/Programming_methods_proc/test/test_sort/sort_example.txt");

    if(!file_in_1.open((QIODevice::ReadOnly | QIODevice::Text)))
            return;
    if(!file_in_2.open((QIODevice::ReadOnly | QIODevice::Text)))
        return;

    QTextStream s_in(&file_in_1);
    QTextStream s_out(&file_in_2);

    QString s1 = s_in.readAll();
    QString s2 = s_out.readAll();

    QCOMPARE(s1,s2);

    file_in_1.close();
    file_in_2.close();
}



#include "test.moc"
