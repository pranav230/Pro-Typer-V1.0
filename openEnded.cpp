#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;

ostream& mani(ostream& out)
{
	out<<setw(20)<<fixed<<setprecision(2);
	return out;
}

ostream& center(ostream& out)
{
	out<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	out<<"\t\t\t\t\t\t";
	return out;
}

class L1
{
protected:
	char alpha[26];
	int check[26];
	double timeTaken,accuracy,score;
	public: L1()
			{
				srand(time(NULL));
				for(int i=0;i<26;i++)
					check[i]=1;
				for(int i=0;i<26;i++)
				{
					int num = rand()%26;
					if(check[num])
					{
						check[num]=0;
						alpha[i] = num + 97;
						continue;						
					}
					else
					{
						while(check[num]!=1)
						{
							num++;
							num=num%26;
						}
						alpha[i] = num + 97;
						check[num]=0;    
					}
				}
			}
			double playL1()
			{
				system("CLS");
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t\t\t\t\tLevel 1\n\n\t\t\t\t\t\t 10 letter will be shown on the screen, press the corresponding key\n\n\n\t\t\t\t\t\t Press any key...\n";
				getch();
				system("CLS");
				accuracy=0;
				char ch;
				clock_t begin = clock();
				for(int i=0;i<10;i++)
				{
					cout<<alpha[i]<<"\n";
					ch=getch();
					if(ch==alpha[i])
						accuracy++;
					system("CLS");
				}
				clock_t end = clock();
				timeTaken = (end-begin)/1000.0;
				cout<<"Time taken was "<<timeTaken<<endl;
				timeTaken = (30-timeTaken)*50/27;                  //Formula to calculate time score
				cout<<"Accuracy was "<<accuracy<<endl;
				accuracy = accuracy*50/10;						   //Formula to calculate accuracy score
				if(accuracy < 5)
					score = 0;
				else
					score = timeTaken +accuracy ;
				getch();
				return score;
			}
};

class L2
{
protected:
	char words[100][15];
	double timeTaken,accuracy,score;
	public: 
		    L2()
			{
				//To get words from the file "words.txt" and paste them in array (i.e words[100][15])
				accuracy = 0;
				score = 0;
				timeTaken =0;
				ifstream fp;
				fp.open("words.txt");
				for(int i=0;i<100;i++)
				{
					fp>>words[i];
				}
				//Now to randomise the first 10 words
				int num;
				srand(time(NULL));
				char temp[15];
				for(int i=0;i<10;i++)
				{
					num = rand()%100;
					strcpy(temp,words[i]);
					strcpy(words[i],words[num]);	
					strcpy(words[num],temp);
				}
			}
			double playL2()
			{	
				int wrong=0;		//keeps track of how many words wrongly typed
				char arr[20][15];
				system("CLS");
				char temp[15];		//User's typed word
				cout<<center<<"\t\tLevel 2\n\n\t\t\t\t\t\t\tTen words will be displayed on the screen\n\t\t\t\t\t\t\tType them in quick succession\n\n\t\t\t\t\t\t\t\tPress any key....";				getch();
				system("CLS");
				clock_t start = clock();
				for(int i=0;i<10;i++)
				{
					cout<<words[i]<<"\n";
					cin>>temp;
					if(strcmp(temp,words[i])==0)
						cout<<accuracy++<<endl;
					else
					{
						strcpy(arr[wrong],words[i]);
						strcpy(arr[wrong+1],temp);
						wrong+=2;
					}
				    system("CLS");
				}
				clock_t end = clock();
				timeTaken = (end-start)/1000.0;
				if(!wrong)
				{
					cout<<"Well done, you typed all of them correctly\n";
				}
				else
				{
					cout<<"Wrongly typed words are\n\n";
					cout<<setw(20)<<left<<"Correct"<<"Incorrect\n\n";
					for(int i=0;i<=(wrong-2);i+=2)
					{
						cout<<setw(20)<<setfill('.')<<left<<arr[i]<<arr[i+1];
						cout<<"\n";
					}
				}
				cout<<"\n";
				cout<<"Time taken was "<<timeTaken<<endl;
				timeTaken = (90-timeTaken)*50/70;                  //Formula to calculate time score
				cout<<"Accuracy was "<<accuracy<<endl;
				accuracy = accuracy*50/10;						   //Formula to calculate accuracy score
				if(accuracy < 5)
					score = 0;
				else
					score = timeTaken +accuracy ;
				getch();
				return score;
			}
};

