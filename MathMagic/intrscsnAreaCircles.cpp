#include<iostream>
#include<math.h>
#define pi 3.141592
#include<cmath>
#include<iomanip>

using namespace std;
int main(){
    
    int t;
    
    cin>>t;
    
    while(t--){
        
        long double x1, y1, r1, x2, y2, r2;
        
        std::cin>>x1>>y1>>r1>>x2>>y2>>r2;
        
        long double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        
        long double ans = 0;
        
        //cae 1 / if no meeting point
        if(d>(r1+r2)){
            ans = 0;
        }//case 2 / if one circle totally inside the other circle
        else if(d<=abs(r1-r2)){
            long double r = min(r1, r2);
            ans = pi*r*r;
        }//case 3 /exterior circle intersection
        else{
            long double d1 = ((r1)*(r1) - (r2)*(r2) + (d)*(d))/(2*d);
            long double d2 = d - d1;
            
            long double phi = acos(d1/r1);
            long double theta = acos(d2/r2);
            
            ans = (r1*r1)*phi + (r2*r2)*theta - d1*sqrt(r1*r1 - d1*d1) - d2*sqrt(r2*r2 - d2*d2);
        }
        
        cout<<fixed<<setprecision(6)<<ans<<"\n";
        
    }
    
    return 0;
}
