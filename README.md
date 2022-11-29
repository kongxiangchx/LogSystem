# LogSystem
基于C++的仿Log4j的日志库

## 主要功能
- 日志格式化输出到指定输出地（控制台、文件）
- 日志配置读取

## 日志格式化输出
- 每个日志器都包含一个存储日志格式器的list，日志器会将事件交给自己的日志输出器来进行输出，输出地有两类：控制台、文件。
- 每个日志输出器都有一个日志格式器，因此日志输出器再将事件委托给格式器进行格式化。
- 日志格式器会根据指定的格式字符串，生成一个存储格式项的vector。每个格式项会对传入的事件传出不同的属性，例如线程号格式项会输出事件的线程号。
- 当事件来临的时候，会将它交给一个日志器，然后日志器将事件交给它的日志输出器进行输出

## 日志配置读取
通过yaml-cpp库，读取yaml文件，并将日志配置写入程序
## 多线程导致的线程安全
自旋锁和读写锁