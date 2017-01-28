data = dlmread('measurements2.dat')
hold on;
errorbar(data(:,1),data(:,2),data(:,3),'.k')

%checks for fit from c++ run
Vo = 3.14139;
A = 0.119546;
w = 9.54645;
phi = 9.21187;

y = Vo + A*sin(w*data(:,1) - phi);

plot(data(:,1),y);
title('Data with nonlinear fit');
