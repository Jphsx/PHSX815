%computes half integer gamma function values, (n/2)
%only n value should be passed in
function L = gammaFun(n)
%L = sqrt(pi)* factorial(factorial(n-2))/( 2^((n-1)/2 ) );
if(mod(n,2) ~= 0 && n~=0)
    L = sqrt(pi)* dubFactorial(n-2)/( 2^((n-1)/2 ) );
else
    L = factorial(n/2 -1);
end