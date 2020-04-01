//
// Created by jonas on 3/30/2020.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <string>
#include <iostream>
using namespace std;

class Song {

private:
    string name;
    string artist;
    int size;
    static const int MAX_SIZE=512;

public:
    Song();
    Song(string name, string artist, int size);

    string getName() const;
    string getArtist() const;
    int getSize() const;

    void setName(string newName);
    void setArtist(string newArtist);
    void setSize(int newSize);

    bool operator >(Song const &rightSide);
    bool operator <(Song const &rightSide);
    bool operator ==(Song const &rightSide);

    ~Song();
};

#endif
