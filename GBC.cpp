#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

void askOTTV();
void askInsulationThickness();
void askVentilationRate();
void askInsulationOfSteam();
void askIlluminance();
void askIlluminancePtByPt();
void askCostOfLight();

double solveOTTV(double Aw, double Uw, double TDeq, double Af, double Uf, double deltaT, double SC, double SF, double Ao);
double solveInsulationThickness(double k, double Rs, double Dp, double To, double Db);
double solveVentilationRate(double qs, double p, double Cp, double T);
double solveInsulationOfSteam(double r1, double r2, double t1, double t2, double d0);
double solveIlluminance(double phi, double CU, double LLF, double Awp);
double solveIlluminancePtByPt(double cd, double theta, double D);
double solveCostOfLight(double Q, double P, double h, double L, double W, double R); 

int main(void){
    system("cls");
     
    int n;
    
    printf("1- OTTV\n2- Insulation Thickness\n3- Ventilation Rate\n4- Insulation of Steam\n5- Illuminance\n6- Illuminance (Point by Point Method)\n7- Cost of Light\n\n");
    scanf("%d", &n);
    
    switch (n){
           case(1): askOTTV(); 
                    break;
           case(2): askInsulationThickness(); 
                    break;
           case(3): askVentilationRate();
                    break;
           case(4): askInsulationOfSteam();
                    break;                           
           case(5): askIlluminance();
                    break;
           case(6): askIlluminancePtByPt();
                    break;
           case(7): askCostOfLight();         
    }
    
    
    getch();
    return 0;

}

//////////////////////////////ASK//////////////////////////////////

void askOTTV(){
     system("cls"); 

     int n;
     double array[9], OTTV, numerator=0, denominator=0;
     string name;
    
     printf("This program solves for the Overall Thermal Transfer Value (W/m^2)\n\n");
     printf("Enter the number of walls: ");
     scanf("%d", &n);
    
    
     for(int j=0; j<n; j++){
            
            printf("\n\nWALL %d\n\n", j+1);
            
            for(int i=0; i<9; i++){
                switch (i){
                       case(0): name="Opaque Wall Area (m^2)"; 
                                break;                           
                       case(1): name="Thermal Transmittance (W/m^2 K)";
                                break;
                       case(2): name="Equivalent Temperature Difference (K)"; 
                                break;
                       case(3): name="Fenestration Area (m^2)"; 
                                break;
                       case(4): name="Thermal Transmittance of Fenestration (m^2)"; 
                                break;
                       case(5): name="Temperature Difference between Exterior and Interior"; 
                                break;
                       case(6): name="Shading Coefficient of Fenestration"; 
                                break;
                       case(7): name="Solar Factor (W/m^2)"; 
                                break;
                       case(8): name="Gross Area of Exterior Wall (m^2)"; 
                                break;
                }
                       
                cout << name << ": ";    
                scanf("%lf", &array[i]);
                
                }
        
        OTTV= solveOTTV(array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8]);        
        printf("\nThe OTTV of wall %d is %lf W/m^2.", j+1, OTTV);
        
        numerator += (array[8]*OTTV);
        denominator += array[8];    
     }
    
     OTTV= numerator/denominator;
    
     printf("\nThe OTTV of the building is %lf W/m^2.", OTTV);
    
     getch();
     main();

}

void askInsulationThickness(){
     system("cls"); 
     
     double array[5], InsulationThickness;
     string name;
    
     printf("This program solves for the Insulation Thickness\n\n");
                
     for(int i=0; i<5; i++){
            switch (i){
                   case(0): name="Mean Thermal Conductivity (W-mm/sq.m C)"; 
                                break;                           
                   case(1): name="Surface Thermal Resistance (0.115 sq.m C/W-mm)";
                                break;
                   case(2): name="Dew Point (C)"; 
                                break;
                   case(3): name="Operating Temperature (C)"; 
                                break;
                   case(4): name="Ambient Still Air-dry Bulb Temperature (C)"; 
                                break;
            
            }
                       
            cout << name << ": ";    
            scanf("%lf", &array[i]);
     }
        
     InsulationThickness= solveInsulationThickness(array[0], array[1], array[2], array[3], array[4]);       
     printf("\nThe required insulation thickness is %lf", InsulationThickness);

    
     getch();
     main();
     
}

void askVentilationRate(){
     system("cls"); 
     
     double array[4], VentilationRate;
     string name;
    
     printf("This program solves for the Ventilation Rate\n\n");
                
     for(int i=0; i<4; i++){
            switch (i){
                   case(0): name="Sensible Heat Gains (W)"; 
                                break;                           
                   case(1): name="Air Density (~1.2 kg/m^3)";
                                break;
                   case(2): name="Specific Heat of Air (~1000 J/Kg-K)"; 
                                break;
                   case(3): name="Total Temperature Rise of Incoming Air (k)"; 
                                break;            
            }
                       
            cout << name << ": ";    
            scanf("%lf", &array[i]);
     }
        
     VentilationRate= solveVentilationRate(array[0], array[1], array[2], array[3]);       
     printf("\nThe required ventilation rate is %lf", VentilationRate);

    
     getch();
     main();
     
}

