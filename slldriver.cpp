#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "sll.cpp"
#include "sll.hpp"

using namespace std;
//./a.out dataSetA.csv slldatatseta.csv 
//./a.out dataSetB.csv slldatatsetb.csv 
int main(int argc, char* argv[]){
    int testData[10000];
    ifstream inFile;
    ofstream outFile;
    int num = 0;
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    float insert[100];
    float search[100];
    string value;
    string line;
    sll list;
        inFile.open(argv[1]);
        while(getline(inFile,line)){
            stringstream ss(line);
            while(getline(ss, value, ',')){
                num = stoi(value);
                testData[count] = num;
                count++;
            }
        }
        int s = 0;
        int e = 100;
        float num1;
        for(int i = 0; i < 100; i++){
            auto start = chrono::steady_clock::now();
            for(int j = s; j < e; j++){
                list.insertNode(testData[j]);
            }
            auto end = chrono::steady_clock::now();
            num1 = (chrono::duration_cast<chrono::nanoseconds>(end - start).count())/100;
            insert[count2] = num1;
            count2++;
            s += 100;
            e += 100;
        }
        float num2;
        int num3 = 0;
        int num4 = 100;
        for(int i = 0; i < 100; i++){
            auto start = chrono::steady_clock::now();
            for(int j = 0; j < 100; j++){
                num3 = rand()%num4;
                list.searchKey(testData[num3]);
            }
            auto end = chrono::steady_clock::now();
            num2 = (chrono::duration_cast<chrono::nanoseconds>(end - start).count())/100;
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
        list.printPath();
}