#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    cout << v.capacity() << endl;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout << v.capacity() << endl;
    v.push_back(70);
    v.push_back(389);
    cout << v.capacity() << endl;
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v.size() << endl;
    cout << v.at(2) << endl;// dismiss out of bound array
    cout << v.at(3) << endl;//safer to use at()
    v.pop_back();
    cout << v.size() << endl;
 }
 /* instead of push back we can use simple indexing
 but with using indexing it did not increase size of vector*/
 