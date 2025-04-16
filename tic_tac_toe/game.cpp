#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
using namespace std;
             
    string str1="";
    string str2="";
    string firstplayer;
    string secondplayer;
    char token='X';
    int row;
    int col;
    bool tie=false;
          
 void upper()
   {
 	 
	system("cls");
    	cout<<"\t\t\t\t\t\t\t\t"<<"`````````````````````````````````"<<endl;  
    	cout<<"\t\t\t\t\t\t\t\t"<<"`````````````````````````````````"<<endl;
    	cout<<"\t\t\t\t\t\t\t\t"<<"``                             ``"<<endl;
    	cout<<"\t\t\t\t\t\t\t\t"<<"``    ****TIC TAC TOE****      ``"<<endl;
    	cout<<"\t\t\t\t\t\t\t\t"<<"``                             ``"<<endl;
	    cout<<"\t\t\t\t\t\t\t\t"<<"`````````````````````````````````"<<endl;  
	    cout<<"\t\t\t\t\t\t\t\t"<<"`````````````````````````````````"<<endl;            
    }
    
void player(){
	
	while (str1=="\0"){
	 cout<<"\t\t\t\t\tPLAYER 1 NAME: \n";
	 cout<<"\t\t\t\t\t\t";
     cin.ignore();
     getline(cin,str1);
    }
    while(str2=="\0"){
     cout<<"\t\t\t\t\tPLAYER 2 NAME: \n";
     cout<<"\t\t\t\t\t\t";
     getline(cin,str2);
    }
    
    int check=0;
    while(check==0){
			  
              cout<<"\t\t\t\t\tWHO PLAY FIRST: "<<str1<<"  "<<str2<<endl;
              cout<<"\t\t\t\t\t\t";
               getline(cin,firstplayer);
              if(firstplayer==str2){
	              check=1;
                  secondplayer=str1;
                }
                
               else if(firstplayer==str1) {
                check=1;
                secondplayer=str2;
	             }
	             
	             else{
			     	system("cls");
              	    cout<<"\t\t\t\t\tPLAYER NAME IN INCORRECT :" <<endl;
	             	continue; 
				 }

	         }
	               cout<<"\t\t\t\t\tFIRST PLAYER :"<<firstplayer<<endl;
                   cout<<"\t\t\t\t\tSECOND PLAYER:"<<secondplayer<<endl;
//	             cout<<secondplayer<<endl;
}
/////////////////////layout/////////////////////

void layout(char array[3][3]){
	cout<<endl;
	cout<<"\t\t\t\t\t\t\t\t"<<"*****PLAY****"<<endl;
	cout<<"\t\t\t\t\t\t\t\t"<<"-------------"<<endl;
	cout<<"\t\t\t\t\t\t\t\t"<<"-------------"<<endl;
	cout<<"\t\t\t\t\t\t\t\t"<<"|  |    |   |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t"<<"|"<<array[0][0]<<" | " <<array[0][1]<<"  | "<<array[0][2]<<" | \n";
	cout<<"\t\t\t\t\t\t\t\t"<<"|__|____|___|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t"<<"|  |    |   |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t"<<"|"<<array[1][0]<<" | " <<array[1][1]<<"  | "<<array[1][2]<<" | \n";
	cout<<"\t\t\t\t\t\t\t\t"<<"|__|____|___|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t"<<"|  |    |   |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t"<<"|"<<array[2][0]<<" | " <<array[2][1]<<"  | "<<array[2][2]<<" | \n";
	cout<<"\t\t\t\t\t\t\t\t"<<"|  |    |   |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t"<<"-------------"<<endl;
	cout<<"\t\t\t\t\t\t\t\t"<<"-------------"<<endl;

	cout<<endl;		
}

