#include <queue>
#include <unordered_map>

//����һ������ָ��
typedef bool(*Handler)(int sock);

class HttpTask
{
	//Http�����������
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
	//�̳߳���
	//����ָ���������߳�
	//����һ���̰߳�ȫ���������
	//�ṩ�������ӡ����ӣ��̳߳�����/��ʼ���ӿ�
private:
	size_t _max_thread;//��ǰ�̳߳ص�����߳���
	size_t _cur_thr;//��ǰ�̳߳��е��߳���
	std::queue<HttpTask> _task_queue;
	pthread_mutex_t _mutex;
	pthread_cond_t _cond;
	

public:
	ThreadPool(int max) :_max_thread(max)
	{
	}

	bool ThreadPoolInit();//����̴߳�����������/����������ʼ��
	bool PushHttpTask(HttpTask &tt);//�̰߳�ȫ���������
	bool PopHttpTask(HttpTask &tt);//�̰߳�ȫ���������
	bool ThreadPoolStop();//�����̳߳�

private:
	static void *thr_start(void* arg);//����̻߳�ȡ����
};

class HttpServer
{
	//����һ��tcp����˳��򣬽���������
	//Ϊ��������֯һ���̳߳�������ӵ��̳߳���
private:
	int _ser_sock;
	ThreadPool *_tp;
	static bool(HttpHandler)(int sock);//http����Ĵ�����
public:
	bool TcpServerInit();//���Tcp�����socket�ĳ�ʼ�����̳߳صĳ�ʼ��
	bool Start();//��ʼ��ȡ�ͻ�������--�����������������
};

class RequestInfo
{
	//����HttpRequest��������������Ϣ
public:
	std::string _method;//���󷽷�
	std::string _version;//Э��汾
	std::string _path_info;//��Դ·��
	std::string _path_phys;//��Դʵ��·��
	std::string _query_string;//��ѯ�ַ���
	std::unordered_map<std::string, std::string> _hdr_list;//ͷ��Ϣ��ֵ��
	struct stat _stat;
};

class HttpRequest
{
	//http���ݵĽ��սӿ�
	//http���ݵĽ����ӿ�
	//�����ṩ�ܹ���ȡ�������Ľӿ�
private:
	int _cli_sock;
	std::string _http_header;
	RequestInfo _req_info;//���������Ϣ
public:
	HttpRequest() :_cli_sock(-1){}
	bool RecvHttpHeader();//����http����ͷ
	bool ParseHttpHeader();//����ͷ����Ϣ
	RequestInfo& GetRequestInfo();//�����ṩ�������
};

class HttpResponse
{
	//�ṩ�ļ�������Ӧ�Ľӿڣ�����ļ�����/�б��ܣ��ӿ�
	//CGI����Ľӿ�
private:
	int _cli_sock;
	std::string _etag;//�Ƿ��޸Ĺ�
	std::string _mtime;//���һ�ε��޸�ʱ��
	std::string _cont_len;//Context-Length
	
public:
	bool InitResponse(RequestInfo req_info);//��ʼ��һЩ�������Ӧ��Ϣ
	bool ProcessFile(std::string &file);//�ļ����ع���
	bool ProcessList(std::string &path);//�ļ��б���

	bool ProcessCGI(std::string &file);//CGI����Ĵ���
};

class Upload
{
	//CGI�ⲿ�����ļ��ϴ����ܴ���ӿ�
private:
	int _file_fd;
	bool _is_store_file;//��������ȡ�������Ƿ�д���ļ���
	std::string _content_length;
	std::string _file_name;
	std::string _first_boundry;
	std::string _middle_boundry;
	std::string _last_boundry;
public:
	bool InitUploadInfo();//��ʼ���ϴ��ļ�����Ϣ
	bool ProcessUpload();//����ļ��ϴ��洢����
};

class Utils
{
	//�ṩһЩ���õĹ��ܽӿ�
};