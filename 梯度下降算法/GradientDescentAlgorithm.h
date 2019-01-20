/****** Gradient Descent Algorithm********/

/****************************************** /
	  author:Chen Lei
	  date  :2017/10/26
	  thanksTo:Andrew Ng
	  description:  This is  for linear regression
	  
	  Hypothesis:h(x) = a + bx
	  Parameters:a,b
	  cost function:J(a,b) = 1/2m * sub(f(x1)+f(x2)+..+f(xm))  f(xi)=(h(xi) -yi)^2 , i=1,...,m
	  Goal:minimize J(a,b)
	        (a,b)
	  
	  gradient descent algorthm(a and b must simultaneous update):
	    a = a - k * d(J(a,b))/d(a)   d:derivative
		b = b - k * d(J(a,b))/d(b)   d:derivative
***********************************************/

#include<cmath>

void GradientDescForLinear(double& a, double& b, int m, double k, double* dataSet)   //dataSet[] = {x1,y1,x2,y2.....,xm,ym}
{
	
	if (dataSet == NULL || m == 0) return;
	
	double fTempA = a;
	double fTempB = b;
	
	while(1)
	{
		double derivativeSumA = 0;
		double derivativeSumB = 0;
		for(int i = 0; i < 2*m; i+2)
		{
			double h = fTempA+fTempB*dataSet[i] - dataSet[i+1]; 
			derivativeSumA = derivativeSumA + h;
			derivativeSumB = derivativeSumB + h*dataSet[i];
		}
		double derivativeA = derivativeSumA/m;
		double derivativeB = derivativeSumB/m;
		
		if (fabs(derivativeA) < 0.0000001 && fabs(derivativeB) < 0.0000001) break;
		
		fTempA = fTempA - k*derivativeA;
		fTempB = fTempB - k*derivativeB;
	}
	
	a = fTempA;
	b = fTempB;	
}