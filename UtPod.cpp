//DOCUMENT HERE


#include "Song.h"
#include "UtPod.h"
#include <ctime>

using namespace std;


    UtPod::UtPod(){
        SongNode songList;
        songs= nullptr;
        memSize=MAX_MEMORY;

        unsigned int currentTime=(unsigned) time(0);
        srand(currentTime);

    }

    UtPod::UtPod(int size){

        SongNode songList;
        songs=nullptr;
        unsigned int currentTime=(unsigned) time(0);
        srand(currentTime);

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
       if(remainingMemory>=s.getSize()){
           //pushing song to the list

        songs=temp;
           return SUCCESS;
       }else{
           return NO_MEMORY;
       }
    }

    int UtPod::removeSong(Song const &s){


        bool isMore=true;
        SongNode *iterate = songs;
        if(songs== nullptr){

            isMore=false;//empty List
            return NOT_FOUND;
        }


        SongNode *trailer=songs;
        if (songs->s==s){
            //list head is target
cout<<"head";
            songs=songs->next;
            delete trailer;
            return 0;
        }

        while (isMore){
        if(iterate->s==s){


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

            return memSize - usedMemory;
        }else{
            return memSize;
        }

    }

    void UtPod::clearMemory(){
        SongNode *trailer=songs;
        SongNode *iterate=songs;
        bool isMore=true;
        if (!songs){
            isMore=false;
        }
         while (isMore) {

             delete trailer;
             trailer=iterate;
         if (iterate->next) {
             iterate = iterate->next;
         } else {
             isMore = false;
         }

     }
         songs=nullptr;
    }



    void UtPod::swapSongs(int &nodeOne,int &nodeTwo){
        SongNode *searchOne=songs;
        SongNode *searchTwo=songs;
       for(int i=0;i<nodeOne;i++){
           searchOne=searchOne->next;
       }
        for(int i=0;i<nodeTwo;i++){
            searchTwo=searchTwo->next;
        }
        Song temp=searchTwo->s;
        searchTwo->s=searchOne->s;
        searchOne->s=temp;

    }

    void UtPod::shuffle(){
        int listSize=numSongs();
        int song1=0;
        int song2=0;

        for(int i=0;i<listSize*5;i++) {
            song1 = rand() % listSize;
            song2 = rand() % listSize;
            swapSongs(song1, song2);
        }

    }

    void UtPod::sortSongList(){

        SongNode *lowestSong=songs;
        int lowestPosition=0;
        SongNode *iterate=songs;
        SongNode *swapSong=songs;
        int listSize=numSongs();
        for (int i=0;i<listSize;i++){
            iterate=swapSong;
            lowestSong=swapSong;
            lowestPosition=i;
            for(int j=i;j<listSize;j++){
                if(iterate->s<lowestSong->s){
                    lowestSong=iterate;
                    lowestPosition=j;
                }
                iterate=iterate->next;
            }

            swapSongs(i,lowestPosition);
            swapSong=swapSong->next;
        }
    }
    int UtPod::numSongs() {
        int count=0;

        if(songs){
            SongNode iterate=*songs;
            count++;
            while (iterate.next){
                count++;
                iterate=*iterate.next;
            }
        }

        return count;
    }

    UtPod::~UtPod()= default;