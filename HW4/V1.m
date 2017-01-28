%assume 
function v = V1(x)
hbar =1;
m = 1/2;
alpha = 2;
lamda = 10.5;
v = -(1/(2*m))*(hbar)^2 *alpha^2 *lamda*(lamda-1)./(cosh(alpha.*x)).^2;
end