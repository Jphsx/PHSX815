

%intital parameters
L=25;
dx=.1;
m=1/2;
hbar=1;

%set up hamiltonian and 2nd order central finite difference banded matrix
for x= -L:dx:L
   if x == -L
       H = (hbar^2 *2/(2*m*dx^2)) + V1(x);
   else
       H = [H; (hbar^2 /(2*m*dx^2)) + V1(x)];
   end
end
 H = diag(H);
 s1 = diag((-hbar^2 /(2*m*dx^2))*ones(1,2*L/dx),1);
 s2 = diag((-hbar^2 /(2*m*dx^2))*ones(1,2*L/dx),-1);
 A = H + s1 + s2;
%s1 = (-hbar^2 /(2*m*dx^2))*ones(1,2*L/dx);
%s2 = (-hbar^2 /(2*m*dx^2))*ones(1,2*L/dx);
%A = gallery('tridiag',s1,H,s2);

%Collect the analytical 0-ith bound state energies
for n= 0:3
    En(n+1) = Energy(n);
end
%use analytical values to sort out the junk eigen energies
 [Psi,E] = eig(A);
  E=diag(E);
 % normalize the eigenvectors and eigenvalues
  X = -L:dx:L;
  for i = 1:size(Psi,2);
  Area(i)=trapz(X,Psi(:,i).^2);
  NormCoeff(i) = 1/(Area(i));
 % E(i) = E(i)/NormCoeff(i);
  end
  %iterate through E find the values that best match the analytical values
  %the eigen value row corresponds to the column of the eigenvector matrix
 %Psi
 %initilaze column vector that stores psi indices for plotting
 size(En,2)
 for i = 1:size(En,2)
     %initialize differences to -1
    columns(i)=1; 
 end
 %selecting the best matching Eigenenergies to the analytical values, and
 %storing the Psi index of the corresponding eigenvector
 for i = 1:size(En,2)
    for j = 1:size(E,1)
        diff = abs( En(i) - E(j));
        if ( diff < abs(En(i) - E(columns(i))) )
            columns(i) = j;
        end
    end
 end
 %plot the best normalized eigenvectors 
 for i = 1:size(En,2)
    plot(X, NormCoeff(columns(i)).*Psi(:,columns(i)))
    hold on
 end
 hold off
 %print eigen energies
 for i = 1:size(En,2)
    AnalyticEnergy = En(i)
    EigenEnergy = E(columns(i))
    Error = abs(AnalyticEnergy - EigenEnergy)
 end

 %tests for eigenvectors (linsolve cant solve this system)
% RHS = zeros(size(A,1),1);
%linsys = A-En(2).*diag(ones(1,size(A,1)));
% vector0 = linsolve(linsys,RHS);
 
 figure;
hold on
 plot(X,Psi(:,1))
 plot(X,Psi(:,2))
 plot(X,Psi(:,3))
 plot(X,Psi(:,4))
 
 %calculate <x^2>
 ex2 = trapz(X,NormCoeff(1)* (X.^2)' .*Psi(:,1).^2)
 ex2 = trapz(X,NormCoeff(2)* (X.^2)' .*Psi(:,2).^2)
 ex2 = trapz(X,NormCoeff(3)* (X.^2)' .*Psi(:,3).^2)
 ex2 = trapz(X,NormCoeff(4)* (X.^2)' .*Psi(:,4).^2)
 
 %try to get correct eigen energies from the good eigen vectors
 A*Psi(:,1)

