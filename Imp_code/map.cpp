#include<iostream>
#include<map>
#include<string>
 
using namespace std;
 
int main(){
 
    // Map is an associative array
    map<string, int>  marksMap;
    marksMap["Atul"] = 58;
    marksMap["Rohit"] = 57;
    marksMap["Kishlay"] = 78;
    marksMap["Aditya"] = 65;
    marksMap["Sachin"] = 53;
 
    map<string,int> :: iterator iter;
    for (iter = marksMap.begin(); iter != marksMap.end(); iter++)
    {
        cout<<(*iter).first<<" "<<(*iter).second<<"\n";
    }
    auto search=marksMap.find("Rohit"); //find with key
    auto search2=marksMap.find("Aaryan"); // return marksMap.end()
    if (search!=marksMap.end())cout<<"Found "<<search->first<<" "<< search-> second<<"\n";
    if (search2==marksMap.end()) cout<<"Not found "<<"\n";
    return 0;
}
