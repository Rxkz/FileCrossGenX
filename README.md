FileCrossGenX
A C++-based simple messaging system that allows users to send messages to a text file and monitor those messages in real-time using two terminal instances. This project demonstrates a basic client-server-like system where one instance writes messages to a file, and another reads them in real-time. It leverages file handling, live monitoring, and thread-safe operations to provide a seamless messaging experience.

Features
Send Messages: Write messages to a text file with auto-incremented IDs and timestamps.
Live Monitoring: Monitor the text file for new messages in real-time with automatic screen refresh.
Thread-Safe Operations: Uses mutex to ensure safe file access across multiple instances.
Cross-Platform: Supports both Windows and Linux with appropriate screen-clearing functionality.
Prerequisites
To run this project, you need the following:

A C++ compiler (e.g., g++)
A terminal or command-line interface (two instances for full functionality)
Basic knowledge of compiling and running C++ programs
Installation
Clone the Repository:
bash

Collapse

Wrap

Copy
git clone https://github.com/Rxkz/FileCrossGenX.git
cd FileCrossGenX
Compile the Code: Use g++ to compile the FileCrossGenX.cpp file. Ensure all header files (File_Z.h and Example_Class_Structure.h) are in the same directory.
bash

Collapse

Wrap

Copy
g++ FileCrossGenX.cpp -o messaging
Usage
This application runs in two modes: Sender and Viewer. To demonstrate the live monitoring feature, you need to run two instances of the program in separate terminals.

Step 1: Start the Viewer (Live Monitoring)
Open a terminal and navigate to the project directory.

Run the compiled program:

bash

Collapse

Wrap

Copy
./messaging
Choose option 2 to start the live monitoring mode.

The viewer will refresh every 3 seconds when new messages are detected.
Press Enter to exit the monitoring mode and return to the main menu.
Example (Viewer Mode):


The viewer starts monitoring but shows no messages initially since the file is empty.
Step 2: Start the Sender (Send Messages)
Open a second terminal and navigate to the project directory.

Run the compiled program:

bash

Collapse

Wrap

Copy
./messaging
Choose option 1 to enter the message sender mode.

Type your messages and press Enter to send them.
Type exit to quit the sender mode.
Example (Sender Mode):
![Screenshot 2025-04-06 175026](https://github.com/user-attachments/assets/f5c24c88-5712-4272-8f61-a3ea41238fd4)
![Screenshot 2025-04-06 175059](https://github.com/user-attachments/assets/13de0fdb-948c-48b0-a39d-bfb6c391cfc7)


The sender types "test" and "test 2", which are saved to messages.txt.
Step 3: Observe Live Updates
As you send messages in the second terminal (Sender), the first terminal (Viewer) will automatically detect and display the new messages.

The viewer shows the message ID, text, and timestamp (in HH:MM:SS format).

Example (Live Update):
![Screenshot 2025-04-06 175121](https://github.com/user-attachments/assets/a0b715a6-16af-4c8d-aa10-155ead88e539)


The viewer now shows the messages "test" and "test 2" with their IDs and timestamps.
How It Works
Message Storage: Messages are stored in messages.txt in the format id|text|timestamp.
Sender Mode: Creates a Message object with an auto-incremented ID, user-entered text, and a timestamp, then appends it to the file.
Viewer Mode: Uses FileManager to monitor the file for changes, refreshing the display every 3 seconds when new messages are detected.
Thread Safety: A mutex ensures safe file access when multiple instances read/write to messages.txt.
This setup demonstrates a basic client-server-like system where one instance writes to the file, and another reads in real-time.

File Structure
FileCrossGenX.cpp: The main program that provides the user interface and logic for sending and viewing messages.
File_Z.h: Contains the FileManager class for file operations and live monitoring, and stbase for timestamp utilities.
Example_Class_Structure.h: Defines the Message class for message formatting and parsing.
Notes
Ensure both terminals are running in the same directory to access the same messages.txt file.
The refresh interval in the viewer mode is set to 3 seconds by default but can be adjusted in File_Z.h.
The application uses platform-specific commands to clear the screen (cls for Windows, clear for Linux).
Troubleshooting
File Access Issues: Ensure you have read/write permissions for the directory where messages.txt is created.
No Updates in Viewer: Verify that both instances are using the same messages.txt file and that the sender is writing correctly.
Timestamp Format: The timestamp in the viewer is truncated to show only the time (HH:MM:SS) for readability.
Contributing
Contributions are welcome! Feel free to open issues or submit pull requests to improve the functionality or add new features.

License
This project is licensed under the Rx100 License. See the  file for details lol 