void askInsulationOfSteam(){
     system("cls"); 
     
     double array[5], InsulationOfSteam;
     string name;
    
     printf("This program solves for the insulation of steam\n\n");
                
     for(int i=0; i<5; i++){
            switch (i){
                   case(0): name="T1= Minimum Insulation Thickness of Material (mm)"; 
                                break;                           
                   case(1): name="T2= Minimum Insulation Thickness of Material (mm)";
                                break;
                   case(2): name="R1= Thermal Resistivity (m^2 -C/W-mm)"; 
                                break;
                   case(3): name="R2= Thermal Resistivity (m^2 -C/W-mm)"; 
                                break;
                   case(4): name="Outside Pipe Diameter (m)"; 
                                break;             
            }
                       
            cout << name << ": ";    
            scanf("%lf", &array[i]);
     }
        
     InsulationOfSteam= solveInsulationOfSteam(array[0], array[1], array[2], array[3], array[4]);       
     printf("\nThe required insulation of steam is %lf", InsulationOfSteam);

    
     getch();
     main();
}

void askIlluminance(){
     system("cls"); 
     
     double array[4], Illuminance;
     string name;
    
     printf("This program solves for the illuminance\n\n");
                
     for(int i=0; i<4; i++){
            switch (i){
                   case(0): name="Total System Lamp Lumen Output (lm)"; 
                                break;                           
                   case(1): name="Coefficient of Utilization";
                                break;
                   case(2): name="Light Loss Factor"; 
                                break;
                   case(3): name="Area of the Work Plane (m^2)"; 
                                break;             
            }
                       
            cout << name << ": ";    
            scanf("%lf", &array[i]);
     }
        
     Illuminance= solveIlluminance(array[0], array[1], array[2], array[3]);       
     printf("\nThe illuminance is %lf lux", Illuminance);

    
     getch();
     main();
}

void askIlluminancePtByPt(){
     system("cls"); 

     int n;
     double array[3], Illuminance, sum=0;
     string name;
    
     printf("This program solves for the illuminance for multiple luminaires\n\n");
     printf("Enter the number of luminaires: ");
     scanf("%d", &n);
    
    
     for(int j=0; j<n; j++){
            
            printf("\n\nLuminaire %d\n\n", j+1);
            
            for(int i=0; i<3; i++){
                switch (i){
                       case(0): name="Luminous Intensity (candela)"; 
                                break;                           
                       case(1): name="Angle of Light from the Vertical (degrees)";
                                break;
                       case(2): name="Distance of Light Source to Point"; 
                                break;
                }
                       
                cout << name << ": ";    
                scanf("%lf", &array[i]);
                
                }
        
        Illuminance= solveIlluminancePtByPt(array[0], array[1], array[2]);        
        printf("\nThe illuminance at the point due to luminaire %d is %lf lux.", j+1, Illuminance);
        
        sum += Illuminance;    
     }
    
     printf("\nThe total illuminance at the point is %lf lux.", sum);
    
     getch();
     main();

}

void askCostOfLight(){
     system("cls"); 
     
     double array[6], CostOfLight;
     string name;
    
     printf("This program solves for the cost of light.\n\n");
                
     for(int i=0; i<6; i++){
            switch (i){
                   case(0): name="Mean Lamp Flux (thousand lumens)"; 
                                break;                           
                   case(1): name="Lamp Price (pesos)";
                                break;
                   case(2): name="Labor Cost to Replace One Lamp (pesos)"; 
                                break;
                   case(3): name="Average Rated Lamp Life (thousand of hours)"; 
                                break;
                   case(4): name="Mean Input Power per Lamp (watts)"; 
                                break;         
                   case(5): name="Energy Cost (pesos/kilowatt-hour)"; 
                                break;    
            }
                       
            cout << name << ": ";    
            scanf("%lf", &array[i]);
     }
        
     CostOfLight= solveCostOfLight(array[0], array[1], array[2], array[3], array[4], array[5]);       
     printf("\nThe cost of light is %lf pesos per million lumen-hours", CostOfLight);

    
     getch();
     main();
}

///////////////////////////SOLVE//////////////////////////

double solveOTTV(double Aw, double Uw, double TDeq, double Af, double Uf, double deltaT, double SC, double SF, double Ao){
       
       return (( Aw * Uw * TDeq ) + ( Af * Uf * deltaT ) + ( Af * SC * SF )) / Ao;       
}

double solveInsulationThickness(double k, double Rs, double Dp, double To, double Db){
       
       return ( k * Rs * (Dp - To)) / (Db - Dp);       
}

double solveVentilationRate(double qs, double p, double Cp, double T){
       
       return qs / (p * Cp * (T));
}

double solveInsulationOfSteam(double r1, double r2, double t1, double t2, double d0){
       
       return 50.8 * d0 * (((1 + 2 * (t1 / d0)) * exp(r2 / r1)) - 1);
} 

double solveIlluminance(double phi, double CU, double LLF, double Awp){

       return (phi * CU * LLF) / Awp;       
} 

double solveIlluminancePtByPt(double cd, double theta, double D){
       
       return (cd * cos(theta*3.14159/180)) / pow(D, 2);      
}

double solveCostOfLight(double Q, double P, double h, double L, double W, double R){
       
       return (1.0/Q) * (((P + h)/L) + (W * R));       
}  
    

