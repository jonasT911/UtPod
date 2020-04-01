#include "Song.h"
using namespace std;

    Song::Song(){
        name="";
        artist="";
        size=MAX_SIZE;
    }

    Song::Song(string _artist, string _name, int _size){
        name=_name;
        artist=_artist;
        size=_size;
    }

    string Song::getName() const{

        return name;
    }
    string Song::getArtist() const{
        return artist;
    }
    int Song::getSize() const {
        return size;
    }

    void Song::setName(string newName){
        name=newName;
    }
    void Song::setArtist(string newArtist){
        artist=newArtist;
    }

    void Song::setSize(int newSize){
        size=newSize;
    }

    bool Song::operator >(Song const &rightSide){
        if(artist==rightSide.getArtist()){
            if(name==rightSide.getName()) {
                return (size>rightSide.getSize());
            }else{
                return (name>rightSide.getName());
            }
        }else{
            return (artist>rightSide.getArtist());
        }
    }

    bool Song::operator <(Song const &rightSide){
        if(artist==rightSide.getArtist()){
            if(name==rightSide.getName()) {
                return (size<rightSide.getSize());
             }else{
                return (name<rightSide.getName());
            }
        }else{
            return (artist<rightSide.getArtist());
        }
    }

    bool Song::operator ==(Song const &rightSide) {
     if (artist == rightSide.getArtist()) {
        if (name == rightSide.getName()) {
            if (size == rightSide.getSize()){
                return true;
            }
        }
     }
     return false;
    }

Song::~Song(){
        cout<<"destructor";
    }

