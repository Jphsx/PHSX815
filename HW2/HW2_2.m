
%Monte Carlo script

%100 indepented integrations with N = 10000
N = 10000;
r = 1.0;
runs = 100;

Allpoints = cell(1000000,3); % all the points generated from every run
MCpoints = cell(10000,3); %all the points from a run

Allnumhits = cell(runs,1);% and the number of hits from every run

MChits = [];% all the hits from a run
Allhitpoints = cell(10000,3);%matrix of # of hits for every run

for i = 1:runs
    rng(i);
    hits = 0;
    for j = 1:N
        xyz = rand(1,3);
        if j == 1
            MCpoints = xyz;
        else 
            MCpoints = [MCpoints; xyz];
        end
        if r^2 >=  sum(xyz.^2,2)
            if hits == 0
                MChits = xyz;
            else
                MChits = [MChits; xyz];
            end
            hits= hits + 1;
            
            
        end  
    end
        if i == 1
           Allpoints=MCpoints;
           Allhitpoints=MChits;
           MChits = [];
           MCpoints = [];
            Allnumhits = hits;
            hits = 0;

        else
            Allpoints=[Allpoints;MCpoints];
            Allhitpoints=[Allhitpoints;MChits];
            MChits = [];
            MCpoints=[];
            Allnumhits = [Allnumhits; hits];
            hits = 0;
        end 
    
end
 
    for i = 1:runs
        %montecarlo gives volume of quarter of a sphere since 0<xyz<1
        %multiply by 8, quarter volume *4 gives top hemisphere of volume,
        %then double to get total volume
        V(i,1) = (Allnumhits(i,1)/N)*4*2;
    end
    %quarter volume at R=1 means pi = 3/4*V
    PI = (V.*0.75);
    %hit and miss sigma is Ve*sqrt(Nh - Nh^2/N)/N
    PIsigma = (8* ((Allnumhits - (Allnumhits.^2)/N).^(1/2))/N );
    %error propogation
    startindex=1;
    endindex=N;
    sigmaXYZ = [];
    Cxy = [];
    Cxz = [];
    Cyz = [];
    for i = 1:runs
        if i == 1
            sigmaXYZ = std(Allpoints(startindex:endindex,:),0,1);
            Cxy = cov(Allpoints(startindex:endindex,1),Allpoints(startindex:endindex,2));
            Cxz = cov(Allpoints(startindex:endindex,1),Allpoints(startindex:endindex,3));
            Cyz = cov(Allpoints(startindex:endindex,2),Allpoints(startindex:endindex,3));
        else
           sigmaXYZ = [sigmaXYZ; std(Allpoints(startindex:endindex,:),0,1)];
            Cxy = [Cxy; cov(Allpoints(startindex:endindex,1),Allpoints(startindex:endindex,2))];
            Cxz = [Cxz; cov(Allpoints(startindex:endindex,1),Allpoints(startindex:endindex,3))];
            Cyz = [Cyz; cov(Allpoints(startindex:endindex,2),Allpoints(startindex:endindex,3))];
        end
            
        startindex = endindex;
        endindex = endindex + N;
    end
    
    %report to screen final value of PI+/- sigma
    %average over PIs for mean and total differential for sigma
    pi = mean(PI,1)
    pi_sigma = (1/runs)* sqrt(sum(PIsigma.^2,1))
    
    %begin plotting of data
    %hists of x,y,z generated points
 subplot(2,3,1)
 histogram(Allpoints(:,1),20)
 xlabel('0<x<1')
 ylabel('Events Per Bin')

 subplot(2,3,2)
 histogram(Allpoints(:,2),20)
  xlabel('0<y<1')
 ylabel('Events Per Bin')
 title(['All generated XYZ values for 100 N = 10000 runs';''])
 subplot(2,3,3)
 histogram(Allpoints(:,3),20)
  xlabel('0<z<1')
 ylabel('Events Per Bin')
 
 subplot(2,3,4)
 histogram(Allhitpoints(:,1),20)
  xlabel('0<x<1')
 ylabel('Events Per Bin')

 subplot(2,3,5)
 histogram(Allhitpoints(:,2),20)
  xlabel('0<y<1')
 ylabel('Events Per Bin')
  title(['All XYZ Hits for 100 N = 10000 runs';''])
 subplot(2,3,6)
 histogram(Allhitpoints(:,3),20)
  xlabel('0<z<1')
 ylabel('Events Per Bin')

 
 
 figure()
 subplot(2,2,1)
 histogram(sum(Allhitpoints.^2,2).^(1/2),20)
  xlabel('0<r<1')
 ylabel('Events Per Bin')
 title('$ r=\sqrt{x^2 + y^2 + z^2}$','interpreter','latex')
 subplot(2,2,2)
 scatter3(Allhitpoints(:,1),Allhitpoints(:,2),Allhitpoints(:,3),'.')
 xlabel('x')
 ylabel('y')
 zlabel('z')
 title('All xyz hits')
 
 subplot(2,2,3)
 histogram(PI,19);
 xlabel('$\pi$','interpreter','latex')
 ylabel('Events per Bin')
 title('MC $\pi$ values','interpreter','latex')
 subplot(2,2,4)
 histogram(PIsigma,19);
 xlabel('$\sigma_\pi$','interpreter','latex')
 ylabel('Events per Bin')
 title('Error on each MC $\pi$','interpreter','latex')
 
 figure()
 subplot(2,3,1)
 %plot points xy
 scatter(Allpoints(:,1),Allpoints(:,2),'.')
 xlabel('x')
 ylabel('y')
 title('All xy points')
 subplot(2,3,2)
 %plot points xz
 scatter(Allpoints(:,1),Allpoints(:,3),'.')
 xlabel('x')
 ylabel('z')
 title('All xz points')
 subplot(2,3,3)
 %plot points yz
 scatter(Allpoints(:,2),Allpoints(:,3),'.')
 xlabel('y')
 ylabel('z')
 title('All yz points')
 subplot(2,3,4)
 %hist of correlation coeffs from each run for xy
 histogram(Cxy(2:2:end,1)./(sigmaXYZ(:,1).*sigmaXYZ(:,2)),20);
 xlabel('$\rho_{xy}$','interpreter','latex')
 ylabel('Events per bin')

 subplot(2,3,5)
 %hist of correlation coeffs from each run for xz
 histogram(Cxz(2:2:end,1)./(sigmaXYZ(:,1).*sigmaXYZ(:,3)),20);
 xlabel('$\rho_{xz}$','interpreter','latex')
 ylabel('Events per bin')
  title('Correlation Coefficients of (x,y),(x,z),(y,z)')
 
 subplot(2,3,6)
 %hist of correlation coeffs from each run for yz
 histogram(Cyz(2:2:end,1)./(sigmaXYZ(:,2).*sigmaXYZ(:,3)),20);
 xlabel('$\rho_{yz}$','interpreter','latex')
 ylabel('Events per bin')

 

 
 