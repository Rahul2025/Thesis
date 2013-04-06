// reading stats file and comparing it with input data

#include<iostream>
#include<string>
#include<fstream>

#define C 0
#define CPP 1
#define HASKELL 2
#define JAVA 3
#define PYTHON 4

using namespace std;
int main()
{
	int i,flag=0;
	float tim,mem,input_mem,input_tim;
  string line,line1,line2;
  ifstream myfile ("/home/Rahul/Desktop/Thesis/Scripts/Sample1/S2/temp_data");
  ifstream myfile1 ("/home/Rahul/Desktop/Thesis/Scripts/Sample1/S2/stats");
  if ( myfile.is_open() && myfile1.is_open() )
  {
   /* while ( myfile.good() )
    {
      getline (myfile,line);
      cout << line << endl;getline (myfile,line);
    }*/
    getline (myfile,line);
 
    if (line == "C")
    {
    	for(i=0;i<2*C;i++)
    		getline(myfile1,line1);
	    cout << line << " program\n";
	    myfile >> input_mem;
	    myfile >> input_tim;
	    cout << input_mem <<"\t"<< input_tim <<"\n";
//	    getline(myfile1,line1);
//	    getline(myfile1,line2);
		myfile1 >> tim;
		myfile1 >> mem;
		myfile1 >> tim;
	    cout << mem <<"\t"<< tim <<"\n";
	   if(input_mem < mem)
	   {
	   	flag = 1;
	   	cout << "Input program is better(in terms of memory)...\n";
	   }
	   if(input_tim < tim)
	  {
	  		flag = 1;
	  		cout << "Input program is better(in terms of time)...\n";
	  }
	  if(!(flag))
	  	cout << "Input program is no better...\n";
	    
	 }

	 else if (line == "CPP")
	 {
	 	   for(i=0;i<2*CPP;i++)
    		getline(myfile1,line1);
	    cout << line << " program\n";
	    myfile >> input_mem;
	    myfile >> input_tim;
	    cout << input_mem <<"\t"<< input_tim <<"\n";
//	    getline(myfile1,line1);
//	    getline(myfile1,line2);
		myfile1 >> tim;
		myfile1 >> mem;
		myfile1 >> tim;
	    cout << mem <<"\t"<< tim <<"\n";
	   if(input_mem < mem)
	   {
	   	flag = 1;
	   	cout << "Input program is better(in terms of memory)...\n";
	   }
	   if(input_tim < tim)
	  {
	  		flag = 1;
	  		cout << "Input program is better(in terms of time)...\n";
	  }
	  if(!(flag))
	  	cout << "Input program is no better...\n";
	 }

	 else if (line == "HASKELL")
	 {
	 	   for(i=0;i<2*HASKELL;i++)
    		getline(myfile1,line1);
	    cout << line << " program\n";
	    myfile >> input_mem;
	    myfile >> input_tim;
	    cout << input_mem <<"\t"<< input_tim <<"\n";
//	    getline(myfile1,line1);
//	    getline(myfile1,line2);
		myfile1 >> tim;
		myfile1 >> mem;
		myfile1 >> tim;
	    cout << mem <<"\t"<< tim <<"\n";
	   if(input_mem < mem)
	   {
	   	flag = 1;
	   	cout << "Input program is better(in terms of memory)...\n";
	   }
	   if(input_tim < tim)
	  {
	  		flag = 1;
	  		cout << "Input program is better(in terms of time)...\n";
	  }
	  if(!(flag))
	  	cout << "Input program is no better...\n";
	}

	else if (line == "JAVA")
	{
		    for(i=0;i<2*JAVA;i++)
    		getline(myfile1,line1);
	    cout << line << " program\n";
	    myfile >> input_mem;
	    myfile >> input_tim;
	    cout << input_mem <<"\t"<< input_tim <<"\n";
//	    getline(myfile1,line1);
//	    getline(myfile1,line2);
		myfile1 >> tim;
		myfile1 >> mem;
		myfile1 >> tim;
	    cout << mem <<"\t"<< tim <<"\n";
	   if(input_mem < mem)
	   {
	   	flag = 1;
	   	cout << "Input program is better(in terms of memory)...\n";
	   }
	   if(input_tim < tim)
	  {
	  		flag = 1;
	  		cout << "Input program is better(in terms of time)...\n";
	  }
	  if(!(flag))
	  	cout << "Input program is no better...\n";
	}

	else if (line == "PYTHON")
	{
		    for(i=0;i<2*PYTHON;i++)
    		getline(myfile1,line1);
	    cout << line << " program\n";
	    myfile >> input_mem;
	    myfile >> input_tim;
	    cout << input_mem <<"\t"<< input_tim <<"\n";
//	    getline(myfile1,line1);
//	    getline(myfile1,line2);
		myfile1 >> tim;
		myfile1 >> mem;
		myfile1 >> tim;
	    cout << mem <<"\t"<< tim <<"\n";
	   if(input_mem < mem)
	   {
	   	flag = 1;
	   	cout << "Input program is better(in terms of memory)...\n";
	   }
	   if(input_tim < tim)
	  {
	  		flag = 1;
	  		cout << "Input program is better(in terms of time)...\n";
	  }
	  if(!(flag))
	  	cout << "Input program is no better...\n";
	}
   else
 	  cout << "Not a program";
    myfile.close();
    myfile1.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}