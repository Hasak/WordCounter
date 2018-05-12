#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int i,j,c=0,t;
    string tt;
    vector<int> broj(300000);
    vector<string> rijeci(300000);
    ifstream fin;
    ofstream fout;

    fin.open("ResUnSor.txt");
    fout.open("ResSor.txt");
    if(!fin){
        cout<<"File open error!"<<endl;
        return 0;
    }

    while(fin>>broj[c]>>rijeci[c])
        c++;

    for(i=0;i<c-1;i++){
        for(j=i+1;j<c;j++){
            if(broj[i]>broj[j]){
                t=broj[i];
                broj[i]=broj[j];
                broj[j]=t;

                tt=rijeci[i];
                rijeci[i]=rijeci[j];
                rijeci[j]=tt;
            }
        }
    }

    for(i=0;i<c;i++){
        cout<<broj[i]<<" "<<rijeci[i]<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
