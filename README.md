# MeasureTime
该项目暂时用于 C++ 项目中，统计各个函数运行时间，将处理的结果放到 chrome 浏览器中，通过绘图的结果展示时间
# 代码分析和使用过程
* measuretime.cpp 中定义结构体 MeasureTime，在 main 函数或者其他需要测试时间的位置加上 MeasureTime
* 编译 measuretime.cpp ，运行程序，将结果保存到 log.tmp 中
* 编译 convert_to_json.cpp ，执行指令分析日志
 ```
 cat log.tmp | ./convert_to_json -o log.json
 ```
* 打开 chrome 开发者工具，选择 Performance，上传 log.json，分析结果
