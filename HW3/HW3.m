
D = dlmread('measurements.dat');
deg=6;
%make sets of plots and fits for polynomial up to degree 6
%for a given model ndf =n - deg+1
for i=0:deg;
    figure;
   h1 = subplot(2,1,1);
    scatter(D(:,1),D(:,2))
    errorbar(D(:,1),D(:,2),D(:,3),'.k');
    hold on
    %get paramaters and estimates from model
    [B,Berr, Yhat] = polyWLS(D(:,1),D(:,2),D(:,3),i);
    %compute chisq and p value
    ChisqVec =( (D(:,2)-Yhat)./(D(:,3)) ).^2 ;
    Chisq = sum(ChisqVec,1);
    ndf = size(D,1)-(i+1);
    pValue = 1- integral(@(p)chisqpdf(p,ndf),0,Chisq);
  
    plot(D(:,1), Yhat );
     text(min(D(:,1)),max(D(:,2)),['$\chi^{2}$ = ',num2str(Chisq)],'interpreter','latex');
     text(min(D(:,1)),max(D(:,2))-0.05, [ 'pValue =' , num2str(pValue)],'interpreter','latex'); 
     text(max(D(:,1)),min(D(:,2)), ['N =',num2str(size(D,1)) ],'interpreter','latex' );
     text(max(D(:,1)),min(D(:,2))-0.05, [ '$\nu$ =' , num2str(size(D,1)-(i+1)) ],'interpreter','latex');
    title(['Data Fit with Polynomial of Degree ', num2str(i)])
    xlabel('X');
    ylabel('Y');
    h2 = subplot(2,1,2);
    hist(ChisqVec,25);
    ylabel('Events Per Bin');
    xlabel('$\chi^{2}$ Value','interpreter','latex');
    title('$\chi^{2}$ histogram','interpreter','latex');
    
    % report paramters and error matrix, but trim padding
    B = B(1:i+1,:)
    Berr = Berr(1:i+1,:)
end
