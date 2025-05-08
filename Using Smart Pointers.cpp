#include <iostream>
#include <memory>
using namespace std;

// A simple class to demonstrate object lifecycle
class Demo {
public:
    Demo(int value) : data(value) {
        cout << "Constructor called. Data = " << data << endl;
    }

    void show() {
        cout << "Data: " << data << endl;
    }

    ~Demo() {
        cout << "Destructor called for Data = " << data << endl;
    }

private:
    int data;
};

int main() {
    cout << "=== unique_ptr Demo ===" << endl;
    {
        unique_ptr<Demo> uptr = make_unique<Demo>(10);  // Automatic memory management
        uptr->show();
        // No need to delete uptr, memory is freed automatically
    }

    cout << "\n=== shared_ptr Demo ===" << endl;
    {
        shared_ptr<Demo> sp1 = make_shared<Demo>(20);
        cout << "sp1 use_count: " << sp1.use_count() << endl;

        {
            shared_ptr<Demo> sp2 = sp1;  // shared_ptr allows multiple owners
            cout << "sp2 created. sp1 use_count: " << sp1.use_count() << endl;
            sp2->show();
        } // sp2 goes out of scope here

        cout << "After sp2 is out of scope. sp1 use_count: " << sp1.use_count() << endl;
    } // sp1 goes out of scope here and object is deleted

    cout << "\n=== Done ===" << endl;
    return 0;
}
