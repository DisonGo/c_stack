<div align="center" id="top"> 
  <img src="./.github/app.gif" alt="C_stack" />

  &#xa0;
</div>

<h1 align="center">C_stack</h1>

<p align="center">
  <img alt="Github top language" src="https://img.shields.io/github/languages/top/DisonGo/c_stack?color=56BEB8">
  <img alt="Github language count" src="https://img.shields.io/github/languages/count/DisonGo/c_stack?color=56BEB8">
  <img alt="Repository size" src="https://img.shields.io/github/repo-size/DisonGo/c_stack?color=56BEB8">
</p>

<p align="center">
  <a href="#dart-about">About</a> &#xa0; | &#xa0; 
  <a href="#sparkles-features">Features</a> &#xa0; | &#xa0;
  <a href="#white_check_mark-requirements">Requirements</a> &#xa0; | &#xa0;
  <a href="#checkered_flag-starting">Starting</a> &#xa0; | &#xa0;
  <a href="https://github.com/DisonGo" target="_blank">Author</a>
</p>

<br>

## About ##

Implementation of stack container in C.

## Features ##

Type support:

| Type | Supported |
| ---- | --------- |
| int  |     Yes   |
| double  |     Yes   |
| char  |     Yes   |

Macros of dynamic type functions call:

```c
// Requiers c_stack header
#include "c_stack.h"
```

| Macros | Description |
| ---- | --------- |
| st_init(type, size, stack_ptr) | Initialize stack |
| st_empty(type, stack_ptr) | Check if stack `length` = 0 |
| st_pop(type, stack_ptr) | Remove last value of stack |
| st_push(type, stack_ptr, value) | Add new value on the end of stack |
| st_remove(type, stack_ptr) | Free memory allocated to stack  |
| st_size(type, stack_ptr) | Get stack `length` |
| st_top(type, stack_ptr) | Get pointer of last value of stack |
| st_valid(type, stack_ptr) | Check if stack fields is valid |



## Requirements ##

Before starting :checkered_flag:, you need to have [Git](https://git-scm.com) and [Brew](https://brew.sh) installed.

## Starting ##

```bash
# Clone this project
$ git clone https://github.com/DisonGo/c_stack

# Access
$ cd c_stack

# Move to source folder
$ cd src
```


Made by <a href="https://github.com/DisonGo" target="_blank">Godison</a>

&#xa0;

<a href="#top">Back to top</a>
