### 文件命名规范

1. 一章一个chapter文件夹，eg:chapter1
2. 每个程序的命名根据书中命名，书中无名则按照图号命名

### 编译规范

1. 编译CW文件生成可执行文件 gcc name.c -o name.o

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