////////////play game///////////////////////
void play(char array[3][3]){
	   char digit;
	   if(token=='X'){
	   	cout<<"\t\t\t\t\t\t\t\t"<<firstplayer<<": TURN-";
	   	
	   	cin>>digit;
     
	   }
	    if(token=='O'){
	   	cout<<"\t\t\t\t\t\t\t\t"<<secondplayer<<": TURN-";
    	cin>>digit;
	   }
	
	   /////////////specifing area////////
	   if(digit=='1'){
	   	row=0;
	   	col=0;
	   	
	   }
	   
	    if(digit=='2'){
	   	row=0;
	   	col=1;
	   }
	   
	    if(digit=='3'){
	   	row=0;
	   	col=2;
	   
	   }
	   
	    if(digit=='4'){
	   	row=1;
	   	col=0;
	   	
	   }
	   
	    if(digit=='5'){
	   	row=1;
	   	col=1;
	  
	   }
	   
	    if(digit=='6'){
	   	row=1;
	   	col=2;
	  
	   }
	   
	    if(digit=='7'){
	   	row=2;
	   	col=0;
	   	
	   }
	   
	    if(digit=='8'){
	   	row=2;
	   	col=1;
	   }
	   
	    if(digit=='9'){
	   	   row=2;
	   	   col=2;
	   	
	   }
	   else if(digit<'1' || digit>'9' || digit>='a' && digit<='z' || digit>='A' && digit<='Z'){
	       
	       cout<<"\t\t\t\t\t\t\t!!!! INVALID CHOICE !!!!"<<endl;
	       play(array);
	   }
	 
	       
	if(token=='X' && array[row][col]!='X' && array[row][col]!='O'){
	                  	//unsed place
		array[row][col]='X';
		token='O';
	}
	
	else if(token=='O' && array[row][col]!='X' && array[row][col]!='O'){
	   array[row][col]='O';
	   token='X';
}

    else{
	cout<<"\t\t\t\t\t\t\t\t SPACE FILLED"<<endl;
	play(array);
}

 system("cls");
  layout(array);
  
}
////////////////select winner////////////////
bool winner(char array[3][3]){
	 int i;
	 for(i=0;i<3;i++){
		if(array[i][0]==array[i][1] && array[i][0]==array[i][2] || array[0][i]==array[1][i] && array[0][i]==array[2][i]){
//			 tie=false;
			 return false;
		}
		
	}
	if(array[0][0]==array[1][1] && array[0][0]==array[2][2] || array[0][2]==array[1][1] && array[0][2]==array[2][0]){
//		tie=false;
	      return false;	
	}
	
	for(i=0;i<3;i++){
		int j;
		for(j=0;j<3;j++){
			if(array[i][j]!='X' && array[i][j]!='O')
			{
//				    tie=false;
					return true;
			}
		
		}
	}
	
	 tie=true;
	 return false;
}


//////////////main function//////////
int main(){
    
     upper();
     
    while(1){
    	char array[3][3]={'1','2','3','4','5','6','7','8','9'};
    	cout<<"\n\n\t\t\t\t\t\t\t\t"<<"..........START NEW GAME........."<<endl;
    	cout<<"\t\t\t\t\t\t\t\t[START](1)";
    	cout<<"\t  [END](2)"<<endl;
        cout<<"\t\t\t\t\t\t\t\t";
    	char choice;
    	cin>>choice;
    	system("cls");
    	cout<<"\t\t....................................................................................................."<<endl;
    	if(choice!='1'&& choice!='2'){
    		system("cls");
		}
	
    	switch(choice){
    		case '1':
    			choice= '\0';
    			cout<<"\n\t\t\t\t\t\t\t\t........GAME STARTED........\n\n"<<endl;
    		
	        	system("cls");
    			 player();
    	        cout<<endl;
    	        system("cls");
    			while(winner(array)){
                   layout(array);
                   play(array);
                   winner(array);
               }
                   if(token=='X' && tie==false)
                        cout<<"\t\t\t\t\t\t\t\t***"<<secondplayer<<" WINS "<<"***"<<endl;
                   else if(token=='O' && tie==false)
                       cout<<"\t\t\t\t\t\t\t\t***"<<firstplayer<<" WINS "<<"***"<<endl;
                    else
                        cout<<"\t\t\t\t\t\t\t***MATCH TIE***"<<endl;
                    cout<<"\t\t\t\t\t\t\t\t"<<"press key";
                    getch();
                    system("cls");
                    str1.erase();
                    str2.erase();
                    firstplayer.erase();
                    secondplayer.erase();
                    
    			break;
    			
    	   case '2':
    		
    		cout<<"\t\t\t\t\t\t\t\t\t\t"<<"BYE! see you next time....";
    		
    		cout<<(char)1;
    			return 0;
    	default:
    		cout<<"\t\t\t\t\tCHOICE IS INCORRECT ENTER CORRECT ONE"<<endl;
    		break;
		}	
	}
	return 0;
}
    
