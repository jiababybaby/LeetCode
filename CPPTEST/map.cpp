#include <hash_map>
#include <map>
#include <hash_set>
#include <string>
using namespace std;
int main(){

        hash_map<int, string> mymap;
        mymap[9527]="�Ʋ���������";
        mymap[1000000]="�����̵�����";
        mymap[10000]="����Ĺ��ʵ���";

        if(mymap.find(10000) != mymap.end()){
               
        }