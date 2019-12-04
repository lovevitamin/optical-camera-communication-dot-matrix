#include <iostream>
#include <string>
#include "fstream"
using namespace std;

int main(){
    string label_file = "jar_30cm.txt";
    std::ifstream labels(label_file.c_str());
    if(!labels.is_open()){
        cout<<"Can't open the label file!"<<endl;
        return -1;
    }
    string line;
    while(std::getline(labels, line)){
        cout<<line<<endl;
    }
    return 0;
}

