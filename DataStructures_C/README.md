# 《数据结构与算法分析-C语言描述》

* 通过github搜索简直是一大片灾难现场，多少豪言壮志的README.md，最后坚持下来的没几个，大多数进度都凉在起步不久，哎。

### 文件命名规范

1. 一章一个chapter文件夹，eg:chapter1
2. 每个程序的命名根据书中命名，书中无名则按照图号命名

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
    "files.autoGuessEncoding": true,
    "todo-tree.highlights.customHighlight": {
        "TODO": {
            "background": "green",
            "rulerColour": "green",
            "iconColour": "green",
            "rulerLane": "full"
        }
    }
}
```

### todo tree的配置使用

[高亮添加及调整颜色](https://zhuanlan.zhihu.com/p/63303926)

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
2. 特殊情况：约定俗成的大小写比如人名等
3. #define SIZE (num)

### 部分首尾注释模板

```C
/* **********Exercise 4.28********** */
/* **********func start********** */
/* **********func end********** */
```

### TodoLsit

TODO: chapter4添加B树实现
TODO: chapter5添加扩展列实现