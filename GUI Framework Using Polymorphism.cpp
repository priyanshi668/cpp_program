#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class for GUI components
class GUIComponent {
public:
    virtual void draw() const = 0;  // Pure virtual function for drawing the component
    virtual void handleEvent(const string& event) = 0; // Pure virtual function for event handling
    virtual ~GUIComponent() = default;  // Virtual destructor for proper cleanup
};

// Derived class for Button
class Button : public GUIComponent {
private:
    string label;
public:
    Button(const string& label) : label(label) {}

    void draw() const override {
        cout << "Drawing Button: " << label << endl;
    }

    void handleEvent(const string& event) override {
        if (event == "click") {
            cout << "Button " << label << " clicked!" << endl;
        } else {
            cout << "Button " << label << " received event: " << event << endl;
        }
    }
};

// Derived class for Textbox
class Textbox : public GUIComponent {
private:
    string text;
public:
    Textbox(const string& initialText = "") : text(initialText) {}

    void draw() const override {
        cout << "Drawing Textbox with text: " << text << endl;
    }

    void handleEvent(const string& event) override {
        if (event == "focus") {
            cout << "Textbox is focused!" << endl;
        } else if (event == "type") {
            cout << "Typing in Textbox..." << endl;
        } else {
            cout << "Textbox received event: " << event << endl;
        }
    }

    void setText(const string& newText) {
        text = newText;
    }

    string getText() const {
        return text;
    }
};

// GUI Manager to manage all components
class GUIManager {
private:
    vector<GUIComponent*> components;

public:
    void addComponent(GUIComponent* component) {
        components.push_back(component);
    }

    void render() const {
        for (const auto& component : components) {
            component->draw();
        }
    }

    void handleEvent(const string& event) const {
        for (const auto& component : components) {
            component->handleEvent(event);
        }
    }

    ~GUIManager() {
        // Clean up dynamically allocated memory
        for (auto& component : components) {
            delete component;
        }
    }
};

// Main function to demonstrate the GUI framework
int main() {
    GUIManager guiManager;

    // Create GUI components
    Button* button1 = new Button("Submit");
    Textbox* textbox1 = new Textbox("Enter your name");

    // Add components to GUI Manager
    guiManager.addComponent(button1);
    guiManager.addComponent(textbox1);

    // Render the GUI
    cout << "Rendering the GUI:\n";
    guiManager.render();

    // Handle events
    cout << "\nHandling events:\n";
    guiManager.handleEvent("click");
    guiManager.handleEvent("focus");
    guiManager.handleEvent("type");

    return 0;
}
