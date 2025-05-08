#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Plugin Interface
class Plugin {
public:
    virtual void execute() = 0;  // Pure virtual method
    virtual ~Plugin() {
        cout << "Plugin base destructor called\n";
    }
};

// Concrete Plugin 1
class GreetingPlugin : public Plugin {
public:
    void execute() override {
        cout << "Hello from Greeting Plugin!" << endl;
    }

    ~GreetingPlugin() {
        cout << "GreetingPlugin destroyed\n";
    }
};

// Concrete Plugin 2
class MathPlugin : public Plugin {
public:
    void execute() override {
        cout << "Performing 5 + 3 = " << (5 + 3) << endl;
    }

    ~MathPlugin() {
        cout << "MathPlugin destroyed\n";
    }
};

// Plugin Manager
class PluginManager {
private:
    vector<unique_ptr<Plugin>> plugins;

public:
    void addPlugin(unique_ptr<Plugin> plugin) {
        plugins.push_back(move(plugin));
    }

    void runAll() {
        for (const auto& plugin : plugins) {
            plugin->execute();
        }
    }
};

// Main function to simulate loading and running plugins
int main() {
    PluginManager manager;

    manager.addPlugin(make_unique<GreetingPlugin>());
    manager.addPlugin(make_unique<MathPlugin>());

    cout << "\nExecuting all plugins:\n";
    manager.runAll();

    return 0;
}
