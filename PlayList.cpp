// Name: Jisoo Im
// Date: Sep 20, 2024
#include "PlayList.h"

// PlayList method implementations go here

// Constructors and destructor
	// POST: head of list is set to nullptr
	PlayList::PlayList(){
        head = nullptr;
        playlistSize = 0;
    }

	// PARAM: pl - PlayList to be copied
	// POST: new PlayList is created that is a deep copy of pl
	PlayList::PlayList(const PlayList& pl){
        if (pl.head == nullptr){
            head = nullptr;
        }else{
            head = new PlayListNode(pl.head->song);
            PlayListNode* original = pl.head->next;
            PlayListNode* copy = head;

            while (original != nullptr){
                copy->next = new PlayListNode(original->song);
                original = original->next;
                copy = copy->next;
            }
        }
    }
	
	// POST: dynamic memory associated with object is deallocated
	PlayList::~PlayList(){
        deletePlayList();
    }

    void PlayList::deletePlayList(){
        PlayListNode* temp = head;
        while(head != nullptr){
            head = head->next;
            delete temp;
            temp = head;
        }
    }

	// PARAM: pl - PlayList to be copied
	// POST: dynamic memory of calling object deallocated (except
	//       under self-assignment), calling object is set to a
	//       a deep copy of pl
    PlayList& PlayList::operator=(const PlayList & pl){
        if (&pl != this) {
            deletePlayList();
            //PlayList(pl);
        }
        return *this;
    }

	// Mutators
	// PRE: 0 <= i <= length of list
	// PARAM: pos - 0-based insertion position
	//        sng - Song to be insertedpos
	void PlayList::insert(Song sng, unsigned int pos){
        PlayListNode* curr = head;
        PlayListNode* newNode = new PlayListNode(sng);
        unsigned int i = 0;
        if(pos == 0){
            newNode->next = head;
            head = newNode;
            playlistSize ++;
            return;
        }
        while(curr != nullptr && i <pos-1){
            curr = curr ->next;
            i++;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        playlistSize ++;

    }

	// PRE: 0 <= pos <= length of list-1
	// PARAM: pos - 0-based position of element to be removed and returned
	// POST: Song at position pos is removed and returne
	Song PlayList::remove(unsigned int pos){
        PlayListNode* thisNode = head;
        PlayListNode* temp = head;
        if(head == nullptr){
            exit(0);
        } else if(pos == 0){
            Song removeSong = temp->song;
            head = head->next;
            playlistSize --;
            delete temp;
            return removeSong;
        }
        else{
            for(unsigned int i = 0; i < pos-1; i++){
                thisNode = thisNode->next;
            }
            temp = thisNode->next;
            Song thisSong = temp->song;
            thisNode->next = temp->next;
            playlistSize --;
            delete temp;
            return thisSong;
        }

    }

	// PRE: 0 <= pos1, pos2 <= length of list-1
	// PARAM: pos1, pos2 - 0-based positions of elements to be swapped
	// POST: Songs at positions pos1 and pos2 are swapped
	void PlayList::swap(unsigned int pos1, unsigned int pos2){
        PlayListNode* temp1 = head; 
        PlayListNode* temp2 = head;
        PlayListNode* newNode1 = nullptr;
        PlayListNode* newNode2 = nullptr;

        if (head == nullptr){
            return;
        }
        else{
            
            // find out pos1 list
            for (unsigned int i = 0; i < pos1; i++){
                newNode1 = temp1;
                temp1 = temp1->next;
            }

            // find out pos2 list
            for (unsigned int i = 0; i < pos2; i++){
                newNode2 = temp2;
                temp2 = temp2->next;
            }

            // link pos1 list to temp2
            if(newNode1 != nullptr){
                newNode1->next = temp2;
            }else{
                head = temp2;
            }

            // link pos2 list to temp1
            if(newNode2 != nullptr){
                newNode2->next = temp1;
            }else{
                head = temp1;
            }

            // swap pos1 and pos2
            PlayListNode* temp = temp1-> next;
            temp1->next = temp2->next;
            temp2->next = temp;
            
        }

    }

	// Accessor
	// PRE: 0 <= pos <= length of list-1
	// PARAM: pos - 0-based position of element to be removed and returned
	// POST: returns the Song at position pos
	Song PlayList::get(unsigned int pos) const{
        int i = 0;
        PlayListNode* temp = head;
        if (head == nullptr){
            exit(0);
        } else if(pos == 0){
            return temp->song;
        }else{
            while(temp != nullptr && i <pos){
                temp = temp ->next;
                i++;
            }
            return temp->song;
        }
    } // 0- based postition

	// POST: returns the number of songs in the PlayList
	unsigned int PlayList::size() const{
        return playlistSize;
    }

