#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string toLow(string a){
    int c=0;
    while(a[c]!='\0'){
        if(a[c]<97 && a[c]!=' ')
            a[c]+=32;
        c++;
    }
    return a;
}


string trim(string a){
    int i=0,j=0;
    char b[2000];
    a=toLow(a);
    while(a[i]!='\0'){
        while(a[i]==a[i+1])
            i++;
        b[j]=a[i];
        i++;
        j++;
    }
    b[j]='\0';
    return b;
}


int main()
{
    int c=0;
    string tt;
    vector<string> rijeci(300000);
    ifstream fin;
    ofstream fout;

    fin.open("LatEdit.txt");
    fout.open("Trim.txt");
    if(!fin){
        cout<<"File open error!"<<endl;
        return 0;
    }
    while(fin>>tt){
        fout<<trim(tt)<<endl;
        c++;
    }


    fin.close();
    fout.close();
    cout <<"\nNumber of words: "<<c<< "\n\nDone!" << endl;
    return 0;
}
