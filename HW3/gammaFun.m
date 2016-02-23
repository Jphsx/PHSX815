%computes half integer gamma function values, (n/2)
%only n value should be passed in
function L = gammaFun(n)
%L = sqrt(pi)* factorial(factorial(n-2))/( 2^((n-1)/2 ) );
L = sqrt(pi)* dubFactorial(n-2)/( 2^((n-1)/2 ) );
end