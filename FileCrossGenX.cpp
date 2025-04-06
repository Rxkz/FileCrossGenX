#include "File_Z.h"
#include <iostream>
#include <string>
#include "Example_Class_Structure.h"


using namespace std;
using namespace TwoCli;

int main() {
    // Create file manager
    FileManager<Message> msgManager("messages.txt");

    cout << "SIMPLE MESSAGING SYSTEM" << endl;
    cout << "1. Send Messages" << endl;
    cout << "2. View Messages (Live)" << endl;
    cout << "Choose option: ";

    int choice;
    cin >> choice;
    cin.ignore(); // Clear input buffer

    if (choice == 1) {
        // Sender mode
        cout << "\nMESSAGE SENDER\n" << endl;
        cout << "Type your messages (type 'exit' to quit):" << endl;

        string input;
        while (true) {
            cout << "> ";
            getline(cin, input);

            if (input == "exit") {
                break;
            }

            // Create and send message
            Message msg;
            msg.id = msgManager.getNextId();
            msg.text = input;
            msg.timestamp = stbase::getCurrentTimeMark();

            msgManager.addRecord(msg);
        }
    }
    else if (choice == 2) {
        // Viewer mode with live monitoring
        auto displayMessages = [](const vector<Message>& messages) {
            for (const auto& msg : messages) {
                cout << "[" << msg.id << "] "
                    << msg.text
                    << " (sent at " << msg.timestamp.substr(11, 8) << ")"
                    << endl;
            }
            };

        auto hasChanges = [](const vector<Message>& current, const vector<Message>& previous) {
            return current.size() != previous.size();
            };

        msgManager.startMonitor(displayMessages, hasChanges);
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}