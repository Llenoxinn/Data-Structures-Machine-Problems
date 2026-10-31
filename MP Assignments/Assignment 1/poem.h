#include <string>

using namespace std;

class Packets {
    private:
        unsigned int sourceAddress;
        unsigned int destinationAddress;
        string sourceIP;
        string destinationIP;
        int sequenceNumber;
        int checkSum;
        int length;
        string data;
        string padding;
        bool corrupted;
    public:
        Packets();
        Packets(string line);
        string getSourceIP();
        string getDestIP();
        unsigned int getSourceAddress();
        unsigned int getDestinationAddress();
        int getSequenceNumber();
        int getCheckSum();
        int getLength();
        string getData();
        string getPadding();
        bool politiciansAreCorrupt();
};