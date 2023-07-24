#include <stdio.h>

/* Unit Conversion for Pressure -  Converts various units of pressure between one another. The user enters the value and type of 
unit being entered. The program will then perform the conversions, and provide the equivalent value in the other 4 units. */

int unitConvert(int i, int j){
    
int n = i;

int a = 100000;
int b = 101325;
int c = 760;
float d = 13.591;
float e = 9.80665;

int bar;
int torr;
int atm;
int mmhg;
int pa;

   switch(j) {
       
    case 1 :
    //Convert from Pascals

    printf("You have entered %d Pascals \n", n);
    printf("The conversion rates are: \n");
    bar = n/a;
    printf("%d bar ", bar);

    atm = n/b;
    printf("%d atm ", atm);

    torr = n*(c/b);
    printf("%d Torr ", torr);

    mmhg = n/(d*e);
    printf("%d mmHg ", mmhg);

    break;
    
    case 2 :
    // Convert from barr
    printf("You have entered %d barr \n", n);
    printf("The conversion rates are: \n");
  
    pa = n*a;
    printf("%d Pascals ", pa);

    atm = n*(a/b);
    printf("%d atm ", atm);

    torr = n*((a*c)/b);
    printf("%d Torr ", torr);

    mmhg = n*(a/(d*e));
    printf("%d mmHg ", mmhg);
    
    break;
      
    case 3 :
    // Convert from atm
    printf("You have entered %d atm \n", n);
    printf("The conversion rates are: \n");
    
    pa = n*b;
    printf("%d Pascals ", pa);

    bar = n*(b/a);
    printf("%d bar ", bar);

    torr = n*c;
    printf("%d Torr ", torr);

    mmhg = n*(b/(d*e));
    printf("%d mmHg ", mmhg);

    break;
    
    case 4 :
    // Convert from Torr
         
    printf("You have entered %d Torr \n", n);
    printf("The conversion rates are: \n");

    pa = n*(b/c);
    printf("%d Pascals ", pa);

    bar = n*(b/a*c);
    printf("%d bar ", bar);

    atm = n*(1/c);
    printf("%d atm ", atm);

    mmhg = n*(b/(c*d*e));
    printf("%d mmHg ", mmhg);

    break;
    
    case 5 :
    // Convert from mmHg

    printf("You have entered %d mmHg \n", n);
    printf("The conversion rates are: \n");

    pa = n*(d*e);
    printf("%d Pascals ", pa);

    bar = n*((d*e)/a);
    printf("%d bar ", bar);

    atm = n*((d*e)/b);
    printf("%d atm ", atm);

    torr = n*((c*d*e)/b);
    printf("%d Torr ", torr);

    break;
    
    default :
        printf("Invalid option \n" );
   }

return 0;

}

/* Main function */

int main()
{
    int n = 350;
    int option = 3;
    
    printf("Enter an integer value, followed by a number to indicate the unit. Key: 1 = Pascals, 2 = Barr, 3 = atm, 4 = Torr, 5 = mmHg\n" );
    scanf("%d %d", &n, &option);
   
    unitConvert(n, option);
    
    return 0;
}
