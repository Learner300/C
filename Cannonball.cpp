/***********************************************************
 @author: Pooja Poudel

Objective-A cannonball show is coming, and you are asked to double-check
their calculations to make sure no one gets injured! The human cannonball is fired from a cannon
that is a distance ?? from a vertical wall with a hole through which the cannonball must fly. The
lower edge of the hole is at height ??1 and the upper edge is at height ??2. The initial velocity of
the cannonball is given as ??0 and you also know the angle ?? of the cannon relative to the ground.
Thanks to their innovative suits, human cannonballs can fly without air resistance, and thus their
trajectory can be modeled using the following
??(??) = ??0 ?? cos ??
??(??) = ??0 ?? sin ?? -
1
2
?? ??
2
where ??(??) and ??(??) provides the position of a cannon ball at time t that is fired from point (0,0).
g is the acceleration due to gravity (g = 9.81 m/s
2
).
Write an algorithm and a C++ program to determine if the human cannonball can make it safely
through the hole in the wall. The inputs for the program are ??0 , ??, ??, ??1, ?????? ??2.
? ??0 must be between 0 and 100 m/s.
? ?? must be between 0 and 90 degrees.
? The distance ?? between the cannon and the wall must be between 0 and 1000.
? H1 and H2 (0 < H1 < H2 < 1000) are the heights of the lower and upper edges of the
wall.
To pass safely, there has to be a vertical safety margin of 1m both below and above the point
where the ball’s trajectory crosses the centerline of the wall. Your program output “Safe” if the
cannon ball can safely make it through the wall. Otherwise, output “Not Safe”!

********************************************************************************/

#include <iostream>
#include<cmath>

using namespace std;

const double g=9.81;//accelaration due to gravity
const double pi=3.14159;

void input(double& V,double& angle,double& x,double& H1,double& H2);//input function
double y(double& V,double& angle,double& x,double& t,double& y_T);//function to calculate y
void print(double& y_T,double& H1,double& H2);//print function


int main()//main function
{
double V,angle,x,H1,H2,t,y_T;//declare variables

input(V,angle,x,H1,H2);//function calls
y(V,angle,x,t,y_T);
print(y_T,H1,H2);

return 0;

}



 void input(double& V,double& angle,double& x,double& H1,double& H2)//input function
{

cout << "Enter Inputs: " << endl;

//velocity
cout << "Initial Velocity: " ;
cin>>V;
if (V<0||V>100)//make sure velocity is between 0 and 100.Print error.
{
    cout<<"ERROR.The velocity should be between 0 and 100m/s.";
    cout << "Initial Velocity: " ;
    cin>>V;
}

//angle
cout << "The angle of cannon relative to the ground: ";
cin>>angle;
if(angle<0||angle>90)//print error
{

    cout<<"ERROR.The angle must be between 0 and 90."<<endl;
    cout << "The angle of cannon relative to the ground: ";
    cin>>angle;
}

//distance x
cout << "The distance x between cannon and the wall: ";
cin>>x;
if (x<0||x>1000)//error
{

    cout<<"ERROR.The distance must be between 0 and 1000."<<endl;
    cout << "The distance x between cannon and the wall: ";
    cin>>x;
}

//lower edge
cout << "The height of the lower edge of the wall: ";
cin>>H1;
if(H1<0||H2>1000)//error
{
    cout<<"ERROR.Please Enter a valid height."<<endl;
    cout << "The height of the lower edge of the wall: ";
    cin>>H1;
}

//upper edge
cout << "The height of the upper edge of the wall: ";
cin>>H2;
if(H1>H2||H2<0||H2>1000)//error
{
    cout<<"ERROR.Please Enter a valid height."<<endl;
    cout << "The height of the upper edge of the wall: ";
    cin>>H2;
}
}

//function to calculate time and y.
double y(double& V,double& angle,double& x,double& t,double& y_T)
{
double cos_angle,sin_angle;//declare double
sin_angle=sin((angle*pi)/180);//calculate sine of angle by converting to radian.
cos_angle=cos((angle*pi)/180);//calculate sine of angle by converting to radian.

    t=x/(cos_angle*V);//given model
    y_T=(V*t*sin_angle)-(0.5*g*t*t);//given trajectory model

    return y_T;
}


void print(double& y_T,double& H1,double& H2)//print function

{

   if(H1+1<y_T && H2-1>y_T)
        cout<<"\nSafe"<<endl;//safe case
    else
        cout<<"\nNot Safe";//not safe case
}
