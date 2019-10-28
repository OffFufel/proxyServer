#pragma once
#include "stdafx.h"
#include <string>
#include <regex>
#include <iostream>
#define DateType std::string
using namespace std;
//Request-Line [ General-Header | Request-Header | Entity-Header ]\r\n[ Entity-Body ]
struct dataRequest {
	struct RequestLine {
		string RequestLineStr;//"Method Request-URI HTTP-Version\r\n" 
		string Method; //GET, POST
		string RequestURL;///index.html или http://www.myhost.ru/index.html или /index.html?a=1&b=qq
		string HTTPVersion;//HTTP/1.0
	};
	struct GenerealHeader {
		string GeneralHeaderStr;// [Date: value\n | Pragma: no-cache\n] 
		DateType date; //Date  дата по Гринвичу в формате "День недели, Число Месяц Год ЧЧ:ММ:СС GMT"
		bool isCache; //pragma:no-cache?
	};
	struct RequestHeader {
		string RequestHeaderStr;
		string Allow;//"Allow: GET | HEAD\n"
		string From;//"From: myname@mailserver.ru\r\n". 
		DateType ifModifiedSince; //dlya Get Дата указывается по Гринвичу в таком же формате, как и для параметра Date в General-Header. 
		string Referer; //"Referrer: www.host.ru/index.html\n". 
		string UserAgent; //"User-Agent: Mozilla/4.0\n" 
	};
	struct EntityHeader {
		string EntityHeaderStr;
		string Allow;//"Allow: GET | BODY\n"
		string ContentEncoding;
		int ContentLength;//"Content-Length: 26457\n".
		string ContentType;//"Content-Type: text/html\n"
		DateType Expires;//"Expires: date\n". Формат даты алогичен формату даты для параметра Date  - когда должна быть удалена из кэша
		DateType LastModified; //время последнего изменения пересылаемых данных
		string ExtentionHeader; //"ParameterName: parametervalue\n". Данные параметры будут игнорироваться, если программа-клиент не знает, как их обработать.Например: "Cookie: r=1\r\n"  устанавливает всем известные печеньки для страницы.
	};
};


class ParserRequest //GET http://www.php.net/ HTTP/1.0\r\n\r\n 
{
public:
	//ParserRequest();
	//~ParserRequest();
	void ParsingRequestForParts(string _url) const {
		const char r = '\r';
		int indexPrev = 0;
		int indexNext = _url.find("\r");
		string _RequestLineStr = string(_url, indexPrev, indexNext - indexPrev);
		cout << _RequestLineStr;
		//regex reg = new regex("\\\r\nContent-Length: (.*?)\\\r\n");
		//match m = reg.Match(headerString);
	};
private:
	dataRequest _data;
};

class ParserResponce
{


};