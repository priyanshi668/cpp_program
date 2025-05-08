#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Cache {
private:
    unordered_map<string, string> cacheData;

public:
    // Store data in the cache
    void store(const string& key, const string& value) {
        cacheData[key] = value;
        cout << "Stored [" << key << "] = " << value << endl;
    }

    // Retrieve data from the cache
    string retrieve(const string& key) const {
        auto it = cacheData.find(key);
        if (it != cacheData.end()) {
            return it->second;
        } else {
            return "Key not found in cache.";
        }
    }

    // Check if key exists
    bool contains(const string& key) const {
        return cacheData.find(key) != cacheData.end();
    }

    // Clear the cache
    void clear() {
        cacheData.clear();
        cout << "Cache cleared.\n";
    }
};

// Example usage
int main() {
    Cache cache;

    cache.store("username", "john_doe");
    cache.store("session_token", "abc123");

    cout << "\nRetrieving values:\n";
    cout << "username: " << cache.retrieve("username") << endl;
    cout << "session_token: " << cache.retrieve("session_token") << endl;
    cout << "email: " << cache.retrieve("email") << endl;

    if (cache.contains("username")) {
        cout << "\nKey 'username' exists in cache.\n";
    }

    cache.clear();
    return 0;
}
