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
			cout<<endl
				<<"Information for Song \" "<<name<<" \" has been set! "
				<<"\nPress any key to continue...";
			getch();			
		}	
		void get_allinfo()
		{
			string name, artist;
			float duration;
			cout<<"Name: "<<get_name()
				<<"\tArtist: "<<get_artist()
				<<"\tDuration: "<<get_duration()
				<<endl;
		}			
};

class Playlist
{
	private:
		string name;
		int size;
		Song* songs ;
	public:
		Playlist()
		{
			songs = nullptr;
			size = 0;
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
			if(size==0)
			{
				cout<<"Playlist"<<name<<" is Empty...";
			}
			else
			{
				cout<<"ALL Songs in the playlist : "<<endl<<endl;
				for(int x=0;x<size;x++)
				{
					songs[x].get_allinfo();
				}
			}
		}
		void add_song()
		{
     			 // allocate size + 1 songs 
			Song* temp = new Song[size + 1];
			
			      // copy songs over to the new array
			for(int x=0;x<size;x++)
			temp[x] = songs[x];
			
			      // set the information for the last song added
			temp[size].set_info();
			
			      // adjust the size to the new amount
			++size;
			
			     // delete the old array and set songs to the new array
			delete [] songs;
			songs = temp;
		}
		void access_song()
		{
			int choice;
			system("cls");
			cout<<"Do you wish to access a Song by "<<"\n (1) Name or\n (2) Serial Number ? "<<endl;
			cout<<"Press 0 to go back...";
			
				cin>>choice;
				switch(choice)
				{
					case 0:
							return;
						break;
					case 1:
						//Search by Name
						break;
					case 2:
						//search by Serial Number
						break;
					default:
						cout<<"You selected "<<choice<<".\nNo such option exists... \nPress any key to try again";
						getch();
				}
			
		}
		void update_song()
		{
			//update info about song
		}
		void delete_song()
		{
			int choice;
			system("cls");
			cout<<"Do you wish to Delete a Song by "<<"\n (1) Name or\n (2) Serial Number ? "<<endl;
			cout<<"Press 0 to go back...";
			
				cin>>choice;
				switch(choice)
				{
					case 0:
							return;
						break;
					case 1:
						//delete by Name
						break;
					case 2:
						//delete by Serial Number
						break;
					default:
						cout<<"You selected "<<choice<<".\nNo such option exists... \nPress any key to try again";
						getch();
				}
		}
		void get_size()
		{
			//get total number of songs in the playlist
		}
		bool IsEmpty()
		{
			//returns true if playlist is empty
			if(size==0)
				return true;
			else
				return false;
//			if(p1.IsEmpty())
//			{
//				cout<<"empty";
//			}
//			else
//				cout<<"filled";
		}
		
};

int main()
{
	Playlist p1;
	p1.displayAll();

	
	
	return 0;
}

// add_songs(); works alright now. Took some time but worth it!

