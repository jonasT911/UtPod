/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    cout << "Remaining memory = " << t.getRemainingMemory() << endl;
    Song s1("Beatles", "Hey Jude", 4);
    int result = t.addSong(s1);
    cout << "add result = " << result << endl;
    t.showSongList();
    cout<<"Remaining Memory = "<<t.getRemainingMemory()<<endl<<endl;

    Song D4C("AC/DC","Filthy Acts For a Reasonable Price",16);
    Song SOS("ABBA","SOS",12);

    Song largeSong("Notorious B.I.G","Big Poppa",508);
    Song TooBig("Notorious B.I.G","Really Big Poppa",513);

    Song Bite("Queen","Another one Bites the Dust",8);
    Song the("Queen","Another one Bites the Dust",9);
    Song Dust("Queen","Another one Bites the Dust",30);

    Song kQ("Queen","Killer Queen",9);

    result = t.addSong(D4C);
    cout << "Adding AC/DC result = " << result << endl;
    result = t.addSong(SOS);
    cout << "Adding SOS result = " << result << endl;
    t.showSongList();

    cout<<"Remaining Memory = "<<t.getRemainingMemory()<<endl;
    result = t.addSong(largeSong);
    cout << "Adding song that is 508mb result = " << result << endl;


    cout<<endl<<"Adding More Songs"<<endl;
    result = t.addSong(Bite);
    result = t.addSong(the);
    result = t.addSong(Dust);
    result = t.addSong(kQ);
    result = t.addSong(D4C);

    t.showSongList();
    cout << "Remaining memory = " << t.getRemainingMemory() << endl;

    cout<<endl<<"sorting the list"<<endl;
    t.sortSongList();
    t.showSongList();
    cout<<endl<<"Shuffle the list"<<endl;
    t.shuffle();
    t.showSongList();
    cout<<endl<<"sorting the list"<<endl;
    t.sortSongList();
    t.showSongList();
    cout<<endl<<"Shuffle the list"<<endl;
    t.shuffle();
    t.showSongList();

    result = t.removeSong(kQ);
    cout <<endl<< "Removing Killer Queen result = " << result << endl;

    result = t.removeSong(D4C);
    cout << "Removing One AC/DC result = " << result << endl;
    result = t.removeSong(kQ);
    cout <<"Removing Killer Queen  when it is not in the list result= " << result << endl;

    cout<<endl<<"printing list"<<endl;
    t.showSongList();
    

    cout<<endl<<"Clearing Memory"<<endl;
    t.clearMemory();
    cout<<"printing list"<<endl;
    t.showSongList();

    cout<<"Adding 513mb song"<<endl;
    result = t.addSong(TooBig);
    cout << "Adding 513mb result = " << result << endl;

    cout<<"Adding 508mb song"<<endl;
    result = t.addSong(largeSong);
    cout << "Adding 508mb result = " << result << endl;
    cout<<"printing list"<<endl;
    t.showSongList();
    t.clearMemory();

    //Small UtPod Test
    cout<<endl<<endl<<"Testing a UtPod with a memory of 12"<<endl;
    UtPod Tiny(12);
    cout << "Adding 4 songs of size 4"<< endl<<endl;

    result = Tiny.addSong(s1);
    cout << "add result = " << result << endl;
    Tiny.showSongList();
    cout << "Remaining memory = " << Tiny.getRemainingMemory() << endl;

    result = Tiny.addSong(s1);
    cout << "add result = " << result << endl;
    Tiny.showSongList();
    cout << "Remaining memory = " << Tiny.getRemainingMemory() << endl;

    result = Tiny.addSong(s1);
    cout << "add result = " << result << endl;
    Tiny.showSongList();
    cout << "Remaining memory = " << Tiny.getRemainingMemory() << endl;

    result = Tiny.addSong(s1);//adding a song to a full UtPod
    cout << "add result = " << result << endl;
    Tiny.showSongList();
    cout << "Remaining memory = " << Tiny.getRemainingMemory() << endl;
    Tiny.clearMemory();

    //Invalid size UtPod test
    cout<<endl<<"Testing creation of UtPod of size -12 and 1000 respectively"<<endl<<endl;
    UtPod neg(-12);
    cout << "Total memory of UtPod (-12) = " << neg.getTotalMemory() << endl;

    UtPod Big(1000);
    cout << "Total memory of UtPod (1000) = " << Big.getTotalMemory() << endl;
}
