typedef bool (*Handler)(int sock);

class HttpTask
{
	//Http请求处理的任务
private:
	int _cli_sock;
	Handler TaskHandler;
public:
	Handler TaskHandler(int sock, Handler headle);
}

class ThreadPool
{
	//线程池类
	//创建指定数量的线程
	//创建一个线程安全的任务队列
	//提供任务的入队、出队，线程池销毁/初始化接口
}

class HttpServer
{
	//建立一个tcp服务端程序，接收新连接
	//为新连接组织一个线程池任务，添加到线程池中
}

class RequestInfo
{
	//包含HttpRequest解析出的请求信息
}

class HttpRequest
{
	//http数据的接收接口
	//http数据的解析接口
	//对外提供能够获取处理结果的接口
}

class HttpResponse
{
	//提供文件请求相应的接口（完成文件下载/列表功能）接口
	//CGI请求的接口
}

class Upload
{
	//CGI外部程序文件上传功能处理接口
}

class Utils
{
	//提供一些公用的功能接口
}