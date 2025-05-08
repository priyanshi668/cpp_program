#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Packet {
    int id;
    string data;
    Packet(int i, const string& d) : id(i), data(d) {}
};

class Network {
private:
    queue<Packet> transmissionQueue;
    int packetCounter;

public:
    Network() : packetCounter(0) {
        srand(time(0)); // Seed for randomness
    }

    // Simulate sending a packet
    void sendPacket(const string& data) {
        packetCounter++;
        Packet p(packetCounter, data);

        // Simulate 10% chance of packet loss
        if (rand() % 10 == 0) {
            cout << "[Packet " << p.id << " LOST during transmission]\n";
            return;
        }

        // Simulate delay
        if (rand() % 5 == 0) {
            cout << "[Packet " << p.id << " DELAYED in transmission]\n";
            transmissionQueue.push(p); // Delayed, but will be received later
            return;
        }

        transmissionQueue.push(p);
        cout << "[Packet " << p.id << " SENT]\n";
    }

    // Simulate receiving a packet
    void receivePacket() {
        if (transmissionQueue.empty()) {
            cout << "No packets to receive.\n";
            return;
        }

        Packet p = transmissionQueue.front();
        transmissionQueue.pop();

        cout << "[Packet " << p.id << " RECEIVED] Data: " << p.data << "\n";
    }

    // Check if any packets are in the queue
    bool hasPendingPackets() const {
        return !transmissionQueue.empty();
    }
};

// Example usage
int main() {
    Network net;

    net.sendPacket("Hello, World!");
    net.sendPacket("Packet 2");
    net.sendPacket("Packet 3");

    cout << "\nReceiving Packets:\n";
    while (net.hasPendingPackets()) {
        net.receivePacket();
    }

    return 0;
}
