#include "TMath.h"


const int n = 10000;  //number of times to run the simulation
float momentum = 10; //in GeV
float field = 3; //in T
float maxRadius = 1.5; //in m
const int layers = 12; //layers in the tracker
float charge = 1; //in e


//Calculate the line of best fit of a x-y relation, using the minimization of squares method
float * lineOfBestFit(float x[], float y[], float size){
    float sumX = 0;
    float sumY = 0;
    for(int i = 0; i < size; i++){
        sumX += x[i];
        sumY += y[i];
    }

    float avgX = sumX/size;
    float avgY = sumY/size;
    

    
    float numerator = 0; //of slope calculation
    float demoninator = 0; //of slope calculation
    for(int i = 0; i < size; i++){
        numerator+=(x[i]-avgX)*(y[i]-avgY);
        demoninator+=pow((x[i]-avgX),2);
    }
    
    static float line[2];
    line[0]=numerator/demoninator; //slope
    line[1]=avgY-line[0]*avgX; //y intercept
    
    
    return line;
}

/*
 * Here is what is going down in each iteration of the simulation:
 * 1) Calculate the actual radius of the particle's path (pT = .3qrB)
 * 2) Generate a and b, the coordinates of the center of the circle, pseudo-randomly s.t. a^2+b^2 = r^2, where r is the radius
 * of the particle's path
 * 3) Now, at each layer of the tracker:
 *      a) Calculate the intersection of the circle representing the layer and the circle of the particle's actual path
 *      b) Convert those x-y coordinates to r-phi coordinates
 *      c) Smear phi up to 10 micrometers in the direction orthogonal to the radial segment to the origin
 *      d) Convert back to x-y (these are the measured x-y coordinates)
 *      e) Add the u-v coordinates to an array (linearization of the circle)
 * 4) Fit the u-v coordinates to generate the equation of the measured circle
 * 5) Calculate the measured radius of the particle's path based on this equation (a^2+b^2 = r^2)
 * 6) Compute and plot the measured momentum/energy of the particle (pT = .3qrB)

 */

