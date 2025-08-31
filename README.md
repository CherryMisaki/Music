🎵 Music Player (C++)

A simple C++ console-based music player that uses a doubly linked list to manage songs in a playlist, allowing you to add, delete, search, sort, play songs, and save/load the playlist from a file.

🚀 Features

➕ Add Songs to the playlist

❌ Delete Songs from the playlist

📃 Display Playlist

🔍 Search Songs by name

▶️ Play Songs and track the last played

⏮ Recently Played List

🔢 Count Total Songs

🗂 Sort Playlist Alphabetically

💾 Save Playlist to a file (playlist.txt)

📂 Load Playlist from a file

🛠 Implementation Details

Data Structure: Doubly Linked List for playlist management.

Persistence: File I/O (playlist.txt) for saving and loading songs.

Extra Tracking: Maintains both last played song and recently played list.

📌 How to Run

Clone this repo:

git clone https://github.com/CherryMisaki/Music.git
cd Music


Compile the program:

g++ music.cpp -o music


Run the program:

./music

📸 Menu Options
1. Add Song
2. Delete Song
3. Display Playlist
4. Total Songs
5. Search Song
6. Play Song
7. Recently Played List
8. Last Played
9. Sort Playlist
10. Save Playlist to File
11. Load Playlist from File
12. Exit

📖 Example Usage
Welcome to the Music Player!

Menu:
1. Add Song
2. Delete Song
...
Enter your choice: 1
Enter song name to add: Shape of You
Song 'Shape of You' added to the playlist.

⚡ Tech Stack

Language: C++

Concepts Used: Doubly Linked List, File I/O, OOP

👩‍💻 Author

CherryMisaki
