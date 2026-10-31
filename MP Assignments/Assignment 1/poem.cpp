#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "poem.h"

using namespace std;

Packets::Packets() {
    sourceAddress=0;
    destinationAddress=0;
    sequenceNumber=0;
    sourceIP="";
    destinationIP="";
    checkSum=0;
    length=0;
    data="";
    padding="";
    corrupted=false;
}

Packets::Packets(string s) {
    // pos 0 - 32 -> source add
    // pos 32 - 64 -> destination add
    // pos 64 - 80 -> sequence number
    // pos 80 - 96 -> check sum
    // pos 96 - 112 -> length
    // the rest of it is the data
    int pos=0;
    // use lang siguro line.substring for like accessing
    // bcs accessing it manually is so time consuming. so basically
    // those positions macover then proceed to conversions and stuff like that
    
    // **************
    // october 6, 2026 continuation hahahgsasgh
    
    
    // WHATEVER, im gonna count it manually using for loops AHA~
    
    // i need to use SPAN
    // span is basically the highest value base on the size of it as such that 2^32 = 4294967296
    // but the thing is how do i store it? it cannot fit in a original INT
    
    
    // i need to add a checker first like what if i performed everything 
    sourceAddress=0;
    destinationAddress=0;
    sourceIP="";            // FIX: was sourceIP=0; (a string can't be set to 0)
    destinationIP="";       // FIX: same
    sequenceNumber=0;
    checkSum=0;
    length=0;
    data="";
    padding="";
    corrupted=false;
    int totalBits = s.length();
    if(totalBits<112 || totalBits%16!=0) {
        corrupted=true;
        return;
    }
    
    unsigned long long span = 4294967296ULL;
    for(int i=0; i<32; i++) {
        span=span/2;
        if(s[pos+i]=='1') {
            sourceAddress = sourceAddress + span;
        }
    }
    
    // since there are 4 octets in that i need to divide it and add DOTS
    for(int octet=0; octet<4; octet++) {
        int value=0;
        int half=128; //2^7 = 128 or 2^8-1
        for(int j=0; j<8; j++) {
            if(s[pos+octet*8+j]=='1') {
                value=value+half;
            }
            half=half/2;
        }
        if(octet > 0) sourceIP+=".";
        sourceIP+=to_string(value);
    }
    pos+=32;
    
    span = 4294967296ULL;
    for(int i=0; i<32; i++) {
        span=span/2;
        if(s[pos+i]=='1') {
            destinationAddress = destinationAddress + span;
        }
    }
    
    for(int octet=0; octet<4; octet++) {
        int value=0;
        int half=128; //2^7 = 128 or 2^8-1
        for(int j=0; j<8; j++) {
            if(s[pos+octet*8+j]=='1') {
                value=value+half;
            }
            half=half/2;
        }
        if(octet > 0) destinationIP+=".";
        destinationIP+=to_string(value);
    }
    pos+=32;
    
    int half16=32768;
    for(int i = 0; i<16; i++) {
        if(s[pos+i]=='1') {
            sequenceNumber = sequenceNumber + half16;
        }
        half16=half16/2;
    }
    
    if(sequenceNumber >= 32768) {
        sequenceNumber = sequenceNumber - 65536;
    }
    pos+=16;
    
    half16=32768;
    for(int i = 0; i<16; i++) {
        if(s[pos+i]=='1') {
            checkSum = checkSum + half16;
        }
        half16=half16/2;
    }
    pos+=16;
    
    half16=32768;
    for(int i = 0; i<16; i++) {
        if(s[pos+i]=='1') {
            length = length + half16;
        }
        half16=half16/2;
    }
    pos+=16;
    
    int sum=0;
    int chunks=totalBits/16;
    for(int chunk=0; chunk<chunks;chunk++) {
        int value=0;
        if(chunk!=5) {
            int h=32768;
            for(int j = 0;j<16; j++, h=h/2) {
                if(s[chunk*16+j]=='1') {
                    value=value+h;
                }
            }
        }
        sum=sum+value;
        if(sum>65535) {
            sum=sum-65536;
            sum+=1;
        }
    }
    
    int computed = 65535-sum;
    if(computed!=checkSum) {
        corrupted=true;
    }
    
    if(pos+length>totalBits) {
        corrupted=true;
        return;
    }
    int numC=length/8;
    for(int c=0; c<numC; c++) {
        int value=0;
        int half=128;
        for(int j=0; j<8; j++) {
            if(s[pos+c*8+j]=='1') {
                value=value+half;
            }
            half=half/2;
        }
        data+=(char)value;
    }
    pos+=length;
    for(int i=pos;i<totalBits;i++) {
        padding+=s[i];
    }

}

