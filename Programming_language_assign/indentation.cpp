#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	char character;						// character variable to check each character one by one
	int i=0,k=0;						// iterator variables
	int countTab=0,match=0,previousTab;			// coutTab will count number of tabs on each line
								// match will count for occurences of 'class' , 'def' and 'end'
								// previousTab will hold the no. of tabs on previous line 
	string charWord,line;
    ifstream file;						// file object of input file stream
    file.open("abc.txt",ios::in);				// file is opened in input mode

    while(!file.eof())
    {
        countTab=0;
        getline(file,line);								// each line is fetched from file 

		for(countTab=0;line[countTab]=='\t';countTab++);		
		cout<<countTab<<endl;							// display no. of tabs on each line


        previousTab=match;						
        k=0;
        while(1)
        {
            character=line[k];
			/* check occurence of 'class','end','def'*/
            if(character=='c' || character=='l' || character=='a' || character=='s'||character=='d' || character=='e' || character=='f' ||character=='n' || character=='d')
            {
                charWord[i]=character;
                charWord[i+1]='\0';
                i++;
            }
			/* check occurence of space and newline character*/
            if(character==' ' || character=='\n')
            {
                if(charWord[0]=='c' && charWord[1]=='l' && charWord[2]=='a' && charWord[3]=='s' && charWord[4]=='s')
                {
                    match++;				// if 'class' increment match variable
                }

                if(charWord[0]=='d' && charWord[1]=='e' && charWord[2]=='f')
                {
					match++;				// if 'def' increment match variable
				}

				if(charWord[0]=='e' && charWord[1]=='n' && charWord[2]=='d'&&charWord[3]=='c')
				{
				match--;					// if 'endc' decrement match and previousTab variable
				previousTab--;
				}

				charWord[0]='\0';
				i=0;

				if(character=='\n')
				{
					if(countTab!=previousTab)				// invalid indentation condition
                    {
						cout<<"Invalid";
						return 0;
                    }
                    break;
                }
            }
            k++;
        }
        k=0;

    }
    return 0;
}

