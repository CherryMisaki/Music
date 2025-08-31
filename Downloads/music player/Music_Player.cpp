#include <iostream>
#include <fstream>
#include <string>
#include <cstring> 
#include <cstdlib> 

using namespace std;

struct SongNode {
    string song;
    SongNode *next;
    SongNode *prev;
};

class MusicPlayer {
private:
    SongNode *head;
    SongNode *tail;
    SongNode *lastPlayed; 
    SongNode *recentlyPlayed; 

public:
    MusicPlayer() {
        head = nullptr;
        tail = nullptr;
        lastPlayed = nullptr;
        recentlyPlayed = nullptr;
    }

    // Function to add a new song to the playlist
    void addSong(const string& songName) {
        SongNode *newNode = new SongNode;
        newNode->song = songName;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        cout << "Song '" << songName << "' added to the playlist." << endl;
    }

    // Function to delete a song from the playlist
    void deleteSong(const string& songName) {
        if (head == nullptr) {
            cout << "Playlist is empty. Cannot delete." << endl;
            return;
        }

        SongNode *current = head;
        while (current != nullptr && current->song != songName) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Song '" << songName << "' not found in the playlist." << endl;
        } else {
            // Remove from the doubly linked list
            if (current == head && current == tail) {
                head = nullptr;
                tail = nullptr;
            } else if (current == head) {
                head = head->next;
                head->prev = nullptr;
            } else if (current == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            // Delete the node
            delete current;
            cout << "Song '" << songName << "' deleted from the playlist." << endl;
        }
    }

    // Function to display the entire playlist
    void displayPlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty." << endl;
            return;
        }

        SongNode *current = head;
        cout << "Playlist:" << endl;
        while (current != nullptr) {
            cout << current->song << endl;
            current = current->next;
        }
    }

    
    void countTotalSongs() {
        int count = 0;
        SongNode *current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        cout << "Total songs in the playlist: " << count << endl;
    }

    
    void searchSong(const string& songName) {
        SongNode *current = head;
        while (current != nullptr) {
            if (current->song == songName) {
                cout << "Song '" << songName << "' found in the playlist." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Song '" << songName << "' not found in the playlist." << endl;
    }

   
    void playSong(const string& songName) {
        SongNode *current = head;
        while (current != nullptr) {
            if (current->song == songName) {
                cout << "Playing song '" << songName << "'." << endl;
                addToRecentlyPlayed(songName);
                lastPlayed = current;
                return;
            }
            current = current->next;
        }
        cout << "Song '" << songName << "' not found in the playlist." << endl;
    }

    
    void displayRecentlyPlayed() {
        if (recentlyPlayed == nullptr) {
            cout << "No songs have been recently played." << endl;
            return;
        }

        SongNode *current = recentlyPlayed;
        cout << "Recently played songs:" << endl;
        while (current != nullptr) {
            cout << current->song << endl;
            current = current->next;
        }
    }

    
    void displayLastPlayed() {
        if (lastPlayed == nullptr) {
            cout << "No song has been last played yet." << endl;
        } else {
            cout << "Last played song: " << lastPlayed->song << endl;
        }
    }

    
    void sortPlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty. Nothing to sort." << endl;
            return;
        }

        
        SongNode *i, *j;
        string temp;
        for (i = head; i != nullptr; i = i->next) {
            for (j = i->next; j != nullptr; j = j->next) {
                if (i->song > j->song) {
                    temp = i->song;
                    i->song = j->song;
                    j->song = temp;
                }
            }
        }
        cout << "Playlist sorted alphabetically." << endl;
    }

   
    void saveToFile() {
        ofstream file("playlist.txt");
        if (!file.is_open()) {
            cout << "Error opening file for writing." << endl;
            return;
        }

        SongNode *current = head;
        while (current != nullptr) {
            file << current->song << endl;
            current = current->next;
        }
        file.close();
        cout << "Playlist saved to file 'playlist.txt'." << endl;
    }

   
    void loadFromFile() {
        ifstream file("playlist.txt");
        if (!file.is_open()) {
            cout << "Error opening file for reading. Starting with empty playlist." << endl;
            return;
        }

        string songName;
        while (getline(file, songName)) {
            addSong(songName);
        }
        file.close();
        cout << "Playlist loaded from file 'playlist.txt'." << endl;
    }

   
    ~MusicPlayer() {
        while (head != nullptr) {
            SongNode *temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        lastPlayed = nullptr;
        recentlyPlayed = nullptr;
    }

private:
    
    void addToRecentlyPlayed(const string& songName) {
        SongNode *newNode = new SongNode;
        newNode->song = songName;
        newNode->next = recentlyPlayed;
        newNode->prev = nullptr;

        if (recentlyPlayed != nullptr) {
            recentlyPlayed->prev = newNode;
        }
        recentlyPlayed = newNode;
    }
};

int main() {
    MusicPlayer player;
    int choice;
    string songName;

    cout << "Welcome to the Music Player!" << endl;

    do {
        cout << "\nMenu:\n1. Add Song\n2. Delete Song\n3. Display Playlist\n4. Total Songs\n5. Search Song\n";
        cout << "6. Play Song\n7. Recently Played List\n8. Last Played\n9. Sort Playlist\n10. Save Playlist to File\n11. Load Playlist from File\n12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song name to add: ";
                cin.ignore();
                getline(cin, songName);
                player.addSong(songName);
                break;
            case 2:
                cout << "Enter song name to delete: ";
                cin.ignore();
                getline(cin, songName);
                player.deleteSong(songName);
                break;
            case 3:
                player.displayPlaylist();
                break;
            case 4:
                player.countTotalSongs();
                break;
            case 5:
                cout << "Enter song name to search: ";
                cin.ignore();
                getline(cin, songName);
                player.searchSong(songName);
                break;
            case 6:
                cout << "Enter song name to play: ";
                cin.ignore();
                getline(cin, songName);
                player.playSong(songName);
                break;
            case 7:
                player.displayRecentlyPlayed();
                break;
            case 8:
                player.displayLastPlayed();
                break;
            case 9:
                player.sortPlaylist();
                break;
            case 10:
                player.saveToFile();
                break;
            case 11:
                player.loadFromFile();
                break;
            case 12:
                cout << "Exiting the Music Player. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 12." << endl;
        }
    } while (choice != 12);

    return 0;
}
