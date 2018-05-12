
    int i,j,c=0,cc=0;
    bool stavio;
    string rijec,red;
    vector<int> broj(300000);
    vector<string> rijeci(300000);
    vector<string> unique(300000);
    ifstream fin;
    ofstream fout;

    fin.open("LatEdit.txt");
    fout.open("ResUnSor.txt");
    if(!fin){
        cout<<"File open error!"<<endl;
        return 0;
    }

    while(fin>>rijec){
        rijeci[c]=rijec;
        c++;
    }

    for(i=0;i<c;i++){
        stavio=false;
        for(j=0;j<cc;j++){
            if(rijeci[i]==unique[j]){
                stavio=true;
                break;
            }
        }
        if(!stavio){
            unique[cc]=rijeci[i];
            cc++;
        }
    }

    for(i=0;i<cc;i++){
        for(j=0;j<c;j++){
            if(unique[i]==rijeci[j]){
                broj[i]++;
            }
        }
    }


    for(i=0;i<cc;i++){
        fout<<broj[i]<<" "<<unique[i]<<endl;
    }
    fin.close();
    fout.close();
    return 0;

