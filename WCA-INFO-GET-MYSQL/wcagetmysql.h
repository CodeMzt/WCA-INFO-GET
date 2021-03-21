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
����һ����ѯwca(world cube)��Ϣ����Ŀ(.lib)
;����mysql
*/
//WCA��ѯ��
class WcaInfoGetByMysql {
private:
	MYSQL conn;
	MYSQL_RES* result;  //�洢��ѯ�Ƚ��
	MYSQL_ROW sql_row;	//��ѯ��������
public:
	WcaInfoGetByMysql(const char* username,const char * password,const char *host,const char* database,unsigned int port);
	~WcaInfoGetByMysql();
	//�����ֻ�IDģ������()
	string* personName(string& name);
	//wcaIdֱ�Ӳ���
	string* wcaId(string& personId);
	//wcaid����������Ŀ��single
	string* single(string& wcaId);
	//wcaid����������Ŀ��avg
	string* avg(string& wcaId);
	string* allInfo(string& wcaId);
};