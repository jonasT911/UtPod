//DOCUMENT HERE


#include "Song.h"
#include "UtPod.h"

using namespace std;


    UtPod::UtPod(){
cout<<" Start,";//debug
        SongNode songList;
        songs= nullptr;
        memSize=MAX_MEMORY;

    }

    UtPod::UtPod(int size){

       songs->next=nullptr;

        if(size>MAX_MEMORY||size<=0){
            memSize=MAX_MEMORY;
        }else{
            memSize=size;
        }
    }

    int UtPod::addSong(Song const &s){

        SongNode *temp=new SongNode;
        temp->s=s;
        temp->next=songs;

       int remainingMemory=getRemainingMemory();
       if(remainingMemory>s.getSize()){
           //pushing song to the list
cout<<"adding Song,"<<endl;//debug
        songs=temp;
           return SUCCESS;
       }else{
           return NO_MEMORY;
       }
    }

    int UtPod::removeSong(Song const &s){

        cout<<"Removing SOng,";
        bool isMore=true;
        SongNode *iterate = songs;
        if(songs== nullptr){
            cout<<"Empty List";//debug
            isMore=false;//empty List
            return NOT_FOUND;
        }
        cout<<"List has Songs";//debug

        SongNode *trailer=songs;
        if (songs->s==s){
            cout<<"Head Found,";
            //list head is target

            songs=songs->next;//free Space?
            delete trailer;
            return 0;
        }

        while (isMore){
        if(iterate->s==s){
            cout<<"Song Found,";

            trailer->next=iterate->next;//free Space?
            delete iterate;
            return 0;
        }
            trailer=iterate;
            if(iterate->next) {
                iterate = iterate->next;
            }else{
                isMore=false;
            }
        }
        cout<<"Missing Song";
        return NOT_FOUND;
    }

    void UtPod::showSongList(){
        if(songs) {
            SongNode iterate = *songs;
            bool isMore = true;
            while (isMore) {
                cout << "name= " << iterate.s.getName() << " artist= " << iterate.s.getArtist() << " size= "
                     << iterate.s.getSize() << endl;

                if (iterate.next) {
                    iterate = *iterate.next;
                } else {
                    isMore = false;
                }

            }
        }

    }

    int UtPod::getRemainingMemory(){
        cout<<" get Remaining,";// debug
        int usedMemory=0;


        if(songs) {
            SongNode iterate = *songs;

            bool isMore=true;
            while (isMore) {
                usedMemory += iterate.s.getSize();

                if(iterate.next) {
                    iterate = *iterate.next;
                }else{
                    isMore=false;
                }
            }
            usedMemory += iterate.s.getSize();//for final song in list
            cout << " Remaining got, ";//debug
            return memSize - usedMemory;
        }else{
cout<<" empty ";//debug
            return memSize;
        }

    }

    UtPod::~UtPod(){
        cout<<"destructor";
    }
