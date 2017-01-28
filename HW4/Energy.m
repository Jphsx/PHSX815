function en = Energy(n)
hbar =1;
m = 1/2;
alpha = 1;
lamda = 4;
en = -(1/(2*m))*hbar^2 *alpha^2 *(lamda - 1 - n)^2;
end