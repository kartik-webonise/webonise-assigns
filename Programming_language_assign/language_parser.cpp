#include<iostream>
#include<fstream>
#include<string>
using namespace std;

char name[20];	//variable name stores the file name enterd by user

/* Class Identifier has member functions which will give the code language,classes,methods and variables
	All the member functions are made public */
	
class Identifier	
{
	public:
			void getLanguage();
			void getClass();
			void getJavaMethod();
			void getPhpMethod();
			void getRubyMethod();
			void getPhpVariable();
			void getRubyVariable();
			void getJavaVariable();
};

/* getLanguage is the member function of class Identifier which tells the language of the code 
	from Java, php and Ruby*/
	
void Identifier::getLanguage()
{
    int countClassDef=0,countEnd=0;		// variable countClassDef counts the number of 'class' keyword and 'def' keyword
										// variable countEnd counts the number of 'end' keyword 
	ifstream file;						// object file is created for file operations in read-only mode
	Identifier method,variable;			// created two objects method and variable of class Identifier
    string data;						// variable data stores the intended entry in file word by word

	file.open(name,ios::in);			// file is opened in input mode
    while(!file.eof())					// conditions are checked till end of file
    {
		file>>data;
		if(data.compare("<?php")==0)		// condition check for php language
        {
			cout<<"\nIt is a PHP program";
			method.getPhpMethod();			// Method getPhpMethod is called using object method
			variable.getPhpVariable();		// Method getPhpVariable is called using object variable
            return;
        }
		
		// condition check for ruby language
		else if(data.compare("def")==0||data.compare("class")==0||data.compare("end")==0)	
        {
            if((data.compare("def")==0)||(data.compare("class")==0))
				countClassDef++;								// count of 'class' and 'def'
            if(data.compare("end")==0)
               countEnd++;										// count of 'end'
        }

    }
    cout<<countClassDef<<endl;
    cout<<countEnd;
    if(countClassDef==countEnd-1)			// condtition check for ruby language
    {
		cout<<"\nIt is a RUBY program";
		method.getRubyMethod();				// Method getRubyMethod is called using object method
		variable.getRubyVariable();			// Method getRubyVariable is called using object variable
		return;
	}
    else
    {
		cout<<"\nIt is a JAVA program\n";		// else a Java code
		method.getJavaMethod();					// Method getJavaMethod is called using object method
		variable.getJavaVariable();				// Method getJavaVariable is called using object variable
	}
	file.close();
}

/* getClass() function is implemented to find the name of class in all the three languages
	The function finds the keyword 'class' and displays the word next to it which will be
	the class name*/
	
void Identifier::getClass()
{
	int i;				//iterator variable i used in for loop 
    ifstream file;		
    string data;				// file contents are fetched in variable data
    file.open(name,ios::in);		// file opened in input mode
	cout<<"\n------The Classes in file "<<name<<" are------ : ";
    while(!file.eof())
    {
		file>>data;
		if(data.compare("class")==0)			// ocurrence of keyword 'class' is checked 
        {
			file>>data;							// next word to 'class' is fetched 
            for(i=0;data[i]!='\0';i++);
            if(data[i-1]==123)					// ocurrence of '{' opening curly bracket is checked using it's ASCII value 123
				data[i-1]='\0';
            cout<<endl<<data<<endl;				// The name of class is displayed
        }
    }
}
/* getRubyMethod() is implemented to find and display all the methods once 
	language ruby is detected. It checks the occurence of keyword 'def' and
	displays the word next to it as the method name */
	
void Identifier::getRubyMethod()

{
    int i;							// iterator i used in for loop
    ifstream file;
	string data;					//	file contents are fetched in variable data
    file.open(name,ios::in);		// file opened in input mode
	cout<<"\n-----The methods in file"<<name<<" are : ";
    while(!file.eof())
    {
		file>>data;
		if(data.compare("def")==0)					// occurence of 'def' is checked
        {
			file>>data;								// the next word is fetched
            cout<<endl<<data<<endl;					// the method name is displayed
        }
	}
}

/* getPhpMethod() is implemented to find and display all the methods once 
	language php is detected. It checks the occurence of keyword 'function' and
	displays the word next to it as the method name */
	
