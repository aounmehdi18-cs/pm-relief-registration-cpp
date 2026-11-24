#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    char answer,vehicle,owner;
    int year,cc,gender_checker;
     int rejected = 0,male=0,female=0,relief = 0;
     double accepted = 0,applicant = 0,acceptance_rate;

do {
   long long  cnic;
   bool ans = false ;
  cout<<"Hello ! Welcome to PM relief registration centre ! " << endl;
    while(ans==false){
    cout<<"Please enter your CNIC (13 digits, no Dashes ): ";
    cin>> cnic;
    int rem = 0;
long long temp = cnic;
 gender_checker = temp % 10;
    while(temp>0){
      temp = temp /10;
      rem++;
    }
      if(rem == 13){
        ans = true;
      }
      else {
        cout<<"Invalid length.It must be exactly 13 digits ! "<< endl;
      }
    }
    cout<<"Enter your vehicle type (M for Motorcycle,Q for Qingqi,R for Rickshaw,C for Car) : ";
    cin>>vehicle;
    applicant+=1;
    if(vehicle=='M'||vehicle=='Q'||vehicle=='R'||vehicle=='C'){
    if(vehicle=='C'){
      cout<<"What is the registration year : ";
      cin>>year;
      if(year>=2006){
      cout<<"Enter Engine Capacity of car : ";
      cin>> cc;
      cout<<"Is the applicant the registered owner (Y for yes ,N for No) : ";
      cin>>owner;
      if(cc<=800 && owner == 'Y'){
        if (gender_checker%2==0){
           cout<<"Registration accepted (Female) " <<endl ;
           female+=1;
        }else{
       cout<<"Registration accepted {Male} " << endl;
       male+=1; 
        }
         cout<<"Monthly relief : RS 3000 !" << endl;
         relief+=3000;
         accepted+=1;
      }
      else {
        if(cc>800){
        cout<<"Registration rejected  : Engine capacity above 800cc ! ";
        rejected+=1;
      }
      else{
       cout<<"Only Rejistered owner can apply !";
       rejected+=1;
      }
    }
   
  }
      else {
        cout<<"Rejected ! Vehicle rejected before 2006 ! ";
       rejected+=1;
      }
    
    }
  else {
       cout<<"What is the registration year : ";
      cin>>year;
      if (year>=2006){
        if (gender_checker%2==0){
           cout<<"Registration accepted (Female) "<< endl ;
           female+=1;
          }else{
       cout<<"Registration accepted {Male} " <<endl ; 
           male+=1;  
      }
        cout<<"Monthly relief : RS 2000 !" << endl;
           relief +=2000;  
           accepted+=1;
      }
      else{
          cout<<"Registration REJECTED : Vehicle registered before 2006 ! " << endl;
           rejected+=1;
        }
    }
    
    }else {
      cout<<"Unknown Vehicle Type ! ";
       rejected+=1;
    }






    cout<<"Is there any other registration left (Y or y for Yes ,N or n for No ): ";
    cin>> answer;
  }while(answer=='Y' || answer == 'y'); 
  cout<<"Application Processed : ";
  cout<< applicant << endl;
  cout<<"Application (accepted / rejected) : ";
  cout<< "( " << accepted <<" / " << rejected << " ) " << endl; 
  cout<<"Male / Female : " ;
  cout<< male << " / " << female << endl ;
  cout<<"Total relief : " << relief << endl;
  cout<<"Acceptance rate : " ;
  acceptance_rate = (accepted*100)/applicant;
  cout<< setprecision(2) << fixed << acceptance_rate << "%";
  
    return 0;
}