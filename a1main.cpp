/*
PlayList Methods
 Default constructor: O(1) There is no loop and recurrsion, so the constuctor will execute in a constant amount of time.
 Destructor: O(n) It happens until n elements in playlist 
 Copy constructor: O(n) It happens until n elements in playlist 
 Overloaded assignment operator: O(n) The number of node in pl
 Insert: O(n) traverse all n node when insert end of playlist
 Remove: O(n) traverse all n node when remove end of playlist
 Get: O(n) traverse all n node when insert end of playlist
 Swap: O(n) when both pos1 and pos2 are near the end of the list
 Size: O(1) There is no loop and recurrsion
Main Function Commands
 Enter a song: O(n) where n is the number of songs in the playlist. When the song is inserted at the end of the playlist, requiring traversal of all n nodes.
 Remove a song: O(n) where n is the number of songs in the playlist. When the song is removed at the end of the playlist, requiring traversal of all n nodes.
 Swap two songs: O(n) where n is the number of songs in the playlist. Getting songs at pos1 and pos2 take O(n) time.
 Print all the songs: O(n) where n is the number of songs in the playlist. Print all songs in the playlist.
*/
#include <iostream>
#include <string>
#include "PlayList.h"

using namespace std;
using std::string;

void printMenu(){
    cout << "Menu:" << endl;
    cout << "1 - Enter a song in the play list at a given position" << endl;
    cout << "2 - Remove a song from the play list at a given position" << endl;
    cout << "3 - Swap two songs in the play list" << endl;
    cout << "4 - Print all the songs in the play list" << endl;
    cout << "5 - Quit" << endl;
}

int main(){
    int choice;
    string nm;
    string art;
    int len;
    int pos;
    int pos1;
    int pos2;
    PlayList head = PlayList();
    printMenu();
    while(true){
        cout << " " << endl;
        cout << "Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): ";
        cin >> choice;
        if (choice == 5){
            cout << "You have chosen to quit the program." << endl;
            break;
        }
        if (choice == 1){
            cout << "Song name: ";
            cin.ignore();
            getline(cin, nm);
            cout << "Artist: ";
            getline(cin, art);
            cout << "Length: ";
            cin >> len;
            while(true){
                if(head.size()==0){
                    cout << "position (1): ";
                }else{
                    cout << "position (1 to " << head.size()+1 << "): ";
                }
                cin >> pos;
                if(pos > 0 && pos <= head.size()+1){
                    cout << "You entered " << nm << " at position " << pos << " in the play list" << endl;
                    Song sng = Song(nm,art,len);
                    head.insert(sng,pos-1);
                    break;
                }else{
                    cout << "Out of range: Please re-enter the postion." << endl;
                }
            }
        }
        else if (choice == 2){
            while(true){
                cout << "Position (1 to " << head.size() << "): ";
                cin >> pos;
                if(pos > 0 && pos <= head.size()){
                    Song sng = head.remove(pos-1);
                    cout << "Your removed " << sng.getName() << " from the play list" << endl;
                    break;
                }else{
                    cout << "Out of range: Please re-enter the postion." << endl;
                }
            }
        }
        else if(choice == 3){
            while(true){
                cout << "Swap song at position (1 to " << head.size() << "): ";
                cin >> pos1;
                cout << "with the song at position (1 to " << head.size() << "): ";
                cin >> pos2;
                if(pos1 == pos2){
                    cout << "Re-enter two different positions" << endl;
                }
                else if(pos1 > 0 && pos1 <= head.size() && pos2 > 0 && pos2 <= head.size()){
                    head.swap(pos1-1,pos2-1);
                    Song sng1 = head.get(pos1-1);
                    Song sng2 = head.get(pos2-1);
            
                    cout << "You swapped the songs at positions " << pos1 << " and " << pos2 <<endl;
                    break;
                } else{
                    cout << "Out of range: Please re-enter the postion." << endl;
                }
            }
        }
        else if(choice == 4){
            for(int i =0; i <= head.size()-1; i++){
                cout << i+1 << " "<< head.get(i).getName() << " (" << head.get(i).getArtist() <<") "<< head.get(i).getLength() << "s "<< endl;
            }
            cout << "There are " << head.size() << " songs in the play list." <<endl;
        }
        else{
            cout << "Please enter number between 1 to 5" << endl;
        }
        
    }
}
