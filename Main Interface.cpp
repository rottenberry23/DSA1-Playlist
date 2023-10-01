#include <iostream>
#include <conio.h>
					
					//void Team::addNewPlayer(Players new_player) {
					//
					//    // add new_player to the end of the array
					//    int newSize = sizeof(players)/sizeof(players[0]);			// use this if i dont know the current number of songs
					//    Players newArray[newSize+1];
					//    
					//    for (int i=0; i < newSize; i++) {
					//        newArray[i] = players[i];
					//    }
					//
					//    newArray[newSize] = new_player;
					//    players = newArray;
					//} 							TIP : make my own vectors 

using namespace std;

class Song
{
	private:
		string name, artist;
		float duration;
	public:			//no need for constructor currently
		void set_name(string name)
		{
			this->name = name;
		}
		void set_artist(string artist)
		{
			this->artist = artist;
		}
		void set_duration(float duration)
		{
			this->duration = duration;
		}
		string get_name()
		{
			return name;
		}
		string get_artist()
		{
			return artist;
		}
		int get_duration()
		{
			return duration;
		}
		void set_info()
		{
			string name, artist;
			float duration;
			system("cls");
			cout<<"Enter Name of Song: ";
			cin>>name;
			cout<<"Enter Name of the Artist: ";
			cin>>artist;
			cout<<"Enter the Duration of the Song: ";
			cin>>duration;
			set_name(name);
			set_artist(artist);
			set_duration(duration);
			cout<<endl<<"Information for Song "<<name<< "has been set! "
				<<"\nPress any key to continue...";
			getch();			
		}	
		void get_allinfo()
		{
			string name, artist;
			float duration;
			cout<<"Name: "<<name
				<<"\tArtist: "<<artist
				<<"\tDuration: "<<duration
				<<endl;
		}			
};

class Playlist
{
	private:
		string name;
		int size;
		Song* songs;
	public:
		Playlist()
		{
			songs = NULL;
			size=0;
		}
		void set_name(string name)
		{
			this->name = name;
		}
		string get_name()
		{
			return name;
		}		
		void displayAll()
		{
			system("cls");
			if(size=0)
			{
				cout<<"Playlist"<<name<<" is Empty...";
			}
			else
			{
				cout<<"ALL Songs in the playlist : "<<endl<<endl;
				for(int x=0;x<size-1;x++)
				{
					songs->get_allinfo();
				}
			}
		}
//		void add_song()
//		{
//			song //start here
//			
//		}
};

int main()
{
	Playlist p1;
	
	
	return 0;
}
