using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

struct img{
    string type;
    int dim[2];
    int depth;
    int ***value;
};

void line();

void p3_identity(img);

void p3_rgb_rotate(img);

void p3_grayscale(img);

void p3_saturate_channel(img,char);

void p3_crop(img,int[]);

int main(int argc, char *argv[]){
    string fName = string(argv[1]);

    fstream fIn;
    fIn.open(fName, ios::in);
    if(!(fIn.is_open())) {
        line();
        cout << "Missing file name!" << endl;
        line();

        return 0;
    }

    img F;

    fIn >> F.type;
    fIn >> F.dim[0] >> F.dim[1];
    fIn >> F.depth;

    F.value = new int**[F.dim[1]];
    for(int i=0; i<F.dim[1]; i++){

        F.value[i] = new int*[F.dim[0]];
        for(int j=0; j<F.dim[0]; j++){

            F.value[i][j] = new int[3];
            for(int k=0; k<3; k++){fIn >> F.value[i][j][k];}
        }
    }

    fIn.close();

    if(string(argv[2])=="--identity"){p3_identity(F);}

    else if(string(argv[2])=="--rgb-rotate"){p3_rgb_rotate(F);}

    else if(string(argv[2])=="--grayscale"){p3_grayscale(F);}

    else if(string(argv[2])=="--reder"
         || string(argv[2])=="--greener"
         || string(argv[2])=="--bluer"){p3_saturate_channel(F,string(argv[2])[2]);}

    else if(string(argv[2])=="--crop"){
        int C[4] = {stoi(argv[3]),stoi(argv[4]),stoi(argv[5]),stoi(argv[6])};
        p3_crop(F,C);
    }

    return 0;
}

void line(){cout << "--------------------------------" << endl;}

void p3_identity(img imgF){
    cout << imgF.type << endl;
    cout << imgF.dim[0] << " " << imgF.dim[1] << endl;
    cout << imgF.depth << endl;

    for(int i=0; i<imgF.dim[1]; i++){
        for(int j=0; j<imgF.dim[0]; j++){
            for(int k=0; k<3; k++){cout << imgF.value[i][j][k] << " ";}
        }
        cout << endl;
    }
}

void p3_rgb_rotate(img imgF){
    cout << imgF.type << endl;
    cout << imgF.dim[0] << " " << imgF.dim[1] << endl;
    cout << imgF.depth << endl;

    for(int i=0; i<imgF.dim[1]; i++){
        for(int j=0; j<imgF.dim[0]; j++){
            cout << imgF.value[i][j][1] << " ";
            cout << imgF.value[i][j][2] << " ";
            cout << imgF.value[i][j][0] << " ";
        }
        cout << endl;
    }
}

void p3_grayscale(img imgF){
    cout << imgF.type << endl;
    cout << imgF.dim[0] << " " << imgF.dim[1] << endl;
    cout << imgF.depth << endl;

    int Gray;
    for(int i=0; i<imgF.dim[1]; i++){
        for(int j=0; j<imgF.dim[0]; j++){
            Gray = 0.2989*imgF.value[i][j][0]
                 + 0.5870*imgF.value[i][j][1]
                 + 0.1140*imgF.value[i][j][2];

            for(int k=0; k<3; k++){cout << Gray << " ";}
        }
        cout << endl;
    }
}

void p3_saturate_channel(img imgF, char choice){
    cout << imgF.type << endl;
    cout << imgF.dim[0] << " " << imgF.dim[1] << endl;
    cout << imgF.depth << endl;

    for(int i=0; i<imgF.dim[1]; i++){
        for(int j=0; j<imgF.dim[0]; j++){
            switch(choice){
                case 'r': imgF.value[i][j][0] *= 1.3; break;
                case 'g': imgF.value[i][j][1] *= 1.3; break;
                case 'b': imgF.value[i][j][2] *= 1.3; break;
            }
            for(int k=0; k<3; k++){cout << imgF.value[i][j][k] << " ";}
        }
        cout << endl;
    }
}

void p3_crop(img imgF, int imgC[]){
    cout << imgF.type << endl;

    imgF.dim[0] -= (imgC[0]+imgC[3]);
    imgF.dim[1] -= (imgC[1]+imgC[2]);
    cout << imgF.dim[0] << " " << imgF.dim[1] << endl;

    cout << imgF.depth << endl;

    for(int i=imgC[1]; i<(imgF.dim[1]+imgC[1]); i++){
        for(int j=imgC[0]; j<(imgF.dim[0]+imgC[0]); j++){
            for(int k=0; k<3; k++){cout << imgF.value[i][j][k] << " ";}
        }
        cout << endl;
    }
}