#include<iostream>
#include <unordered_map>
#include <map>
using namespace std;


int main(){
    // Creating Hashmap
    unordered_map<string, int> m;

    // Inserting values in hashmaps
    // 1
    pair<string,int> p("Mohsin", 1001);
    m.insert(p);

    // 2
    pair<string,int> pair2 = make_pair("Behzad", 2001);
    m.insert(pair2);

    // 3
    m["moni"] = 3001;

    m["moni"] = 4001;

    // Search
    cout<< m.at("moni") << endl;
    cout<< m["Mohsin"] << endl;

    cout<<m["unknownKey"] << endl;
    cout<<m.at("unknownKey") << endl;

    // size
    cout<< "size is " << m.size() << endl;

    // count
    cout<< m.count("Mohsin") << endl;
    cout<< m.count("hahaha") << endl;

    // erase
    m.erase("Mohsin");
    cout<<"new size becomes after erase " << m.size() << endl;


    // for(auto i:m){
    //     cout<< i.first << " " << i.second << endl;
    // }

    // Traverse using iterator
    unordered_map<string,int> :: iterator it = m.begin();

    while(it!=m.end()){
        cout<<it->first<< " " <<it->second<< endl;
        it++;
    }
}