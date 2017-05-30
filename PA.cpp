// Personal Assistant 1.0 ( based on C++ )
// Subsmission Year : 2015
// Purpose : OOP Principles based Project (for assignment) 

#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <istream>
#include <ostream>
#include <string.h>
using namespace std;
class id
{
	protected:
		static string name;
		static int age;
        public:
        	int code;
        	id()
        	{
        		name='\n';
        	}
            id(int i)
            {
             	if (i==1)
             	{
                	cout<<"\nPlease enter your name:";
                	cin>>name;
                }
            }
            id(string a)
            {
                name=a;
            }
            void greet(int ctr)
            {
            	if(ctr==0)
            	{
		        	cout<<"\nHello,"<<name<<"!";
		        	cout<<"\nHow may I help you?";
            	}
            	else
            		cout<<"\n\nGlad you are back! :)";
            	cout<<"\nFor Resume Maker enter 1 , for Calendar enter 2 and for To-do List maker enter 3 :";
            	cin>>code;
            }
};
string id::name;
int id::age;
class cv:virtual public id
{
    char fname[15],lname[15];
    int year,no_of_acheivements;
    float result;
    long int dob,c_no;
    char gender[10],marital_status[10],religion[15],qual[30];
    public:
    void cv_maker()
    {
    	ofstream ofile("Resume.txt");
    	if ( cin.peek() == '\n' )
		cin.ignore();
    	cout<<"Please give your First Name:";
    	cin>>fname;
    	if ( cin.peek() == '\n' )
		cin.ignore();

    	cout<<"Age:";
    	cin>>age;
    	cout<<"Last name:";
    	cin>>lname;
    	if ( cin.peek() == '\n' )
		cin.ignore();
	cout<<"Date of birth(without '-'or'/')";
    	cin>>dob;
    	if ( cin.peek() == '\n' )
		cin.ignore();
	cout<<"Contact Number:";
	cin>>c_no;
	if ( cin.peek() == '\n' )
		cin.ignore();
    	cout<<"Gender:";
    	cin>>gender;
    	cout<<"Religion:";
    	cin>>religion;
    	if ( cin.peek() == '\n' )
		cin.ignore();
    	cout<<"Marital Status:";
    	cin>>marital_status;
    	cout<<"Matriculation board ,year and percentage/CGPA obtained:";
    	cin>>qual;
    	cin>>year>>result;
    	ofile<<"\t\t\t\t\t\t\t\tRESUME";
    	ofile<<"\nName\t\t\t\t\t\t:\t\t\t\t\t\t"<<fname<<" "<<lname;
    	ofile<<"\nGender\t\t\t\t\t\t:\t\t\t\t\t\t"<<gender;
    	ofile<<"\nReligion\t\t\t\t\t:\t\t\t\t\t\t"<<religion;
    	ofile<<"\nMarital Status\t\t\t\t\t:\t\t\t\t\t\t"<<marital_status;
    	ofile<<"\nAge\t\t\t\t\t\t:\t\t\t\t\t\t"<<age;
    	ofile<<"\nContact number\t\t\t\t\t\t:\t\t\t\t\t\t"<<c_no;
    	ofile<<"\n\n---------------------------------------------------------------------------------------------------------------------------";
    	ofile<<"\nQualifications:";
    	ofile<<"\n---------------------------------------------------------------------------------------------------------------------------";
    	ofile<<"\n Class 10th\t\t\t\t\t\t:\t\t\t\t\t"<<result<<"(Year of passing:"<<year<<")";
    	cout<<"10+2 board ,year and percentage obtained:";
    	cin>>qual;
    	cin>>year>>result;
    	ofile<<"\n Class 12th\t\t\t\t\t\t:\t\t\t\t\t"<<result<<"(Year of passing:"<<year<<")";
    	cout<<"Average SGPA and year of passing(if still doing B.Tech Mention the year when you will finish):";
    	cin>>result>>year;
    	ofile<<"\nBachelor in Technology\t\t\t\t\t:\t\t\t\t\t"<<result<<"SGPA(Year of passing:"<<year<<")";
    	ofile<<"\n\n---------------------------------------------------------------------------------------------------------------------------";
    	ofile<<"\nAchievements:";
    	ofile<<"\n---------------------------------------------------------------------------------------------------------------------------";
    	cout<<"How many achivements do you want to write?:\n";
    	cin>>no_of_acheivements;
    	for(int i=0;i<no_of_acheivements;i++)
    	{
    		char ac[60];
    		cout<<"Enter the achievement #"<<i+1<<"(after entering it please press 'enter' twice):";
    		if ( cin.peek() == '\n' )
			cin.ignore();
    		cin.getline(ac,sizeof(ac));
    		if ( cin.peek() == '\n' )
			cin.ignore();
    		ofile<<"\n"<<i+1<<"."<<ac;
    	}
    	ofile.close();    		
    }
};

