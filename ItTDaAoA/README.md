## Introduction of The Design and Analysis of Algorithms

* 《算法设计与分析基础》-Anany Levitin

### 文件命名规范

1. 一章一个chapter文件夹，eg:chapter1
2. 一节一个section文件夹，eg:section1.1
3. 每个程序的命名根据书中命名，书中无名则按照图号命名
4. test文件命名，每个test对应书中每个exercise，eg:0106gcd为sections01_exercise06_functiongcd

### 编译规范

1. 编译C文件生成可执行文件 gcc name.c -o name.o(win10中使用name.exe)
2. 链接其他文件，eg:

```
gcc .\binarysearchtree.c .\bstree_test.c
.\a.exe
```

### setting.json配置

```json
{
    "explorer.confirmDelete": false,
	"fileheader.cursorMode": {
        "description": "",
        "param": "",
        "return": ""
    },
	"fileheader.customMade": {
        "Author": "junhuizhou",
        "Date": "Do not edit",
        "LastEditor": "junhuizhou",
        "LastEditTime": "Do not edit",
        "Description": "header",
        "FilePath": "Do not edit"
    },
    "fileheader.configObj": {
        "prohibitAutoAdd": [ "json", "md" ] 
    },
    "files.autoGuessEncoding": true
}
```

### 计算运行时间

```C
    #include <time.h> //linux为us级，win10中为ms级
    int main()
    {
        clock_t begin,end;
        begin = clock();
        end = clock();
        printf("time of this code is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
        return 0;
    }    
```

### 命名规范

[Google C/C++开源风格](https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/)

个人改动：
1. 函数命名，单个单词的名字首字母大写，多个单词的名字首单词小写
2. 特殊情况，约定俗成的大小写命名，比如人名首字母大写