void trackMC(){
    
    //Set up the display
    TCanvas *c1 = new TCanvas("c1","Tracker Simulation",200,10,700,500);

    
    c1->SetFillColor(42);
    
    TH1F *histo1  = new TH1F("histo1","Measured Energies",100,0.,momentum*2);
    histo1->SetMarkerStyle(21);
    
    //Set up random number generation
    TRandom ran;
    gRandom->SetSeed();
    

    //Compute the actual radius of the particle's path (pT = .3qrB)
    float radiusActual = momentum/(.3*charge*field);
    
    //cout << endl;
    //cout << "Radius of curvature:" << radiusActual << endl;
    
    
    for(int i = 0; i < n; i++){
        //randomly generate a and b such that a^2 + b^2 = r^2, where r is the radius of curvature of the particle
        //for simplicity, a and b lie in the first quadrant
        float a = ran.Uniform(0,radiusActual);
        float b = sqrt(pow(radiusActual,2)-pow(a,2));
                
        //u-v coordinates to be later used for tracking
        float u[layers*2];
        float v[layers*2];

        //cout << "Equation of circle: " << "(x-" << a << ")^2 + (y-" << b << ")^2 = "<< a*a+b*b << endl;
        //cout << endl;
        
        
        //take measurements at each layer
        for(int j = 1; j <= layers; j++){
            float r = maxRadius/layers*j; //current radius
            
            //A, B, and C for quadratic equation Ax^2+Bx+C = 0, used to determine intersection of the circle
            //representing the current radius (x^2+y^2 = r^2) and the circle (x-a)^2+(y-b)^2=a^2+b^2;
            float qA = 1+pow(a,2)/pow(b,2);
            float qB = -a*pow(r,2)/pow(b,2);
            float qC = pow(r,2)*(pow(r,2)/(4*pow(b,2))-1);
            float x1 = (-qB+sqrt(pow(qB,2)-4*qA*qC))/(2*qA); //The x coordinate of the intersection (the greater one)
            float x2 = (-qB-sqrt(pow(qB,2)-4*qA*qC))/(2*qA); //The x coordinate of the intersection (the lesser one)

            float y1 = -a/b*x1+pow(r,2)/(2*b); //The y-coordinate coresponding to the greater x coordinate (x1)
            float y2 = -a/b*x2+pow(r,2)/(2*b); //The y-coordinate coresponding to the lesser x coordinate (x2)
            
            //cout << "R: " << r << endl;
            //cout << "X1: " << x1 << endl;
            //cout << "Y1: " << y1 << endl;
            //cout << "X2: " << x2 << endl;
            //cout << "Y2: " << y2 << endl;

            //cout << "Radius of X1, Y1: " << sqrt((x1-a)*(x1-a)+(y1-b)*(y1-b)) << endl;
            //cout << "Radius of X2, Y2: " << sqrt((x2-a)*(x2-a)+(y2-b)*(y2-b)) << endl;

            
            
            //Compute r-phi coordinates
            float phi1, phi2;
            if(x1 > 0){
                phi1 = atan(y1/x1);
            }
            if(x1 < 0){
                phi1 = atan(y1/x1)+TMath::Pi();   
            }
            if(x2 > 0){
                phi2 = atan(y2/x2);
            }
            if(x2 < 0){
                phi2 = atan(y2/x2)+TMath::Pi();   
            }
            
            
            //smear the coordinates of x1-y1
            float epsilon = 10*pow(10,-4); //error in measurement perpendicular to the radial segment
            float Ephimax = atan(epsilon/r); //maximum error in phi
            
            //"smear" the phi value pseudo-randomly according to a gaussian distribution
            float efactor = ran.Gaus(0,1);
            if(efactor > 1){
                efactor = 1;
            }
            if(efactor < -1){
                efactor = -1;
            }
            phi1 += Ephimax*efactor;
            //convert from r-phi back to x-y
            float X1m = r*cos(phi1);
            float Y1m = r*sin(phi1);
            
            //smear the coordinates of x2-y2
            efactor = ran.Gaus(0,1);
            if(efactor > 1){
                efactor = 1;
            }
            if(efactor < -1){
                efactor = -1;
            }
            phi2 += Ephimax*efactor;
            float X2m = r*cos(phi2);
            float Y2m = r*sin(phi2);
            

            
            //cout << "Measured X1: " << X1m << endl;
            //cout << "Measured Y1: " << Y1m << endl;
            //cout << "Measured X2: " << X2m << endl;
            //cout << "Measured Y2: " << Y2m << endl;
            //cout << endl;
            
            //add values to u-v array
            u[2*(j-1)] = X1m/(pow(X1m,2)+pow(Y1m,2));
            v[2*(j-1)] = Y1m/(pow(X1m,2)+pow(Y1m,2));
            
            u[2*(j-1)+1] = X2m/(pow(X2m,2)+pow(Y2m,2));
            v[2*(j-1)+1] = Y2m/(pow(X2m,2)+pow(Y2m,2));

            
  
        }
        
        //calculate a and b as measured by the tracker after fitting
        float *line = lineOfBestFit(u,v,layers);
        float slope = *(line+0);
        float yInt = *(line+1);
        float bm = 1/(2*yInt);
        float am = -slope*bm;
        //cout << "Measured a: " << am << endl;
        //cout << "Measured b: " << bm << endl;
        
        //calculate the radius measured by the tracker (a^2+b^2 = r^2)
        float rm = sqrt(pow(am,2)+pow(bm,2));
        //cout << "Measured radius: " << rm << endl;
        
        //calculate the energy measured by the tracker (p = .3qrB)
        float pm = .3*charge*field*rm;
       // cout << "Measured momentum: " << pm << endl;
        //cout << endl;
        histo1->Fill(pm);
        
    }
    
    //Fit the histogram to a gaussian distribution
    histo1->Fit("gaus");
    histo1->SetLineColor(2);
    histo1->Draw("");
    c1->Update();
    c1->SaveAs("c1.gif");
}