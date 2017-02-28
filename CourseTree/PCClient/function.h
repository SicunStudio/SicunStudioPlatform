//
// Created by ZhangMing on 02-27-17
//
#ifndef FUNCTION_H
#define FUNCTION_H

#include <cstdio>
#include <QString>
#include <stack>
#include <QMap>

#define TOPCOURSENUM 20
/* -------------course tree--------------- */
typedef struct coursetree
{
    int CourseId;
    struct coursetree *child;   // left child
    struct coursetree *sibling; // right sibling
}CourseTree;


void InitMap(void);
bool BuildCourseTree(void);
bool AddCourse(CourseTree *course);
bool DeleteCourse(CourseTree *course);
bool ModifyCourse(CourseTree *course);
CourseTree *QueryCourse(QString queryname);
CourseTree *FindRoot(int id, int i);
void DataVisualization(void);
/* --------------------------------------- */

#endif // FUNCTION_H