void Identifier::getPhpMethod()
{
	ifstream file;
	string data,access;					// variable access is used with in-built function assign to store the access specifier
    file.open(name,ios::in);			// file is opened in input mode
	cout<<"\n-----The methods in file"<<name<<" are : ";
	while(!file.eof())
    {
		file>>data;
		if(data.compare("public")==0||data.compare("private")==0||data.compare("protected")==0)			// ocurrence of access specifier is checked
		{
			access.assign(data);					// access specifier is stored in variable in access 
			file>>data;								// next word is fetched
			if(data.compare("function")==0)			// occurence of 'function' is checked
       		{
				file>>data;							// the function name is displayed
				cout<<endl<<access <<" "<<data<<endl;
        	}
		}

	}
}

/* getJavaMethod() is implemented to find and display all the methods once 
	language java is detected. It checks the occurence of access specifier followed
	by the data type and displays the word next to it as the method name */
	
void Identifier::getJavaMethod()
{
	ifstream file;
	int i;						// iterator i used in for loop
    string data,access;			// variable access is used with in-built function assign to store the access specifier
    file.open(name,ios::in);	// file is opened in input mode 
	cout<<"\n-----The methods in file"<<name<<" are : ";

	while(!file.eof())
    {
		file>>data;
		if(data.compare("public")==0||data.compare("private")==0||data.compare("protected")==0)		// occurence of access specifier is checked 
		{
			access.assign(data);			// access specifier is stored in variable access
			file>>data;						// next word is fetched
			// occurence of data type is checked
			if(data.compare("void")==0||data.compare("String")==0||data.compare("Long")==0||data.compare("Double")==0||data.compare("int")==0)// || data.compare("void")==0||data.compare("String")==0||data.compare("Long")==0)
				file>>data;						// next word is fetched
			for(i=0;data[i]!='\0';i++);			// i is incremented to end of the word
			if(data[i-1]!=';')					// occurence of ';' is checked
					cout<<endl<<access<<" "<<data<<endl;		// method is displayed along with it's access specifier

		}
	}
}

/* getPhpVariable() is implemented to find and display all the variables once 
	language java is detected. It checks the occurence of access specifier followed
	by the data type and displays the word next to it as the method name */
	
void Identifier::getPhpVariable()
{
    ifstream file;
    string data;
    file.open(name,ios::in);			// file is opened in input mode

	cout<<"\n----Properties Of the class  ";
	cout<<"\n-----The variables in file"<<name<<" are : ";

	while(!file.eof())
    {
        file>>data;
		if(data.compare("public")==0||data.compare("private")==0||data.compare("protected")==0)		// occurence of access specifier is checked 
		{
			file>>data;
			if(data[0]=='$')			// occurence of '$' is checked
				cout<<endl<<data<<endl;		// variable along with '$' is displayed
		}
	}
}

/* getRubyVariable() is implemented to find and display all the variables once 
	language ruby is detected. It checks the occurence of '@' to display class 
	variables */
	
void Identifier::getRubyVariable()
{
	int i;
    ifstream file;
    string data;
    file.open(name,ios::in);				// open file in input mode

	cout<<"\n----Properties Of the class  ";
	cout<<"\n-----The variables in file"<<name<<" are : ";

	while(!file.eof())
    {
        file>>data;
		if(data[0]=='@' && data[1]=='@')				// check occurence of '@@'
		{
			cout<<endl<<"The class variables are : "<<data<<endl;		// display variable along with '@@'
		}
	}	
}


/* getJavaVariable() is implemented to find and display all the variables once 
	language Java is detected. It checks the occurence of access specifier followed
	by ';' at the end of string */
	
void Identifier::getJavaVariable()
{
	int i;
    ifstream file;
    string data,type;				// variable type is used to store the data type
    file.open(name,ios::in);		// open file in input mode

	cout<<"\n----Properties Of the class  ";
	cout<<"\n-----The methods in file"<<name<<" are : ";

	while(!file.eof())
    {
		file>>data;
		if(data.compare("void")==0||data.compare("String")==0||data.compare("Long")==0)		// occurence of data type is checked
		{
			type.assign(data);							// data type is stored in variable type
			file>>data;									// next word is fetched
			for(i=0;data[i]!='\0';i++);					// i is incremented to the end of string
			if(data[i-1]==';')							// occurence of ';' is checked and discarded from the output
				cout<<endl<<type<<" "<<data<<endl;
		}
	}
}

/* Main method definition*/
int main()
{
    Identifier language,classes;	// created two objects of class Identifier

	cout<<"\nEnter the file name\t";	// get file from user in variable name(global) 
    cin>>name;

	language.getLanguage();			//getLanguage function is called using object language
    classes.getClass();				//getClass function is called using object classes

    return 0;
}