class L3
{
protected:	
	string collection[25];
	double timeTaken,accuracy,score;
	public: L3()
			{
				score =0;
				accuracy =0;
				timeTaken =0;
				ifstream fp;
				fp.open("sentence.txt");
				string temp;
				//To get the 25 strings from the file
				for(int i=0;i<25;i++)                     
				{
					getline(fp,temp,'\n');
					collection[i]=temp;
					// cout<<collection[i]<<endl;
				}
				srand(time(NULL));		//Now to randomise the first 3 strings
				for(int i=0;i<3;i++)
				{
					int num=rand()%26;
					string temp;
					temp=collection[i];
					collection[i]=collection[num];
					collection[num]=temp;
				}
				fp.close();
			}

			double playL3()
			{
				int countOfWords = 0;
				system("CLS");
				int w=0;
				string temp,wrong[50],temp1,temp2;
				cout<<center<<"\t\tLevel 3\n\n\t\t\t\t\t\t\tYou will be shown 3 sentences\n\t\t\t\t\t\t\tWrite them and press enter\n\n\t\t\t\t\t\t\tPress any key to continue...\n";
				getch();
				system("CLS");
				clock_t begin = clock();

				for(int i=0;i<3;i++)
				{
				    cout<<collection[i]<<"\n";
				    fflush(stdin);
				    getline(cin, temp);
				    istringstream tempss(temp);
				    istringstream okss(collection[i]);
				    do
				    {
				    	tempss>>temp1;
				    	okss>>temp2;
				    	if(temp1 != temp2)
				    	{
				    		wrong[w]=temp2;
				    		wrong[w+1]=temp1;
				    		w+=2;
				    	}
				    	else
				    	{
				    		accuracy++;
				    	}
				    	countOfWords++;
				    }while(okss);			
					cout<<"\n";					
				    system("CLS");
				}
				clock_t end = clock();
				timeTaken = (end-begin)/1000.0;
				if(!w)
				{
					cout<<"Well done, you typed all of them correctly\n";
				}
				else
				{
					cout<<"Wrongly typed words are\n\n";
					cout<<setw(20)<<left<<"Correct"<<"Incorrect\n\n";
					for(int i=0 ;i<w; i+=2 )
					{
						cout<<setw(20)<<setfill('.')<<left<<wrong[i]<<wrong[i+1];
						cout<<'\n';
					}	
				}
				cout<<'\n';
				cout<<"Number of words are "<<countOfWords<<endl;
				cout<<"Time taken was "<<timeTaken<<endl;
				timeTaken = ( 3*countOfWords -timeTaken)*50/ (2*countOfWords) ;                  //Formula to calculate time score
				cout<<"Accuracy was "<<accuracy<<endl;
				accuracy = accuracy/countOfWords*50;						   //Formula to calculate accuracy score
				if(accuracy < 5)
					score = 0;
				else
					score = timeTaken +accuracy ;
				getch();
				return score;				
			}

			// void show()
			// {
			// 	for(int i=0;i<3;i++)
			// 		cout<<collection[i]<<"\n";
			// }

};

typedef struct
{
	char para[1000];
}Type_para;

