#include <hash_map>
#include <map>
#include <hash_set>
#include <string>
using namespace std;
int main(){

        hash_map<int, string> mymap;
        mymap[9527]="唐伯虎点秋香";
        mymap[1000000]="百万富翁的生活";
        mymap[10000]="白领的工资底线";

        if(mymap.find(10000) != mymap.end()){
               
        }