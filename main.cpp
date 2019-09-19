#include <iostream>
#include <cmath>

// Name / student number : Tomas Vosylius / 1042957

using namespace std; // Not the best practice and shouldn't be used

void inclusion(double e, double v)
{
    double
        a = 0.0, // First number in pair
        b = max(1.0, v), // Second number in pair
        x = (a + b / 2); // Average root of v
    int
        i = 0;

    while(abs(x * x - v) > e)
    {
        // We loop over i, but the condition is given in.
        // var i will only show us how many loops were done

        // If the loop meets condition abs(x*x-v) <= e, we are done.
        // So we are doing this loop when abs(x * x - v) > e
        if((a * a) == v)
        {
            cout << "Root of " << v << " is " << a << endl;
            return; // Since this is void function we cannot return any value
        }
        else if((b * b) == v)
        {
            cout << "Root of " << v << " is " << b << endl;
            return;
        }
        else
        {
            // We first have to print out a, b, x values and which loop iteration i is happening as asked
            cout << i << "\t" << a << "\t" << x << "\t" << b << "\t" << endl;
            // And then calculate new x based on two conditions.
            if(x * x < v)
            {
                a = x;
            }
            else
            {
                b = x;
            }
        }
        x = (a + b) / 2; // Each time we look for new x value
        i ++ ;
    }
    cout << "Inclusion square root of " << v << " is " << x << " for epsilon " << e << endl;
}

void newton_raphson(double e, double v)
{
    double
        Xa = max(1.0, v), // This is X[0], later it'll become X[i-1]
        // Calculate initial X[i] formula. Since it is X[i] = X[i-1]-f(X[i]) / f'((X[i]), we can use Xa instead of X[i] and Xb in X[i + 1]
        // X[i+1] = X[i] – f(X[i]) / f’(X[i])
        // f = X[i]*X[i] - v
        Xb = Xa - ((Xa*Xa-v) / (2*Xa)); // We could also name Xb as X[i]
    int
        i = 0;
    while(abs(Xb*Xb - v) > e)
    {
        // Loop will continue if abs(X[0]*X[0]-v) <= e, just like in 1.2
        // Otherwise, we are done
        cout << i << "\t" << Xa << "\t" << Xb << endl;

        Xa = Xb; // Assign X[i] value to X[i-1]
        Xb = Xa - ((Xa*Xa-v) / (2*Xa)); // Recalculate new X[0] value

        i ++ ;
    }
    cout << "newton_raphson square root of " << v << " is " << Xb << " for epsilon " << e << endl;
}

int main()
{


    return 0;
}
