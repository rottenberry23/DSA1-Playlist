#include <iostream>
#include <conio.h>
#include <fstream>		//for filehandling for bonus task
using namespace std;

class Song
{
	private:
		string name, artist;
		float duration;
	public:			//no need for constructor currently
		void set_name(string name)
			{	this->name = name;	}
			
		void set_artist(string artist)
			{	this->artist = artist;	}
			
		void set_duration(float duration)
			{	this->duration = duration;	}
			
		string get_name()
			{	return name;	}
			
		string get_artist()
			{	return artist;	}
			
		int get_duration()
			{	return duration;	}
			
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
		
		void get_info(int n)
		{
			string name, artist;
			float duration;
			cout<<n+1
				<<". Name: "<<get_name()
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
		Playlist()		//constructor
		{
			songs = NULL;
			size = 0;
		}
		
		void set_name(string name)		//setter for name variable
			{	this->name = name;		}
			
		string get_name()				//getter of name variable
			{	return name;	}	
				
		void displayAll()			//displays all the songs in the playlist
		{
			system("cls");
			
			if(size==0)
				cout<<"Playlist"<<name<<" is Empty...";
				
			else
			{
				cout<<"ALL Songs in the playlist : "<<endl<<endl;
				for(int x=0;x<size;x++)
					songs[x].get_info(x);
			}
		}
		
		void add_song()			//appends a new song at the end of the playlist
		{
     			 
			Song* temp = new Song[size + 1];		// allocate size + 1 songs 
			
			for(int x=0;x<size;x++)			// copy songs to the new array
				temp[x] = songs[x];			
			  
			temp[size].set_info();	    // set the information for the last song added
			++size;				// adjust the size to the new amount
			delete [] songs;		  // delete the old array and set songs to the new array
			songs = temp;
		}
				
		void searchby_name()		//searched for a song by its name (for use in access_song())
		{
			string n;
			cout<<"Enter name of song you are looking for: ";
			cin>>n;
			int a=0;
			
			for(int x=0;x<size;x++)		//actual searching begins here
			{
				if(n==songs[x].get_name())
				{
					system("cls");
					songs[x].get_info(x);
					++a;
					break;
				}
			}
			if(a>0)
			{
				cout<<"\" "<<n<<" \" was not found in the playlist..."<<endl;
			}			
		}

		void access_song()			//function to view info of a single Song
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
						system("cls");
						searchby_name();
						break;
					case 2:
						songs_namelist();
						int n;
						cout<<"\nEnter serial number: ";
						cin>>n;
						songs[n-1].get_info(0);
						break;
					default:
						cout<<"You selected "<<choice<<".\nNo such option exists... \nPress any key to try again";
						getch();
				}
		}
		
		void update_song()			//update info about song
		{
			
		}
		void delete_song()
		{
			int Sno,y=0;		//y is counter for *songs
			system("cls");
			displayAll();
			cout<<"Enter serial number of song you wish to Delete ...";
			cout<<"Press 0 to go back...";
			cin>>Sno;
			
			if(Sno==0)
			{
				return;
			}
			else
			{
				Song * temp = new Song[size-1];
				for(int x=0;x<size-1;x++)
				{
					if(x==Sno-1)
						++y;		//simply skips the index of the song marked for deletion
					temp[x]= songs[y];
					++y;
				}
				delete [] songs;
				--size;
				songs = temp;
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
		
		void songs_namelist()
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
					cout<<x+1<<" Name : "<<songs[x].get_name()<<endl;
				}
			}
		}
		
};

void MenuInterface()
{
	int choice;
	bool check = false;
	string Name;
	Playlist * p;
	Main_menu:				//add goto jump for repeated method of calling menu;
	system("cls");
	cout<<"Enter a number to perform its respective operation: "
		<<"\n (1) Initialize an Empty Playlist"
		<<"\n (2) Check if Playlist is Empty"
		<<"\n (3) Add a Song to the Playlist"
		<<"\n (4) Remove a Song from the Playlist"
		<<"\n (5) Update Song Details in the Playlist"
		<<"\n (6) Check the size of the Playlist"
		<<"\n (7) Exit"
		<<endl<<endl<<" ";
	cin>>choice;
	if(choice!=1 && check)
	{
		cout<<"You must Initialze a playlist first before you can perform any other commands...\n\nPress any key to continue...";
		getch();
		goto Main_menu;
	}
	switch(choice)
	{
		case 1:		//create new empty playlist
			check = true;
			p = new Playlist;
			system("cls");
			cout<<"Enter a name for your playlist : ";
			cin>>Name;
			p->set_name(Name);
			cout<<"A Playlist with the name \" "<<Name<<" \" has been initialized...\nPress any key to continue...";
			getch();
			goto Main_menu;
			break;
		case 2:		//add songs
			p->add_song();
			goto Main_menu;			
			break;
			
		case 3:		//update info
			
			break;
		case 4:		//remove song
			p->delete_song();
			break;
		case 5:		//check size
			
			break;
			
		case 6:		//IsEmpty();
			
			break;
		case 7:
			return;
			break;
		default:
			cout<<"You selected "<<choice<<".\nNo such option exists... \nPress any key to try again";
			getch();
			goto Main_menu;
	}
	
}

int main()
{
	
/*				//Add this so this runs only at the start of the program then MenuInterface() takes over

	system("cls");
	cout<<"\tWelcome to Playlist Management System "
		<<"\n\tDesigned by Muhammad Hammad "
		<<"\n\t----\"This was a real pain to make T_T\"--- "
		<<endl<<endl<<endl
		<<"Press any key to continue to the actual program";
		getch();

*/

//	MenuInterface();
	
/*
	system("cls");
	cout<<"Aww leaving so soon ? Well in any case goodbye";
*/

	Playlist p;
	p.add_song();
	p.add_song();
	p.add_song();
	p.add_song();
	p.displayAll();
	p.delete_song();
	
	p.displayAll();
	return 0;
}

// add_songs(); works alright now. Took some time but worth it!

