#include <fstream>
#include <iostream>

#include "person.pb.h"

#include <pb2json.h>

using namespace std;
using namespace google::protobuf;

int main(int argc,char *argv[])
{
 	// Test 1: read binary PB from a file and convert it to JSON
	ifstream fin("dump",ios::binary);
	fin.seekg(0,ios_base::end);
	size_t len = fin.tellg();
	fin.seekg(0,ios_base::beg);

        string buf(len, 0);
	fin.read(&buf[0],len);

	string json = pb2json<Person>(buf);
	cout<<json<<endl;

	// Test 2: convert PB to JSON directly
	Person p;
        p.ParseFromString(buf);
	string json2 = pb2json(p);
	cout<<json2<<endl;

	return 0;
}
