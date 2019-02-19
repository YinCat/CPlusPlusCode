#include <queue>
#include <unordered_map>

//定义一个函数指针
typedef bool(*Handler)(int sock);

class HttpTask
{
	//Http请求处理的任务
private:
	int _cli_sock;
	Handler TaskHandler;
public:
	void SetHttpTask(int sock, Handler handle)
	{
		_cli_sock = sock;
		TaskHandler = handle;
	}
	void Handler()
	{
		TaskHandler(_cli_sock);
	}
};

class ThreadPool
{
	//线程池类
	//创建指定数量的线程
	//创建一个线程安全的任务队列
	//提供任务的入队、出队，线程池销毁/初始化接口
private:
	size_t _max_thread;//当前线程池的最大线程数
	size_t _cur_thr;//当前线程池中的线程数
	std::queue<HttpTask> _task_queue;
	pthread_mutex_t _mutex;
	pthread_cond_t _cond;
	

public:
	ThreadPool(int max) :_max_thread(max)
	{
	}

	bool ThreadPoolInit();//完成线程创建，互斥锁/条件变量初始化
	bool PushHttpTask(HttpTask &tt);//线程安全的任务入队
	bool PopHttpTask(HttpTask &tt);//线程安全的任务出队
	bool ThreadPoolStop();//销毁线程池

private:
	static void *thr_start(void* arg);//完成线程获取任务
};

class HttpServer
{
	//建立一个tcp服务端程序，接收新连接
	//为新连接组织一个线程池任务，添加到线程池中
private:
	int _ser_sock;
	ThreadPool *_tp;
	static bool(HttpHandler)(int sock);//http任务的处理函数
public:
	bool TcpServerInit();//完成Tcp服务端socket的初始化，线程池的初始化
	bool Start();//开始获取客户端连接--创建任务，任务入队列
};

class RequestInfo
{
	//包含HttpRequest解析出的请求信息
public:
	std::string _method;//请求方法
	std::string _version;//协议版本
	std::string _path_info;//资源路径
	std::string _path_phys;//资源实际路径
	std::string _query_string;//查询字符串
	std::unordered_map<std::string, std::string> _hdr_list;//头信息键值对
	struct stat _stat;
};

class HttpRequest
{
	//http数据的接收接口
	//http数据的解析接口
	//对外提供能够获取处理结果的接口
private:
	int _cli_sock;
	std::string _http_header;
	RequestInfo _req_info;//解析后的信息
public:
	HttpRequest() :_cli_sock(-1){}
	bool RecvHttpHeader();//接收http请求头
	bool ParseHttpHeader();//解析头部信息
	RequestInfo& GetRequestInfo();//向外提供解析结果
};

class HttpResponse
{
	//提供文件请求相应的接口（完成文件下载/列表功能）接口
	//CGI请求的接口
private:
	int _cli_sock;
	std::string _etag;//是否修改过
	std::string _mtime;//最后一次的修改时间
	std::string _cont_len;//Context-Length
	
public:
	bool InitResponse(RequestInfo req_info);//初始化一些请求的响应信息
	bool ProcessFile(std::string &file);//文件下载功能
	bool ProcessList(std::string &path);//文件列表功能

	bool ProcessCGI(std::string &file);//CGI请求的处理
};

class Upload
{
	//CGI外部程序文件上传功能处理接口
private:
	int _file_fd;
	bool _is_store_file;//接下来获取的数据是否写到文件中
	std::string _content_length;
	std::string _file_name;
	std::string _first_boundry;
	std::string _middle_boundry;
	std::string _last_boundry;
public:
	bool InitUploadInfo();//初始化上传文件的信息
	bool ProcessUpload();//完成文件上传存储功能
};

class Utils
{
	//提供一些公用的功能接口
};