class calendar:virtual public id
{
    public:
        /* This function calculates the first day of the new year                 */
        int  firstDayofNewYearAndMonth(int year) 
        { 
            int day_start; 
            int x1, x2, x3; 
            x1 = (year - 1)/ 4;
            x2 = (year - 1)/ 100; 
            x3 = (year - 1)/ 400; 
            day_start = (year + x1 - x2 + x3) %7; 
            return day_start; 
        }
        /* Function for checking leap year helps in function number of days in a month*/
        int leapyear(int year)
        {
		    if (year%4 == 0) 
		    {
				if (year%100 == 0) 
				{
					if (year%400 == 0)
						return 1;
					else 
						return 0;
				}
				else 
					return 1;		    
			 }	
				 else
					return 0;
		}	    	

        /* This function returns the number of days in a month                    */
        int numOfDaysInAMonth (int m,int year)
        {
            switch(m)
            {
            	case 1: return 31;
            	break;
            	case 2:{
						if(leapyear(year)==1)          	
				        	return 29;
				        else
				            return 28;
            			}
            	break;
            	case 3:return 31;
            	break;
            	case 4:return 30;
            	break;
            	case 5:return 31;
            	break;
            	case 6:return 30;
            	break;
            	case 7:return 31;
            	break;
            	case 8:return 31;
            	break;
            	case 9:return 30;
            	break;
            	case 10:return 31;
            	break;
            	case 11:return 30;
            	break;
            	case 12:return 31;
            	break;
            }    
        }
/*    It takes the number of the month and prints out the name of the month and the frame of the calander      */
        void printHeader (int m) 
	    {
		if (m == 1)
			cout << "\tJanuary" << endl;
		else if (m == 2)  
			cout << "\tFebruary" << endl;  
		else if (m == 3)      
			cout << "\tMarch" << endl; 
		else if (m == 4)   
			cout << "\tApril" << endl; 
		else if (m == 5)   
			cout << "\tMay" << endl; 
		else if (m == 6)   
			cout << "\tJune" << endl; 
		else if (m == 7)   
			cout << "\tJuly" << endl; 
		else if (m == 8)  
			cout << "\tAugust" << endl; 
		else if (m == 9)   
			cout << "\tSeptember" << endl; 
		else if (m == 10) 
			cout << "\tOctober" << endl; 
		else if (m == 11)   
			cout << "\tNovember" << endl; 
		else if (m == 12)   
			cout << "\tDecember" << endl; 

		cout << " S  M  T  W  T  F  S" <<endl;
		cout << "_____________________" << endl;
	    }
/* This function prints out the days in the month after the header for the month specified */
/* and variable "check" checks whether the month is to be printed or not */
        void printMonth (int numDays, int &weekDay,int check) 
        {
            int day = 1;
            if(check==1)
            {
            	skipToDay(weekDay);
				while (day <= numDays) 
				{
				    cout<< setw(2) << day << " ";
				    if (weekDay == 6)
				    {
				        cout << endl;
				        weekDay = 0;
				    }
				else 
				    weekDay = weekDay + 1;
				day = day + 1; 
				}
				
			}
			else
			{
				while (day <= numDays) 
				{
				    if (weekDay == 6)
				    {
				        weekDay = 0;
				    }
				else 
				    weekDay = weekDay + 1;
				day = day + 1; 
				}
				
			}
        }
/* Prints spaces in calander                   */
        void skipToDay (int d)
        {
			int i=3*d;        
        	while (i > 0) 
            {
                cout << " ";
                i--;
            }
        }
/* Main function for displaying calendar */
        void get_calendar()
        {
            int year, firstDayInCurrentMonth;
            int currentMonth = 1,currMonth;
            int numDays,month=1;
            cout << "What month & year do you want a calendar for(please specify month number not month name and give space between year and month)?\n";
            cin>>currMonth>>year;
            cout<<id::name<<",here's the calendar you asked for."<<endl;
            cout <<"\t"<<year << endl;
            firstDayInCurrentMonth=firstDayofNewYearAndMonth(year);
            while(month<=currMonth)
            {
		        	if(month==currMonth)
		        	{
						numDays = numOfDaysInAMonth(currentMonth,year);
						printHeader(currentMonth);
						printMonth(numDays, firstDayInCurrentMonth,1); 	//here 3rd parameter specifies to print the month
						cout << endl << endl << endl;
						cout << endl;
					}
					else
					{
						numDays = numOfDaysInAMonth(currentMonth,year);
						printMonth(numDays, firstDayInCurrentMonth,0);	//here 3rd parameter specifies not to print the month
					}
					month++;
					currentMonth++;
            }
        }
        
};

