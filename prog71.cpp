#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string>& split(const string& s, char delim, vector<string>& elems)
{
    stringstream ss(s);
    string item;
    while (getline(ss,item,delim))
        elems.push_back(item);
    return elems;
}

string simplifyPath(string path)
{
    vector<string> elems;
    vector<string> vs;
    vs.push_back("/");
    split(path, '/',elems);
    for (int i=0;i<elems.size(); i++)
    {
        if (elems[i]=="" || elems[i]==".")
            continue;
        else if (elems[i]=="..")
            vs.pop_back();
        else
            vs.push_back(elems[i]);
    }
    string result;
    for (auto iter=vs.begin(); iter!= vs.end();iter++)
        result += *iter;
    return result;
}

int main()
{
    string path="/a/./b/../../c/";
    cout << path << " : " << simplifyPath(path) << endl;
}

