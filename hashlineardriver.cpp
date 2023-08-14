#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "hashlinear.hpp"
#include "hashlinear.cpp"

using namespace std;
//./a.out dataSetA.csv linedataseta.csv linecollisionsA.csv
//./a.out dataSetB.csv linedatasetb.csv linecollisionsB.csv
int main(int argc, char* argv[]){
    int testData[10000];
    ifstream inFile;
    ofstream outFile;
    ofstream outFile2;
    int num = 0;
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    float insert[100];
    float search[100];
    int collisioni[100];
    int collisions[100];
    string value;
    string line;
    HashTable *tab = new HashTable(10009);
        inFile.open(argv[1]);
        while(getline(inFile,line)){
            stringstream ss(line);
            while(getline(ss, value, ',')){
                num = stoi(value);
                testData[count] = num;
                count++;
            }
        }
        int num5;
        int s = 0;
        int e = 100;
        int temp;
        float num1;
        for(int i = 0; i < 100; i++){
            auto start = chrono::steady_clock::now();
            for(int j = s; j < e; j++){
                tab->insertItem(testData[j]);
            }
            auto end = chrono::steady_clock::now();
            num1 = (chrono::duration_cast<chrono::nanoseconds>(end - start).count())/100;
            num5 = tab->getNumOfCollisioni();
            collisioni[count4] = (num5 - temp)/100;
            count4++;
            temp = tab->getNumOfCollisioni();
            insert[count2] = num1;
            count2++;
            s += 100;
            e += 100;
        }
        float num2;
        int num3 = 0;
        int num4 = 100;
        int num6;
        int temp1 = 0;
        for(int i = 0; i < 100; i++){
            auto start = chrono::steady_clock::now();
            for(int j = 0; j < 100; j++){
                num3 = rand()%num4;
                tab->searchItem(testData[num3]);
            }
            auto end = chrono::steady_clock::now();
            num2 = (chrono::duration_cast<chrono::nanoseconds>(end - start).count())/100;
            num6 = tab->getNumOfCollisions();
            collisions[count5] = (num6 - temp1)/100;
            count5++;
            temp1 = tab->getNumOfCollisions();
            search[count3] = num2;
            count3++;
            num4 += 100;
        }
        outFile.open(argv[2]);
        for(int i = 0; i < 100; i++){
            outFile << insert[i] << ",";
        }
        outFile << endl;
        for(int i = 0; i < 100; i++){
            outFile << search[i] << ",";
        }
        outFile.close();
        outFile2.open(argv[3]);
        for(int i = 0; i < 100; i++){
            outFile2 << collisioni[i] << ",";
    
        }
        outFile2 << endl;
        for(int i = 0; i < 100; i++){
            outFile2 << collisions[i] << ",";
        }
        outFile2.close();
        tab->printTable();
}