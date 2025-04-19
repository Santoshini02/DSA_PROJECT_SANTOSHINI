#include <iostream>
#include <stack>
#include <string>
using namespace std;
class TextEditor {
private:
    string text;
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void type(const string& newText) {
        undoStack.push(text);        
        text += newText;              
        while (!redoStack.empty())    
            redoStack.pop();
    }

    void undo() {
        if (!undoStack.empty()) {
            redoStack.push(text);    
            text = undoStack.top(); 
            undoStack.pop();
        } else {
            cout << " Nothing to undo\n";
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            undoStack.push(text);     
            text = redoStack.top();  
            redoStack.pop();
        } else {
            cout << " Nothing to redo\n";
        }
    }

    void showText() const {
        cout << "\n Current Text: \"" << text << "\"\n";
    }
};

int main() {
    TextEditor editor;
    int choice;
    string input;

    while (true) {
        cout << "\n Text Editor \n";
        cout << "1. Type Text\n2. Undo\n3. Redo\n4. Show Text\n5. Exit\n";
        cout << "Choose an option: ";
        
        if (!(cin >> choice)) {
            cin.clear(); 
            cin.ignore();
            cout << "Invalid input.\n";
            continue;
        }

        cin.ignore();  

        switch (choice) {
            case 1:
                cout << "Enter text to add: ";
                getline(cin, input);
                editor.type(input);
                break;
            case 2:
                editor.undo();
                break;
            case 3:
                editor.redo();
                break;
            case 4:
                editor.showText();
                break;
            case 5:
                cout << "Exiting editor. \n";
                return 0;
            default:
                cout << " Invalid option.  Please choose from 1-5.\n";
        }
    }
}