string Packets::getSourceIP() { 
	return sourceIP; 
}

string Packets::getDestIP() { 
	return destinationIP; 
}

unsigned int Packets::getSourceAddress() { 
	return sourceAddress; 
}

unsigned int Packets::getDestinationAddress() { 
	return destinationAddress; 
}

int Packets::getSequenceNumber() { 
	return sequenceNumber; 
}

int Packets::getCheckSum() { 
	return checkSum; 
}

int Packets::getLength() { 
	return length; 
}

string Packets::getData() { 
	return data; 
}

string Packets::getPadding() { 
	return padding; 
}

bool Packets::politiciansAreCorrupt() { 
	return corrupted; 
}

int main() {
    string filename;
    getline(cin, filename);
    
    ifstream fin(filename.c_str());
    if(!fin) {
        cout<< "Cannot open file: " << filename << endl;
        return 1;
    }
    
    list< list<Packets> > poems;
    
    string line;
    while(getline(fin, line)) {
        string clean="";
        for(int i=0; i<(int)line.length();i++) {
            if(line[i]=='0' || line[i]=='1') {
                clean += line[i];
            }
        }

        if(clean=="") continue;
        
        Packets p(clean);
    
        bool foundPoem=false;
        list< list<Packets> >:: iterator poemIt;
        for(poemIt=poems.begin(); poemIt!=poems.end(); poemIt++) {
            if(poemIt->front().getSourceAddress()==p.getSourceAddress() && poemIt->front().getDestinationAddress()==p.getDestinationAddress()) {
                foundPoem=true;
                break;
            }
        }
        
        if(!foundPoem) {
            list<Packets> newPoem;
            newPoem.push_back(p);
            poems.push_back(newPoem);
            continue;
        }
        
        bool duplicate=false;
        list<Packets>:: iterator pk;
        for(pk=poemIt->begin(); pk!=poemIt->end();pk++) {
            if(pk->getSequenceNumber()==p.getSequenceNumber()) {
                duplicate=true;
                if(pk->politiciansAreCorrupt() && !p.politiciansAreCorrupt()) {
                    *pk=p;
                }
                break;
            }
        }
        if(!duplicate){
            poemIt->push_back(p);
        }
    }
    fin.close();
    
    bool firstPoem=true;
    list< list<Packets> >:: iterator poemIt;
    for(poemIt=poems.begin(); poemIt!=poems.end(); poemIt++) {
        int total=-1;
        int maxSeq=-1;
        bool hasGood=false;
        Packets good;
        list<Packets>:: iterator pk;
        for(pk=poemIt->begin(); pk!=poemIt->end(); pk++) {
            int seq=pk->getSequenceNumber();
            if(seq>maxSeq) maxSeq=seq;
            if(pk->politiciansAreCorrupt()) continue;
            if(!hasGood) {
                good=*pk;
                hasGood=true;
            }
            if(seq<0) total = -seq;
        }
        if(!hasGood) continue;
        if(total==-1) total=maxSeq+1;
        if(!firstPoem) {
            cout << endl;
            for(int d =0; d<80; d++) {
                cout<<"-";
            }
            cout << endl << endl;
        }
        firstPoem=false;
        
        for(int seq=0; seq<total;seq++) {
            bool found=false;
            for(pk=poemIt->begin(); pk!=poemIt->end(); pk++) {
                if(pk->getSequenceNumber()==seq) {
                    found=true;
                    break;
                }
            }
            if(!found) {
                if(seq==0) cout<< "[title missing]" << endl;
                else cout << "[line missing]" << endl;
            }
            else if(pk->politiciansAreCorrupt()) {
                if(seq==0) cout<< "[title corrupted]" << endl;
                else cout << "[line corrupted]" << endl;
            }
            else {
                cout<<pk->getData()<<endl;
            }
            
            if(seq==0){
                cout<<good.getSourceIP() << "/" << good.getDestIP() << endl;
            }
        }
    }
    
    return 0;
}