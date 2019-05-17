#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;
int main (void){

    ofstream out("log.json", ios::out);
    if(!out.is_open()){
        fprintf(stderr, "open log.json filed\n");
        abort();
    }
    string result = "[\n", tmp;
    while(getline(cin, tmp)){
        if(tmp.find("MeasureTime") == tmp.npos)
            continue;
        result += string("    ") + tmp + string("\n");
    }
    result += string("]");
    out.write(result.c_str(), result.length());
    out.close();

    return 0;
}