class to_do_list:public virtual id
{
	float time;
	char work[25];
	public:
	void to_do_list_maker()
	{
		ofstream ofile("todo.htm");
		ofile<<"<html>\n <title> To-Do List \n</title>";
		ofile<<"\n<body>\n\n<center><h1>"<<name<<"'s To-Do List</h1>\n<basefont face='Comic Sans MS'>";
		ofile<<"\n<h4>\n<table summary='Time is important' border=5 cellpadding=30 cellspacing=50>\n<tr>\n<td>Time</td>\n<td>Task</td>\n</tr>";
		char check='Y';
		while(check=='Y' || check=='y')
		{
			cout<<"Enter time(according to 24 hr format):";
			cin>>time;
			cout<<"Enter task you have to do:";
			if ( cin.peek() == '\n' )
				cin.ignore();
			cin.getline(work,sizeof(work));
			ofile<<"\n<tr>\n<td>"<<time<<"</td>"<<"\n<td>"<<work<<"</td>\n</tr>";
			cout<<name<<",you want to add more tasks?(Y/N)";
			cin>>check;
		}
		ofile<<"\n</h4>\n</center>\n</body>\n</html>";
		ofile.close();
	}
};

class review: virtual public id
{
	int rating;
	public:
	void rate()
	{
		cout<<"Enter the ratings in between 1 to 5 star:";
		cin>>rating;
		ofstream rfile;
		ofstream nfile;
		rfile.open("Ratings.dat",ios::app);
		nfile.open("Names.dat",ios::app);
		nfile<<name;
		rfile<<"\n"<<rating;
		rfile.close();
		nfile.close();	
	}
	float avg_rating()
	{
		float res;
		int sum,tot=0;
		fstream ifile;
		ifile.open("Ratings.dat");
		ifile.seekg(1,ios::beg);
		while(ifile.eof()!=1)
		{
			int irating;
			ifile>>irating;
			sum+=irating;
			tot++;
		}
		 res=(float)(sum/tot);
		 ifile.close();
		 return res;
	}
	
};			
int main()
{
	review r;
 cout<<"----------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t\tWELCOME TO PA v1.0"<<"\t\t\t\tAverage Rating:"<<r.avg_rating();
    char check='Y';
    int no_of_runs=0;
    cv c1;
	to_do_list t;
	calendar c;
    id person(1);
    while(check=='Y' || check=='y')
    {	
    	if(no_of_runs==0)
			person.greet(0);
		else
			person.greet(1);
		switch(person.code)
		{
		    case 1:c1.cv_maker();
		    break;
		    case 2:c.get_calendar(); 
		    break;
		    case 3:t.to_do_list_maker();
		    break;
		    default:"Please enter a Valid Code!";       	
		}
		cout<<"Do you want to do more things?";
		cout<<"\n(Y/N)		:		";
		cin>>check;
		no_of_runs++;
	}
	cout<<"\n\nWe would be glad if you gave us rating.";
	cout<<"\nTo proceed for ratings. Press Y for Yes and N for No:		";
	cin>>check;
	if(check=='Y' || check=='y')
		r.rate();
	cout<<"\n\nYou ran the program for "<<no_of_runs<<" times\nThank you for using this app!\nHope you liked it!:)\n\n\n";
		cout<<"----------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n";
	exit(0);
    return 0;
}
