#include <iostream>
#include <fstream>
#include <QTest>
#include "test/test.cpp"
#include "program.h"
using namespace std;
using namespace type_plants;

int main(int argc, char const *argv[])
{
//    QTest::qExec(new test_plant);
    if (argc != 3)
    {
        cout << "incorrect command line!"
               << "Waited: command infile outfile" << endl;
        exit(1);
    }
    cout << argv[1] <<endl;
    cout << argv[2] << endl;
    ifstream ifst(argv[1]);

    if(!ifst.is_open())
    {
        cout << "file is not open!" << endl;
        return 1;
    }
    ofstream ofst(argv[2]);
    if(!ofst.is_open())
    {
        cout << "file is not open!" << endl;
        return 1;
    }

    cout << "Start" << endl;
    container *c = new container;
    init_list(c);
    fill_list(c, ifst);
    cout << "Filled container. " << endl;

    output_list(c, ofst);

    ofst << "Sorted" << endl;
    sort(c->size, c->head);
    output_list(c, ofst);

    ofst << "Filtered" << endl;

    output_tree(c, ofst);

    cout << "Multimethod" << endl;
    multimethod(c,ofst);

    clear_list(c);
    cout << "Empty container. " << endl;
    output_list(c, ofst);
    cout << "Stop" << endl;

    return 0;
}
