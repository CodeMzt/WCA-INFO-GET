#pragma once
#include <iostream>
#include <mysql.h>
#include <vector>
#pragma comment(lib,"libmysql.lib")
#pragma warning(disable : 4996)
#pragma comment(lib, "ws2_32.lib") 
#pragma comment(lib, "Wininet.lib")
#define W1 WcaInfoGetByMysql
using namespace std;
/*
这是一个查询wca(world cube)信息的项目(.lib)
途径：mysql
*/
//WCA查询类
class WcaInfoGetByMysql {
private:
	MYSQL conn;
	MYSQL_RES* result;  //存储查询等结果
	MYSQL_ROW sql_row;	//查询返回行数
public:
	WcaInfoGetByMysql(const char* username,const char * password,const char *host,const char* database,unsigned int port);
	~WcaInfoGetByMysql();
	//据名字或ID模糊搜人()
	string* personName(string& name);
	//wcaId直接查找
	string* wcaId(string& personId);
	//wcaid查找所有项目的single
	string* single(string& wcaId);
	//wcaid查找所有项目的avg
	string* avg(string& wcaId);
	string* allInfo(string& wcaId);
};