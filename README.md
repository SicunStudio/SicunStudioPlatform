SicunStudio Platform
=
A platform for SicunStudio, collecting kinds of functions as a PC-end application.

## Overview
Software based on Qt C/C++, HTML, CSS, Javascript. Support service and functions for members in SicunStudio, Obey MIT LICENSE.

## Developers
* [minghust](https://github.com/minghust)
* [aiifabbf](https://github.com/aiifabbf)


## Develope Environment
##### PC Client
Qt creator : Qt5.8

Compiler : LLVM version 7.0.0 (clang-700.1.76)

Debugger: LLDB-340.4.110 

Language: C/C++

##### Web Page(waiting for Shi dalao)

## Architecture
##### Functions
* Course Tree
* Resource Sharing
* ...


##### Services
* Line to HUB
* Line to HUB Email
* Line to Github
* ...

##### ...


## Getting Data
some struggling

## Data Structure
##### Course Tree
**Child-Sibling-Tree**

	
	typedef struct coursetree
	{
    	int CourseId;               // course id mapping with its name
    	struct coursetree *child;   // left child
    	struct coursetree *sibling; // right sibling
	}CourseTree;
	
**Stack**

	// using stack for non-recursive way to create and search tree
	using std::stack;
	stack<CourseTree>CourseStack;  
	
**QMap**

	// using QMap for storing <QString-int> info.
	QMap<QString, int> CourseMap;


## Data Processing
#### Course Tree
- **Reading** data(pure courseID) from file to main memory if function was started.
- **Creating** Child-Sibling-Tree.<br \>
- **Mapping** the courseName given by users with each ID, and use the ID to search for root node in the tree told above.<br \>
- **Converting** root information to a info-set(I called it so)which will be shown by front-end.

## Data Visualization

## Algorithm

- Non-recursive searching tree. T(n) = O(N).
 
## PC-end UI

## Web Page UI

## ...

## Welcome our members to make pull requests :)

it seems that this pro will be delayed
