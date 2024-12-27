# web_server_Linuxc

# WEB服务器项目
## 需求分析
- 基于HTTP协议的WEB服务器，提供静态页面的下载
- 服务器和浏览器进行通信，传输层使用后tcp协议，应用层使用HTTP协议，浏览器向服务器发送http请求，服务器接收请求后，对请求内容进行解析，明确浏览器目的，服务器需要从请求中提取关键数据，判断对方所请求的文件是否存在并确定类型，构造响应，并回传给浏览器，服务器要支持并发访问。

## 概要分析

- http模块
    对http请求进行解析
    对http响应进行构造
- 资源模块
    判断文件是否存在
    判断文件的类型
- 通信模块
    创建套接字
    组织地址结构
    绑定
    监听
    接收连接请求
    接收http请求
    发送http响应
- 信号模块
    忽略大部分信号
    