//
// Created by ZhangMing on 02-27-17
//
#include "mainwindow.h"
#include "function.h"

QMap<QString, int> CourseMap;
CourseTree *CourseRoot[TOPCOURSENUM]; // Pointers array
std::stack <CourseTree> CourseStack;


void InitMap(void)
{
    CourseMap["微积分"] = 1;
}

bool BuildCourseTree(void)
{
    FILE *fp;
    fp = fopen("courses.txt","r");
    if(!fp)
    {
        return false;
    }
    char perline[10]; // one course dependence, max 10
    char *p = perline;
    int i = 0;
    CourseRoot[i] = new CourseTree;
    CourseRoot[i]->child = nullptr;
    CourseRoot[i]->sibling = nullptr;

    while(!feof(fp))
    {
        CourseTree *root;
        CourseTree *tmp,*pre;
        fgets(perline,10,fp); // will be read 9 records;
        p = perline;
        if(perline[0] == '\n')
        {
            i++;
            CourseRoot[i] = new CourseTree;
            CourseRoot[i]->child = nullptr;
            CourseRoot[i]->sibling = nullptr;
            continue;
        }
        root = FindRoot(*p, i);
        root->CourseId = *p;
        if(*++p != '\n')
        {
            pre = root->child;
            pre = new CourseTree;
            pre->CourseId = *p;
            pre->child = nullptr;
            pre->sibling = nullptr;
            for(;*++p != '\n';p++)
            {
                tmp = new CourseTree;
                tmp->CourseId = *p;
                tmp->child = nullptr;
                tmp->sibling = nullptr;
                pre->sibling = tmp;
                pre = tmp;
            }
        }
    }
    return true;
}

// Inorder traversing tree in non-recursive way, to find
// each time's root
CourseTree *FindRoot(int id, int i)
{
    CourseTree *p = CourseRoot[i];
    while(p || !CourseStack.empty())
    {
        if(p)
        {
            CourseStack.push(*p);
            p = p->child;
        }
        else
        {
            CourseStack.pop();
            if(p->CourseId == id) return p;
            p = p->sibling;
        }
    }
    return nullptr;
}

CourseTree *QueryCourse(QString queryname)
{
    int id = CourseMap[queryname];
    CourseTree *p;

    for(int i=0;i<TOPCOURSENUM;i++)
    {
        if((p = FindRoot(id,i))!=nullptr)
            return p;
    }
    return nullptr;
}
