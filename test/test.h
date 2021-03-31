#ifndef TEST_H
#define TEST_H
#include <QtTest/QtTest>
#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "program.h"

using namespace type_plants;
class test_plant : public QObject
{
    Q_OBJECT

private slots:
    void test_io();
    void test_output_tree();
    void test_get_consonant();
    void test_compare();
    void test_swap();
    void test_sort();

};

#endif // TEST_H
