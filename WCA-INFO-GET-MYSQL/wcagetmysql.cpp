#include "wcagetmysql.h"
//WcaInfoGetByMysql
//格式化成绩
void format(string& str) {
	str.insert(str.length() - 2, ".");
}
WcaInfoGetByMysql::WcaInfoGetByMysql(const char* username, const char* password, const char* host, const char* database, unsigned int port) {
	if (!mysql_init(&conn)) {
		cout << "[mysql_init() error] " << mysql_error(&conn) << endl;
		exit(EXIT_FAILURE); //表示没有成功地执行一个程序
	}
	if (!mysql_real_connect(&conn, host, username, password, database, port, NULL, 0))
	{
		cout << "[mysql_real_connect() error] " << mysql_error(&conn) << endl;
		exit(EXIT_FAILURE);
	}
	mysql_query(&conn, "SET NAMES GBK"); 
}
WcaInfoGetByMysql::~WcaInfoGetByMysql() {
	mysql_close(&conn);//断开连接,释放一个MYSQL 连接实例
}

string info[150000][5];
string* WcaInfoGetByMysql::personName(string& name) {
	string sql_query = ("select * from persons where name LIKE '%" + name + "%' or id LIKE '%" + name + "%'");
	if (mysql_query(&conn, sql_query.c_str()))
	{
		cout << "[mysql_query() (sql:" << sql_query << ")error]" << mysql_error(&conn) << endl;
		exit(EXIT_FAILURE);
	}
	result = mysql_store_result(&conn);
	if (result) {
		int p=0;
		while(sql_row = mysql_fetch_row(result)) {
			info[p][4]= sql_row[0];
			info[p][3] = sql_row[1];
			info[p][2] = sql_row[2];
			info[p][1] = sql_row[3];
			try {
				info[p++][0] = sql_row[4];
			}
			catch (const std::exception&) {
			}
		}
	}

	return info[0];
}
string info2[2][5];
string* WcaInfoGetByMysql::wcaId(string& personId) {
	string sql_query = ("select * from persons where id  = '" + personId + "'");
	if (mysql_query(&conn, sql_query.c_str()))
	{
		cout << "[mysql_query() (sql:" << sql_query << ")error]" << mysql_error(&conn) << endl;
		exit(EXIT_FAILURE);
	}
	result = mysql_store_result(&conn);
	if (result) {
		int p = 0;
		while (sql_row = mysql_fetch_row(result)) {
			info2[p][4] = sql_row[0];
			info2[p][3] = sql_row[1];
			info2[p][2] = sql_row[2];
			info2[p][1] = sql_row[3];
			try {
				info2[p++][0] = sql_row[4];
			}
			catch (const std::exception&) {
			}
		}
	}

	return info2[0];
}
string info3[40][2];
string* WcaInfoGetByMysql::single(string& wcaId) {
	string sql_query = ("select eventId,best from rankssingle where personId= '" + wcaId + "'");
	if (mysql_query(&conn, sql_query.c_str()))
	{
		cout << "[mysql_query() (sql:" << sql_query << ")error]" << mysql_error(&conn) << endl;
		exit(EXIT_FAILURE);
	}
	result = mysql_store_result(&conn);
	if (result) {
		int p = 0;
		while (sql_row = mysql_fetch_row(result)) {
			string now;
			info3[p][0] =sql_row[0] ;
			now = sql_row[1];
			format(now);
			info3[p++][1] = now;
		}
	}

	return info3[0];
}
string* WcaInfoGetByMysql::allInfo(string& wcaId) {
	single(wcaId);
	string sql_query = ("select eventId,best from ranksaverage where personId= '" + wcaId + "'");
	if (mysql_query(&conn, sql_query.c_str()))
	{
		cout << "[mysql_query() (sql:" << sql_query << ")error]" << mysql_error(&conn) << endl;
		exit(EXIT_FAILURE);
	}
	result = mysql_store_result(&conn);
	if (result) {
		int p = 0;
		while (sql_row = mysql_fetch_row(result)) {
			info3[p][1] += '|';
			string now = sql_row[1];
			format(now);
			info3[p++][1] += now;
		}
	}

	return info3[0];
}
string info4[40][2];
string* WcaInfoGetByMysql::avg(string& wcaId) {
	string sql_query = ("select eventId,best from ranksaverage where personId= '" + wcaId + "'");
	if (mysql_query(&conn, sql_query.c_str()))
	{
		cout << "[mysql_query() (sql:" << sql_query << ")error]" << mysql_error(&conn) << endl;
		exit(EXIT_FAILURE);
	}
	result = mysql_store_result(&conn);
	if (result) {
		int p = 0;
		while (sql_row = mysql_fetch_row(result)) {
			string now;
			info4[p][0] = sql_row[0];
			now = sql_row[1];
			format(now);
			info4[p++][1] = now;
		}
	}

	return info4[0];
}