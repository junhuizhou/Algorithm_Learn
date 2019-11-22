### 文件命名规范

1. 一章一个chapter文件夹，eg:chapter1
2. 每个程序的命名根据书中命名，书中无名则按照图号命名

### 编译规范

1. 编译C文件生成可执行文件 gcc name.c -o name.o(win10中使用name.exe)

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

[Google C/C++命名规范](https://www.cnblogs.com/chensheng-zhou/p/5127415.html)
