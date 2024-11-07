using namespace std;
#include <iostream>
#include <string>
#include <fstream>

const int H = 307;

size_t find_seperator(string,string,int);

string get_word(string,size_t,size_t);

int cut_head(string);

int main(int argc, char *argv[]){
    string fName = string(argv[1]);

    fstream fIn;
    fIn.open(fName, ios::in);
    if(!(fIn.is_open())){cout << "Missing file name!" << endl; return 0;}

    string fLine,fWord;
    getline(fIn,fLine);
    
    int sum1=0, sum2=0, km=0;
    for(int i=0; i<H; i++){
        getline(fIn,fLine);

        sum1 += stoi(get_word(fLine,find_seperator(fLine,",",4),find_seperator(fLine,",",5)));
        sum2 += stoi(get_word(fLine,find_seperator(fLine,",",5),find_seperator(fLine,",",6)));

        fWord = get_word(fLine,find_seperator(fLine,",",8),find_seperator(fLine," km",2));

        try{km += stoi(fWord);}
        catch(invalid_argument){
            km += cut_head(fWord);
        }
    }

    fIn.close();

    cout << endl << "sum of the population in 2016: " << sum1 << endl;
    cout << endl << "sum of the population in 2010: " << sum2 << endl;
    cout << endl << "growth percentage: " << (float(sum1)/float(sum2)-1)*100 << "%" << endl;
    cout << endl << "sum of the size in km2: " << km << endl;
    cout << endl << "density (inhabitants per km2): " << float(sum1)/float(km) << endl;

    fstream fOut;
    fOut.open("ex5-V2-output.txt", ios :: out | ios :: app);

    fOut << sum1 << endl;
    fOut << (float(sum1)/float(sum2)-1)*100 << "%" << endl;
    fOut << float(sum1)/float(km) << endl;

    fOut.close();

    return 0;
}

size_t find_seperator(string fLine, string key, int p){
    size_t s;

    for(int i=0; i<p; i++){s = fLine.find(key,s+1);}

    return s;
}

string get_word(string fLine, size_t s1, size_t s2){
    char fWord[s2-s1];
    for(int i=0; i<(s2-s1-1); i++){fWord[i] = fLine[s1+i+1];}
    fWord[s2-s1-1] = '\0';
    return fWord;
}

int cut_head(string fWord){
    int len=0;
    while(fWord[len]!='\0'){len++;}
    
    char fNum[len];
    for(int i=0; i<(len-1); i++){fNum[i] = fWord[i+1];}
    fNum[len-1] = '\0';

    return stoi(fNum);
}