//
// Created by ZhangMing on 02-27-17
//

#include "mainwindow.h"
#include "function.h"

QMap<QString, int> CourseMap;           // for std::map is unexpected...exm??? QMap fits it
CourseTree *CourseRoot[TOPCOURSENUM] = {nullptr};   // Pointers array
std::stack <CourseTree> CourseStack;    // std::stack is ok:)


void InitMap(void)
{
    // Will be initialized while program started.
    // testing data.
    CourseMap["微积分"] = 1;
    CourseMap["大学物理"] = 2;
    CourseMap["大学英语"] = 3;
    CourseMap["大学语文"] = 4;
    CourseMap["模拟电子技术基础"] = 15;
    CourseMap["数字逻辑"] = 6;
    CourseMap["离散数学"] = 7;
    CourseMap["数据结构"] = 8;
    CourseMap["C语言程序设计"] = 9;
    CourseMap["编译原理"] = 14;
    CourseMap["数据库"] = 17;
    CourseMap["计算机网络"] = 15;
    CourseMap["信号与系统"] = 23;
    CourseMap["数理方程"] = 78;
}

bool BuildCourseTree(void)
{
    FILE *fp;
    fp = fopen("/Users/zhangming/Documents/code/Qtcode/SicunStudioPlatform/courses.txt","r");
    if(!fp)
        return false;
    char perline[30]; // one course's dependency, max 30
    char *p;
    int id;
    int i = 0;

    while(!feof(fp))
    {
        CourseTree *root;
        CourseTree *tmp,*pre;
        fgets(perline,30,fp);   // will be read 29 records;
        p = perline;
        while(isspace(*p)) p++; // skip blanks
        if(perline[0] == '\n')
        {
            i++;
            CourseRoot[i] = new CourseTree;
            CourseRoot[i]->child = nullptr;
            CourseRoot[i]->sibling = nullptr;
            continue;
        }
        sscanf(p,"%d",&id);

        if(!CourseRoot[i])
        {
            root = new CourseTree;
            root->child = nullptr;
            root->sibling = nullptr;
            root->CourseId = id;
            CourseRoot[i] = root;
        }
        else
            root = FindRoot(id, i);

        while(isdigit(*p)) p++;
        if(*p != '\n')
        {
            while(isspace(*p)) p++;
            pre = new CourseTree;
            sscanf(p,"%d",&id);
            pre->CourseId = id;
            pre->child = nullptr;
            pre->sibling = nullptr;
            root->child = pre;
            while(isdigit(*p)) p++;

            while(*p != '\n')
            {
                while(isspace(*p)) p++;
                tmp = new CourseTree;
                sscanf(p,"%d",&id);
                tmp->CourseId = id;
                tmp->child = nullptr;
                tmp->sibling = nullptr;
                pre->sibling = tmp;
                pre = tmp;
                while(isdigit(*p)) p++;
            }
        }
    }
    return true;
}

// Non-recursive way, to find each time's root
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
            /**
             void stack::pop(void), only to use
             reference stack::top(void) to get the top element,
             then pop it.
            */
            p = &(CourseStack.top());
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
