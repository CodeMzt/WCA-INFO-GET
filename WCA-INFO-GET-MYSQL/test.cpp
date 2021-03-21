#include "wcagetmysql.h"
#include <chrono>
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
int main() {
	W1 test("root","mzt.c.y3615","localhost","toppahs",3306);

	high_resolution_clock::time_point bt = high_resolution_clock::now();
	//EXAMPLE: personName
	string name = "ндятнд";
	string * p= test.personName(name);
	int q = 0;
	while (*p !="") {
		cout << *(p++) << "  ";
		if (!(++q % 5))cout << endl;
	}
	high_resolution_clock::time_point et = high_resolution_clock::now();
	milliseconds dt = chrono::duration_cast<milliseconds>(et - bt);
	cout << dt.count() << "ms\n";

	////EXAMPLE: wcaId
	// bt = high_resolution_clock::now();
	//string personId = "2015DUYU01";
	// p = test.wcaId(personId);
	//q = 1;
	//while (q<=5) {
	//	cout << * (p++)<<"  ";
	//	q++;
	//}
	//cout << endl;
	// et = high_resolution_clock::now();
	// dt = chrono::duration_cast<milliseconds>(et - bt);
	//cout << dt.count() << "ms\n";

	////EXAMPLE: single
	// bt = high_resolution_clock::now();
	//personId = "2018WENY02";
	//p = test.single(personId);
	//q = 0;
	//while (*p != "") {
	//	cout << *(p++) << "  ";
	//	if (!(++q % 2))cout << endl;
	//}
	// et = high_resolution_clock::now();
	// dt = chrono::duration_cast<milliseconds>(et - bt);
	//cout << dt.count() << "ms\n";

	////EXAMPLE: avg
	//bt = high_resolution_clock::now();
	//personId = "2018WENY02";
	//p = test.avg(personId);
	//q = 0;
	//while (*p != "") {
	//	cout << *(p++) << "  ";
	//	if (!(++q % 2))cout << endl;
	//}
	//et = high_resolution_clock::now();
	//dt = chrono::duration_cast<milliseconds>(et - bt);
	//cout << dt.count() << "ms\n";


	//EXAMPLE: allInfo
	bt = high_resolution_clock::now();
	string personId = "2018WENY02";
	p = test.allInfo(personId);
	q = 0;
	while (*p != "") {
		cout << *(p++) << "  ";
		if (!(++q % 2))cout << endl;
	}
	et = high_resolution_clock::now();
	dt = chrono::duration_cast<milliseconds>(et - bt);
	cout << dt.count() << "ms\n";

	return 0;
}