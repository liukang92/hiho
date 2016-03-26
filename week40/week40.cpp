#include <cstdio>
#include <cmath>

using namespace std;

const double MAX = 400;
const double EPS = 0.0001;

double dis(double x1, double y1, double x2, double y2){
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double f(double a, double b, double c, double x){
	return a * x * x + b * x + c;
}

double solve(double a, double b, double c, double x, double y){
	double mid = -b / 2 / a;
	double left, right, gap, mid1, mid2;
	if(x > mid){
		left = mid;
		right = MAX;
	}else{
		left = -MAX;
		right = mid;
	}
	while(left < right - EPS){
		gap = (right - left) / 3;
		mid1 = left + gap;
		mid2 = mid1 + gap;
		if(dis(x, y, mid1, f(a, b, c, mid1)) > dis(x, y, mid2, f(a, b, c, mid2))){
			left = mid1;
		}else{
			right = mid2;
		}
	}
	return dis(x, y, left, f(a, b, c, left)); 
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
	double a, b, c, x, y; 
    scanf("%lf %lf %lf %lf %lf",&a, &b, &c, &x, &y);
    printf("%.3lf\n", solve(a, b, c, x, y));
    return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
