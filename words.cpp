#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Queue.h"
#include "TimeSupport.h"

using namespace std;
long K = 1000;

long f(string c){
	long Total=0;
	long i = 0;
	while(i<c.size()){
		Total+=long(c[i]);
		i++;
	}
	return Total % K;
}

void print(Queue** ht){
    for (long i = 0; i < K; i++) {
        cout << i << ": ";
        ht[i]->print();
        cout << endl;
    }
}

bool search(Queue** ht, string key, long s){
//cout<<"hello"<<endl;
   		return ht[s]->find(key);
	
}


int main(int argc, const char * argv[]) {

    
    Queue** hashTable = new Queue*[K];

for (long i = 0; i < K; i++) {
        hashTable[i] = new Queue();
    }

    
    const int N = 500000;
    
    ifstream in("words.txt");
    
    string word;
    
    string* words = new string[N];

    int count = 0;

    

while (in >> word) {
        words[count] = word;
	long c=f(word);
	hashTable[c]->push(word);		
        count++;
	if(count>N-1){
		break;
	}
	//cout<<count<<endl;
    }

//print(hashTable);


   
    cout << "Total: " << count << endl << endl;
    
    cout << "| Matching Progress:                      |\n|";
    int matched = 0;
 	timestamp start = current_time();
  
    for (int i = 0; i < count-1; i++){
        string curr = words[i];
        reverse(curr.begin(), curr.end());
	long c = f(curr);
	//cout<<i<<endl;
        if (search(hashTable, curr, c)){
            //cout << words[i] << " = " << curr << endl;
            matched ++;
        }
        if (i % (N/40) == 0) cout << "-";
    }
    cout << "|" << endl;
  	timestamp end = current_time();
	long duration = time_diff(start, end);
	cout<<duration<<endl;
    
    cout << "Matched: " << matched << endl;

	for (long i = 0; i < K; i++) {
        	delete hashTable[i];
   	 }
    
    // Now delete the array
    	delete[] hashTable;
    return 0;
}
