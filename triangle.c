/* triangle.c

   Obtains the dimensions and angles of a right triangle.
*/ 

#include <stdio.h>
#include <math.h>

int main(void); 
int triangle(void);

int main(void)
     {
        double sideA, sideB, sideC, anga, angb, tempC;
        double pi = fabs(acos(-1.));
        double torads = pi/180.;
        double todegs = 180./pi;
        double angc = 90.;

        printf("Using the following conventions for sides and angles:\n");
        triangle();
        printf("\nEnter all known information:\n");
        printf("\tA = ");
        scanf("%lf", &sideA);
        printf("\tB = ");
        scanf("%lf", &sideB);
        printf("\tC = ");
        scanf("%lf", &sideC);
        printf("\tAngle a = ");
        scanf("%lf", &anga);
        printf("\tAngle b = ");
        scanf("%lf", &angb);
        if(sideA && sideB && sideC) {
             tempC = sqrt(pow(sideA, 2.) + pow(sideB, 2.));
             if(fabs(sideC - tempC) > 0.001) {
                  printf("Sides invalid.\n");
                  return(1);
             }
             anga = acos(sideB/sideC) * todegs;
             angb = 90. - anga;
        } else if(sideA && sideB) {
             sideC = sqrt(pow(sideA, 2.) + pow(sideB, 2.));
             anga = acos(sideB/sideC) * todegs;
             angb = 90. - anga;
        } else if(sideB && sideC) {
             sideA = sqrt(pow(sideC, 2.) - pow(sideB, 2.));
             anga = acos(sideB/sideC) * todegs;
             angb = 90. - anga;
        } else if(sideA && sideC) {
             sideB = sqrt(pow(sideC, 2.) - pow(sideA, 2.));
             anga = acos(sideB/sideC) * todegs;
             angb = 90. - anga;
        } else if(sideA) {
             if(anga && angb) {
                  sideC = sideA/cos(angb*torads);
                  sideB = sqrt(pow(sideC, 2.) - pow(sideA, 2.));
             } else if(anga) {
                  sideC = sideA/sin(anga*torads);
                  sideB = sqrt(pow(sideC, 2.) - pow(sideA, 2.));
                  angb = 90. - anga;
             } else if(angb) {
                  sideC = sideA/cos(angb*torads);
                  sideB = sqrt(pow(sideC, 2.) - pow(sideA, 2.));
                  anga = 90. - angb;
             } else {
                  printf("Insufficient information.\n");
                  return(1);
             }
        } else if(sideB) {
             if(anga && angb) {
                  sideC = sideB/sin(angb*torads);
                  sideA = sqrt(pow(sideC, 2.) - pow(sideB, 2.));
             } else if(anga) {
                  sideC = sideB/cos(anga*torads);
                  sideA = sqrt(pow(sideC, 2.) - pow(sideB, 2.));
                  angb = 90. - anga;
             } else if(angb) {
                  sideC = sideB/sin(angb*torads);
                  sideA = sqrt(pow(sideC, 2.) - pow(sideB, 2.));
                  anga = 90. - angb;
             } else {
                  printf("Insufficient information.\n");
                  return(1);
             }
        } else if(sideC) {
             if(anga && angb) {
                  sideA = sideC * cos(angb*torads);
                  sideB = sideC * sin(angb*torads);
             } else if(anga) {
                  sideA = sideC * sin(anga*torads);
                  sideB = sideC * cos(anga*torads);
                  angb = 90. - anga;
             } else if(angb) {
                  sideA = sideC * cos(angb*torads);
                  sideB = sideC * sin(angb*torads);
                  anga = 90. - angb;
             } else {
                  printf("Insufficient information.\n");
                  return(1);
             }
        } else {
             printf("Insufficient information.\n");
             return(1);
        }

        printf("\n\tSide A = %.2f\t\tAngle a = %.2f degrees\n", sideA, anga);
        printf("\tSide B = %.2f\t\tAngle b = %.2f degrees\n", sideB, angb);
        printf("\tSide C = %.2f\n", sideC);
     }
     
    
int triangle(void)
     {
        FILE *tri;
        char line[50];

        tri = fopen("triangle", "r");
        if(tri == NULL) 
          {
          printf("Cannot open triangle file.\n");
          return(1);
          }
        while(fgets(line, 50, tri) != NULL)
             fputs(line, stdout);
        fclose(tri);
     return(0);
     }