class L4
{
protected:	
	double score,accuracy,timeTaken;
	int countOfWords;
 public:
 	L4()
 	{
 		score =0;
 		accuracy =0;
 		timeTaken =0;
 		countOfWords =0;
 	}
 	double playL4()
 	{
 		system("CLS");
 		cout<<center<<"\t\tLevel 4\n\n\t\t\t\t\t\t\tYou will be shown a paragraph\n\t\t\t\t\t\t\tType the paragraph as fast and as accurately as you can\n\n\t\t\t\t\t\t\tPress any key...\n";
 		getch();
 		system("CLS");
		int w=0; 
		clock_t begin,end;
		char temp[1000];	
 		string temp1,temp2,wrong[50],userinput,stringtemp;
		srand(time(NULL));
		int random = rand()%3;
		// cout<<"\nRandom = "<<random<<endl;
		FILE* fp;
		fp = fopen("paragraphs.bin","rb");
		for(int i=0;i<3;i++)
		{
			fread(&temp,sizeof(Type_para),1,fp);
			begin = clock();
			if(i==random)
			{
				stringtemp = temp;
				cout<<stringtemp<<endl;
				fflush(stdin);
			    getline(cin, userinput);
			    end = clock();
			    istringstream tempss(stringtemp);
			    istringstream okss(userinput);
			    do
			    {
			    	countOfWords++;
			    	okss>>temp1;
			    	tempss>>temp2;
			    	if(temp1 != temp2)
			    	{
			    		wrong[w]=temp1;
			    		wrong[w+1]=temp2;
			    		w+=2;
			    	}
			    	else
			    	{
			    		accuracy++;
			    	}
			    }while(okss);			
				cout<<"\n";
				break;
				system("CLS");
			}		
		}
		if(!w)
		{
			cout<<"Well done, you typed all of them correctly\n";
		}
		else
		{
			cout<<"Wrongly typed words are\n";
			cout<<setw(20)<<left<<"Correct"<<"Incorrect\n\n";
			for(int i=0 ;i<w; i+=2 )
			{
				cout<<setw(20)<<setfill('.')<<left<<wrong[i]<<wrong[i+1];
				cout<<'\n';
			}	
		}
		timeTaken = (end-begin)/1000.0;
		cout<<'\n';
		cout<<"Number of words are "<<countOfWords<<endl;
		cout<<"Time taken was "<<timeTaken<<endl;
		timeTaken = ( 3*countOfWords -timeTaken)*50/ (2*countOfWords) ;                  //Formula to calculate time score
		cout<<"Accuracy was "<<accuracy<<endl;
		accuracy = accuracy/countOfWords*50;						   //Formula to calculate accuracy score
		if(accuracy < 5)
			score = 0;
		else
			score = timeTaken +accuracy ;
		getch();
		return score;			
	}
};

typedef struct
{
	char question[100],op1[20],op2[20],op3[20],op4[20];
	char ans;
}Type_question;

class L5
{
protected:	
	int arr[5];
	double score,accuracy;
    public: L5()
		{
			int num=0;
			srand(time(NULL));
			for(int i=0;i<5;i++)
			{
				num = num + rand()%6 + 1;
				arr[i] = num;
			}
		}

		double playL5()
		{
			char option;
			int counter=0;
			system("CLS");
			cout<<center;
			cout<<"\t\tLevel 5\n\n\t\t\t\t\t\t\tYou will be shown 5 MCQ questions\n\t\t\t\t\t\t\tAnswer by pressing the option 'a' 'b' 'c' or 'd'\n\t\t\t\t\t\t\t(Don't press Enter after pressing your answer)\n";
			cout<<"\t\t\t\t\t\t\tPress any key to continue\n";
			getch();
			system("CLS");

			Type_question temp;
			FILE *fp;
			fp = fopen("questions.bin","rb");

			for(int i=0;i<30;i++)
			{
				fread(&temp,sizeof(Type_question),1,fp);
				if( i == arr[counter] )
				{
					cout<<temp.question<<"\n";
					cout<<"(a) "<<temp.op1<<"\n"<<"(b) "<<temp.op2<<"\n"<<"(c) "<<temp.op3<<"\n"<<"(d) "<<temp.op4<<"\n";
					option = getch();
					if(option == temp.ans)
					{
						score++;
						cout<<":) Correct";
						Sleep(600);
						system("CLS");
					}
					else
					{
						cout<<":( Incorrect";
						Sleep(600);
						system("CLS");
					}
					counter++;
				}
				if(counter == 5)
					break;
			}
			cout<<"Your score was "<<score<<"/5\n";
			score= score*20;
			accuracy = score;
			getch();
			return score;
		}

};

