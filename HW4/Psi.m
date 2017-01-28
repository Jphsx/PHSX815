
%returns gaussian wave packet from example
function p = Psi(x)
 x0=0.4;
 k0=250;
 s2=0.001;
 p = exp(-(x-x0)^2 /s2 )*exp(i*k0*x); 

%regular wave function
%p=sin(x);
end