#include "stdafx.h"
#include "Header.h"
#include <iostream>
#define DateType std::string
using namespace std;

int main() {
	ParserRequest p;
	string r = string("POST http ://www.site.ru/news.html HTTP/1.0\r\nHost: www.site.ru\r\nReferer : http://www.site.ru/index.html\r\nCookie: income = 1\r\nContent - Type: multipart / form - data; boundary = 1BEF0A57BE110FD467A\r\nContent - Length: 209\r\n\r\n");
	p.ParsingRequestForParts(r);
}

//class MyHTTPRequestHandler : public HTTPRequestHandler
//{
//public:
//	virtual void handleRequest(HTTPServerRequest & request,
//		HTTPServerResponse & response) {
//		// Write your HTML response in res object
//	}
//};
//
//class MyRequestHandlerFactory : public HTTPRequestHandlerFactory
//{
//	MyHTTPRequestHandler handler;
//
//public:
//	MyRequestHandlerFactory() {}
//	HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request)
//	{
//		const string method = request.getMethod();
//		if (method == "get" || method == "post")
//			return &handler;
//		return 0;
//	}
//};
//
//int main()
//{
//	HTTPServerParams params;
//	params.setMaxQueued(100);
//	params.setMaxThreads(16);
//	ServerSocket svs(80);
//	MyRequestHandlerFactory factory;
//	HTTPServer srv(&factory, svs, &params);
//	srv.start();
//	while (true)
//		Thread::sleep(1000);
//}