void loadingScreen()
{
	system("CLS");
	string load[3];
	load[0]="Loading.";
	load[1]="Loading..";
	load[2]="Loading...";
	for(int i=0;i<9;i++)
	{
		cout<<center;
		cout<<load[i%3];
		Sleep(150);
		system("CLS");
	}
}


void welcomeScreen(){
	system("cls");	
	char text[] = "   Welcome to Pro Typer V1.0"; // company title

	cout << endl<<center<<endl
	<<"\t\t\t\t\t\t\t  ****************************************"<<endl
	<<"\t\t\t\t\t\t\t  ****************************************"<<endl
	<<"\t\t\t\t\t\t\t  ****************************************"<<endl
	<<"\t\t\t\t\t\t\t  **** " << setfill(' ') << left << setw(30) << text << " ****"<<endl
	<<"\t\t\t\t\t\t\t  ****************************************"<<endl
	<<"\t\t\t\t\t\t\t  ****************************************"<<endl
	<<"\t\t\t\t\t\t\t  ****************************************"<<endl;
	getch();
}
class player: public L1,public L2,public L3,public L4,public L5
{
	double  totalAccuracy,totalScore;
	public: player()
			{
				totalAccuracy = totalScore = 0;
			}
			void play()
			{
				system("CLS");
				totalScore  = totalScore + playL1();
				totalScore  = totalScore + playL2();
				fflush(stdin);	
				totalScore  = totalScore + playL3();				
				totalScore  = totalScore + playL4();			
				totalScore  = totalScore + playL5();
				totalScore  = totalScore / 5;

				totalAccuracy  = totalAccuracy + L1::accuracy;
				totalAccuracy  = totalAccuracy + L2::accuracy;
				totalAccuracy  = totalAccuracy + L3::accuracy;
				totalAccuracy  = totalAccuracy + L4::accuracy;
				totalAccuracy  = totalAccuracy + L5::accuracy;
				totalAccuracy  = totalAccuracy / 5 *2;

				loadingScreen();

				system("CLS");

				cout<<"Level  "<<mani<<"Score"<<mani<<"Accuracy"<<endl;
				cout<<"Level 1"<<mani<<L1::score<<mani<<L1::accuracy*2<<endl;
				cout<<"Level 2"<<mani<<L2::score<<mani<<L2::accuracy*2<<endl;
				cout<<"Level 3"<<mani<<L3::score<<mani<<L3::accuracy*2<<endl;
				cout<<"Level 3"<<mani<<L4::score<<mani<<L4::accuracy*2<<endl;
				cout<<"Level 3"<<mani<<L5::score<<mani<<L5::accuracy<<"\n\n";

				cout<<"Total Score:    "<<fixed<<setprecision(2)<<totalScore<<endl;
				cout<<"Total Accuracy: "<<fixed<<setprecision(2)<<totalAccuracy<<endl;
				cout<<"Thanku for playing :)\n";
				getch();
			}
};


int main()
{

	welcomeScreen();
	system("CLS");
	int choice = 0,subchoice =0;
	while( choice != 3 )
	{
		system("CLS");
		cout<<"\nHow do you want to play the game?\n1. Play the whole game\n2. Play a particular level\n3. Exit\n";
		cin>>choice;
		system("CLS");
		if(choice == 1)
		{
			player ok;
			ok.play();	
		}
		else if( choice == 2 )
		{ 		
			L1 player1;
			L2 player2;
			L3 player3;
			L4 player4;
			L5 player5;

			cout<<"Enter the level you want to play\n";
			cout<<"1. Letters\n2. Words\n3. Sentences\n4. Paragraph\n5. MCQ Questions\n";
			cin>>subchoice;

			switch (subchoice)
			{
				case 1: player1.playL1();
						break;
						
				case 2: player2.playL2();
						break;
				
				case 3: player3.playL3();
						break;
						
				case 4: player4.playL4();
						break;
						
				case 5: player5.playL5();
						break;

				default: cout<<"Invalid choice\n";		
														
			}
		}	
	}	
	return 0;
}