/******************************************************************************

                      
Question/Purpose:
You are designing a website for your new clothing store. You want to help your customers buy
the clothes with the perfect size.
Write an algorithm and a C++ program that asks for the user’s height, weight, and age, and then
computes clothing sizes according to the following formulas.
Cap size = weight in pounds divided by height in inches and all that multiplied by 2.9.
Coat size (chest in inches) = height times weight divided by 288 and then adjusted by
adding one-eighth of an inch for each 10 years over age 30. (Note that the adjustment
only takes place after a full 10 years. So, there is no adjustment for ages 30 through 39,
but one-eighth of an inch is added for age 40.)
The waist in inches = weight divided by 5.7 and then adjusted by adding one-tenth of an
inch for each 2 years over age 28. (Note that the adjustment only takes place after a full 2
years. So, there is no adjustment for age 29, but one-tenth of an inch is added for age 30.)
Use functions for each calculation. This means you must use three functions. Your program
should allow the user to repeat this calculation as often as he or she wishes.

 @author: Pooja Poudel


*******************************************************************************/
#include <iostream>
#include<iomanip>

using namespace std;

   void input(int& height,int& weight,int& age);//function prototype
   double capSize(int& height,int& weight,double& cap);
   double coatSize(int& height,int& weight,int& age,double& coat);
   double waistSize(int& weight,int& age,double& waist);
   void output(double cap,double coat,double waist);


int main()
{
    int height,weight,age;
    double cap,coat,waist;
    char ans;
    do{
        input(height,weight,age);
        capSize(height,weight,cap);
        coatSize(height,weight,age,coat);
        waistSize(weight,age,waist);
        output(cap,coat,waist);
        cout<<"\nEnter Y or y to continue, any other character quits."<<endl;//user input y or Y to continue
        cin>>ans;
        }while('Y'==ans ||'y'==ans);//do-while for repeating program.

        return 0;
}


void input(int& height,int& weight,int& age)//for user input
{
     cout << "Give me your height in inches, weight in pounds,age in years and I will give you cap size, Coat size(inches at chest)and you waist in inches. " << endl;
      cin>>height>>weight>>age;

}

double capSize(int& height,int& weight,double& cap)
 {
     cap=((double)weight/height)*2.9;// weight changed to double to print decimal points
 }


double coatSize(int& height,int& weight,int& age,double& coat)
 {
     coat=(weight*height)/288.00;

     if(age>39)
       coat=coat+((age/10-3)/8.00);//for age>39 adding one-eighth of an inch for each 10 years over age 30.
}

double waistSize(int& weight,int& age,double& waist)
{
waist=weight/5.7;
if(age>28)//adding one-tenth of an inch for each 2 years over age 28
 waist=waist+(((age-28)/2)*0.1);
}


void output(double cap,double coat,double waist)//output function
{
cout<<fixed<<showpoint;
cout<<setprecision(2)<<"Cap size = "<<cap<<endl;
cout<<setprecision(2)<<"Coat size = "<<coat<<endl;
cout<<setprecision(2)<<"Waist size = "<<waist;
}


