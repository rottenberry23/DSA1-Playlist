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
			
		void set_info()		//for input
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
		
		void get_info(int n)		//for output
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
			int n;
			displayAll();
			cout<<"Enter Serial No. of Song u wish to update (0 to cancel): ";
			cin>>n;
			if(n==0)
				return;
			cout<<endl<<endl
				<<songs[n-1].get_name()<<" is the song you wish to update... \n";
			
			string name, artist;
			float duration;

			cout<<"Enter Name of Song: ";
			cin>>name;
			cout<<"Enter Name of the Artist: ";
			cin>>artist;
			cout<<"Enter the Duration of the Song: ";
			cin>>duration;
			
			songs[n-1].set_name(name);
			songs[n-1].set_artist(artist);
			songs[n-1].set_duration(duration);
			
			cout<<endl
				<<"Information for Song \" "<<name<<" \" has been set! "
				<<"\nPress any key to continue...";
			getch();
			
		}
		
		void delete_song()		//delete a song from the playlist
		{
			int Sno,y=0;		//y is counter for *songs
			system("cls");
			if(size == 0)
			{
				cout<<"Can't delete anthing if playlist is empty...\nPress any key to continue...";
				getch();
				return;
			}
			displayAll();
			cout<<"\n\nEnter serial number of song you wish to Delete ...";
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
				cout<<songs[Sno].get_name()<<" has been deleted from playlist...\npress any key to continue...";
				delete [] songs;
				--size;				//decrementing size cuz we deleted a song
				songs = temp;
				getch();				
			}							
		}
		
		int get_size()		//returns size of playlist
		{	return size;	}
		
		bool IsEmpty()		//checks if a playlist is empty
		{
			if(size==0)
				return true;
			else
				return false;
		}
		
		void songs_namelist()		// gives a list of only tha names of songs
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
		
		//	PART 2 : MANAGEMENT: 
		void Sorting()		//sorting aplhabetically and bu duration
		{
			int choice;
			cout<<"HOw do you wish to sort out your playlist? "
				<<"\n(1). Alphabetically "
				<<"\n(2). Duration wise "<<endl;
			cin>>choice;
			if(choice ==1)	//sort alphatbetically
			{
				Song swap;
				Song * temp = new Song[size];
				
				for(int x=0; x<size;x++)
				{
					for(int y=0; y<size;y++)
					{
						if(songs[x].get_name() < songs[y].get_name())
							{
								swap = songs[x];
								songs[x]=songs[y];
								songs[y]=swap;
							}
					}
				}
				cout<<"Playlist has been sorted Alphabetically...\nPress any key to continue";
				getch();
				return;
			}
			else if(choice ==2)	//sort by smallest to largest duration
			{
				Song swap;
				Song * temp = new Song[size];
				
				for(int x=0; x<size;x++)
				{
					for(int y=0; y<size;y++)
					{
						if(songs[x].get_duration() < songs[y].get_duration())
							{
								swap = songs[x];
								songs[x]=songs[y];
								songs[y]=swap;
							}
					}
				}
				cout<<"Playlist has been sorted from smallest to largest duration...\npress any key to continue";
				getch();
				return;
			}
			else
			{
				system("cls");
				cout<<choice<<" is not an option...\nPress any key to continue...";
				getch();
				return ;
			}
		}
		
		void Rearrange()		//swap postiions of two songs by index number
		{
			int to_swap, swap_with;
			displayAll();
			cout<<"\n\nEnter Serial Number of Song you wish to Move : ";
			cin>>to_swap;
			cout<<"\n\nEnter Serial Number of Song you wish to Swap with : ";
			cin>>swap_with;
			
			Song swap;
			swap = songs[to_swap-1];
			songs[to_swap-1] = songs[swap_with-1];
			songs[swap_with-1] = swap;
			cout<<"\n The songs have been swapped with each other!!!\nPress any key to continue";
			getch();
		}
		
		void recommendations()		//based on most listened to artist
		{
			system("cls");
			int counter[size];
			int i1;			//indexes of top 3 artists songs 
			ifstream file("recommendations.txt");
			for(int x=0;x<size;x++)		//sets all counts to 1
			{
				counter[x]= 1;
			}
			for(int x=0;x<size;x++)		//counts number of diff artists
			{
				for(int y=0;y<size;y++)
				{
					if(songs[x].get_artist()==songs[y].get_artist())
						++counter[x];					
				}
			}
			int first= counter[0], second= counter[0];
			for(int x=1; x<size;x++)		//to get count of repeated artists in the playlist to recommend songs from top first listened to artists
			{
				if(counter[x]==0)
					continue;
				else if(first<counter[x])
					first = counter[x];
			}			
			for(int x=0;x<size;x++)
			{
				if(first==counter[x])
					i1=x;				
			}
			cout<<"You listen to This Artist the Most : "
				<<endl
				<<songs[i1].get_artist()
				<<endl;	
			cout<<"press any key to get recommendation for songs : ";
			getch();
			string n, art;
			while(!file.eof())
			{
				file >>art >> n;
				if(art == songs[i1].get_artist())
				{
					cout<<"Name : "<<n<<"\t"<<"Artist : "<<art<<endl;
				}
			}
			cout<<"\n\nPress any key to continue...";
			getch();				
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
	cout<<"Part 1:"
		<<"\nEnter a number to perform its respective operation: "
		<<"\n (1) Initialize an Empty Playlist"
		<<"\n (2) Check if Playlist is Empty"
		<<"\n (3) Add a Song to the Playlist"
		<<"\n (4) Remove a Song from the Playlist"
		<<"\n (5) Update Song Details in the Playlist"
		<<"\n (6) Check the size of the Playlist"
		<<"\n (7) View All Songs"
		
		<<"\n\nPart 2:"
		<<"\n (8) Sort your Playlist		(alphabetically/duration)"
		<<"\n (9) Reorder your Playlist		(swap songs)"
		
		<<"\n\nBONUS TASK:"
		<<"\n (10) Get Recommnedations"
		<<"\n\n (11) Exit"
		<<endl<<endl<<" Selection: ";
	cin>>choice;
	if(choice!=1 && !check)
	{
		system("cls");
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
			
		case 2:		// IsEmpty();
			system("cls");
			if(p->IsEmpty())
			{
				cout<<"Playlist\" "<<Name<<" \" is Empty";
				cout<<"\nPress any key to continue...";
				getch();
			}
			else
			{
				cout<<"Playlist\" "<<Name<<" \" is Not Empty";
				cout<<"\nPress any key to continue...";
				getch();
			}
			goto Main_menu;
			break;
			
		case 3:		//Add Song
			p->add_song();
			goto Main_menu;	
			break;
			
		case 4:		//remove song
			p->delete_song();
			goto Main_menu;
			break;
			
		case 5:		//Update Song
			p->update_song();
			goto Main_menu;
			break;
			
		case 6:		//Check Size;
			system("cls");
			cout<<"Current Size of Playlist \" " << p->get_name()<<" \" is : " << p->get_size()<<" songs..."
			<<"\nPress any key to continue...";
				
			getch();
			goto Main_menu;
			break;
		case 7:
			p->displayAll();
			cout<<"\nPress any key to continue...";
			getch();
			goto Main_menu;
			
		case 8:		//Sort songs 
			p->displayAll();
			p->Sorting();
			goto Main_menu;			
			break;
			
		case 9:		// Reorder your playlist (swap)
			p->Rearrange();
			goto Main_menu;
			break;
			
		case 10:	//get recommendations
			p->recommendations();
			goto Main_menu;
			break;
			
		case 11:
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
	system("cls");
	cout<<"\tWelcome to Playlist Management System "
		<<"\n\tDesigned by Muhammad Hammad "
		<<"\n\t----\"This was a real pain to make T_T\"--- "
		<<endl<<endl<<endl
		<<"Press any key to continue to the actual program";
		getch();

	MenuInterface();	

	system("cls");
	cout<<"Aww leaving so soon ? Well in any case goodbye";

	return 0;
}

