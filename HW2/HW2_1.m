
 D1 = dlmread('RK4.txt');
 D2 = dlmread('RK4Damp.txt');
 D3 = dlmread('Euler.txt');
 D4 = dlmread('EulerDamp.txt');
 dt = D1(:,4);
 dtlong = D4(:,4);
 %data goes theta, omega, E, dt, T, <v>, <E>
 
 %RK4 sets
 RK4_01 = D1(dt > 0.0001, :);
 RK4_0001 = D1(dt < 0.01, :);
 %RK4 damped sets
 RK4d_01 = D2(dtlong > 0.0001, :);
 RK4d_0001 = D2(dtlong < 0.01, :);
 
 %Euler sets
 Eul_01 = D3(dt > 0.0001, :);
 Eul_0001 = D3(dt < 0.01, :);
 %Euler damped sets
 Euld_01 = D4(dtlong > 0.0001, :);
 Euld_0001 = D4(dtlong < 0.01, :);
 
 
 
 %angle vs time, energy vs time, omega vs angle, E and <E> vs t
 %undamped 0.01 plots
 subplot(2,2,1)
 plot(RK4_01(:,5),RK4_01(:,1),'Color','r'); hold on
 plot(Eul_01(:,5),Eul_01(:,1),'Color','b'); 
 xlabel('time (s)')
 ylabel('$\theta$ (rads)','interpreter','latex')
 title('Angle vs time dt=.01')
 legend('RK4','Euler','Location','northwest')
 subplot(2,2,2)
 plot(RK4_01(:,5), RK4_01(:,2),'Color','r');hold on
 plot(Eul_01(:,5), Eul_01(:,2),'Color','b');
 xlabel('time (s)')
 ylabel('$\omega$ (rads/s)','interpreter','latex')
 title('Angular velocity vs time dt=.01')
 legend('RK4','Euler','Location','northwest')
 subplot(2,2,3)
 plot(RK4_01(:,2),RK4_01(:,1),'Color','r'); hold on
 plot(Eul_01(:,2),Eul_01(:,1),'Color','b');
 xlabel('$\omega$ (rads/s)','interpreter','latex')
 ylabel('$\theta$ (rads)','interpreter','latex')
 title('Phase Space')
 legend('RK4','Euler','Location','northwest')
 subplot(2,2,4)
 plot(RK4_01(:,5),RK4_01(:,3),'Color','r'); hold on
 plot(Eul_01(:,5),Eul_01(:,3),'Color','b');
 xlabel('time (s)')
 ylabel('Energy')
 title('Energy vs time dt=.01')
 legend('RK4','Euler','Location','northwest')
 

%undamped 0.0001 plots
figure();
subplot(2,2,1)
plot(RK4_0001(:,5),RK4_0001(:,1),'Color','r'); hold on
plot(Eul_0001(:,5),Eul_0001(:,1),'Color','b');
xlabel('time (s)')
 ylabel('$\theta$ (rads)','interpreter','latex')
 title('Angle vs time dt=.0001')
 legend('RK4','Euler','Location','northwest')
subplot(2,2,2)
plot(RK4_0001(:,5), RK4_0001(:,2),'Color','r');hold on
plot(Eul_0001(:,5), Eul_0001(:,2),'Color','b');
xlabel('time (s)')
 ylabel('$\omega$ (rads/s)','interpreter','latex')
 title('Angular Velocity vs time dt=.0001')
 legend('RK4','Euler','Location','northwest')
subplot(2,2,3)
plot(RK4_0001(:,2),RK4_0001(:,1),'Color','r'); hold on
plot(Eul_0001(:,2),Eul_0001(:,1),'Color','b');
xlabel('$\omega$ (rads/s)','interpreter','latex')
 ylabel('$\theta$ (rads)','interpreter','latex')
 title('Phase Space')
 legend('RK4','Euler','Location','northwest')
subplot(2,2,4)
plot(RK4_0001(:,5),RK4_0001(:,3),'Color','r'); hold on
plot(Eul_0001(:,5),Eul_0001(:,3),'Color','b');
xlabel('time (s)')
 ylabel('Energy')
 title('Energy vs time dt=.0001')
 legend('RK4','Euler','Location','northwest')

%damped 0.01 plots
 figure();
 subplot(2,2,1)
 plot(RK4d_01(:,5),RK4d_01(:,1),'Color','r'); hold on
 plot(Euld_01(:,5),Euld_01(:,1),'Color','b'); 
  xlabel('time (s)')
 ylabel('$\theta$ (rads)','interpreter','latex')
 title('Damped angle vs time dt=.01')
 legend('RK4','Euler','Location','northwest')
 subplot(2,2,2)
 plot(RK4d_01(:,5), RK4d_01(:,2),'Color','r');hold on
 plot(Euld_01(:,5), Euld_01(:,2),'Color','b');
 xlabel('time (s)')
 ylabel('$\omega$ (rads/s)','interpreter','latex')
 title('Damped angular velocity vs time dt=.01')
 legend('RK4','Euler','Location','northwest')
 subplot(2,2,3)
 plot(RK4d_01(:,2),RK4d_01(:,1),'Color','r'); hold on
 plot(Euld_01(:,2),Euld_01(:,1),'Color','b');
 xlabel('$\omega$ (rads/s)','interpreter','latex')
 ylabel('$\theta$ (rads)','interpreter','latex')
 title('Damped Phase Space')
 legend('RK4','Euler','Location','northwest')
 subplot(2,2,4)
 plot(RK4d_01(:,5),RK4d_01(:,3),'Color','r'); hold on
 plot(Euld_01(:,5),Euld_01(:,3),'Color','b');
  xlabel('time (s)')
 ylabel('Energy')
 title('Damped energy vs time dt=.01')
 legend('RK4','Euler','Location','northwest')
 %damped 0.0001 plots
 figure();
subplot(2,2,1)
plot(RK4d_0001(:,5),RK4d_0001(:,1),'Color','r'); hold on
plot(Euld_0001(:,5),Euld_0001(:,1),'Color','b');
xlabel('time (s)')
 ylabel('$\theta$ (rads)','interpreter','latex')
 title('Damped angle vs time dt=.0001')
 legend('RK4','Euler','Location','northwest')
subplot(2,2,2)
plot(RK4d_0001(:,5), RK4d_0001(:,2),'Color','r');hold on
plot(Euld_0001(:,5), Euld_0001(:,2),'Color','b');
xlabel('time (s)')
 ylabel('$\omega$ (rads/s)','interpreter','latex')
 title('Dmp angular velocity vs time dt=.0001')
 legend('RK4','Euler','Location','northwest')
subplot(2,2,3)
plot(RK4d_0001(:,2),RK4d_0001(:,1),'Color','r'); hold on
plot(Euld_0001(:,2),Euld_0001(:,1),'Color','b');
 xlabel('$\omega$ (rads/s)','interpreter','latex')
 ylabel('$\theta$ (rads)','interpreter','latex')
 title('Damped Phase Space')
 legend('RK4','Euler','Location','northwest')
subplot(2,2,4)
 plot(RK4d_0001(:,5),RK4d_0001(:,3),'Color','r'); hold on
 plot(Euld_0001(:,5),Euld_0001(:,3),'Color','b');
  xlabel('time (s)')
 ylabel('Energy')
 title('Dmp energy vs time dt=.0001')
 legend('RK4','Euler','Location','northwest')
 
 
 %0.01 and 0.0001 |omega - <omega>| vs time , | E - <E> | vs time undamped
 %                   2         6         5      3    7        5
 figure();
 subplot(2,2,1)
 plot(RK4_01(:,5), abs( abs(RK4_01(:,2)) - abs(RK4_01(:,6))), 'Color','r'); hold on
 plot(Eul_01(:,5), abs( abs(Eul_01(:,2)) - abs(Eul_01(:,6))), 'Color','b');
 xlabel('time (s)')
 ylabel('Absolute Error')
 title('$|\omega - \hat{\omega}|$ vs time dt=.01','interpreter','latex')
 legend('RK4','Euler','Location','northwest')
 subplot(2,2,2)
 plot(RK4_01(:,5), abs( abs(RK4_01(:,3)) - abs(RK4_01(:,7))), 'Color','r'); hold on
 plot(Eul_01(:,5), abs( abs(Eul_01(:,3)) - abs(Eul_01(:,7))), 'Color','b');
 xlabel('time (s)')
 ylabel('Absolute Error')
 title('$|E - \hat{E}|$ vs time dt=.01','interpreter','latex')
 legend('RK4','Euler','Location','northwest')
 subplot(2,2,3)
 plot(RK4_0001(:,5), abs( abs(RK4_0001(:,2)) - abs(RK4_0001(:,6))), 'Color','r'); hold on
 plot(Eul_0001(:,5), abs( abs(Eul_0001(:,2)) - abs(Eul_0001(:,6))), 'Color','b');
  xlabel('time (s)')
 ylabel('Absolute Error')
 title('$|\omega - \hat{\omega}|$ vs time dt=.0001','interpreter','latex')
 legend('RK4','Euler','Location','northwest')
 subplot(2,2,4)
  plot(RK4_0001(:,5), abs( abs(RK4_0001(:,3)) - abs(RK4_0001(:,7))), 'Color','r'); hold on
 plot(Eul_0001(:,5), abs( abs(Eul_0001(:,3)) - abs(Eul_0001(:,7))), 'Color','b');
 xlabel('time (s)')
 ylabel('Absolute Error')
 title('$|E - \hat{E}|$ vs time dt=.0001','interpreter','latex')
 legend('RK4','Euler','Location','northwest')
 
  %0.01 and 0.0001 |omega - <omega>| vs time , | E - <E> | vs time damped
 %                   2         6         5      3    7        5
 figure();
 subplot(2,2,1)
 plot(RK4d_01(:,5), abs( abs(RK4d_01(:,2)) - abs(RK4d_01(:,6))), 'Color','r'); hold on
 plot(Euld_01(:,5), abs( abs(Euld_01(:,2)) - abs(Euld_01(:,6))), 'Color','b');
 xlabel('time (s)')
 ylabel('Absolute Error')
 title('Damped $|\omega - \hat{\omega}|$ vs time dt=.01','interpreter','latex')
 legend('RK4','Euler','Location','northwest')
 subplot(2,2,2)
 plot(RK4d_01(:,5), abs( abs(RK4d_01(:,3)) - abs(RK4d_01(:,7))), 'Color','r'); hold on
 plot(Euld_01(:,5), abs( abs(Euld_01(:,3)) - abs(Euld_01(:,7))), 'Color','b');
  xlabel('time (s)')
 ylabel('Absolute Error')
 title('Damped $|E - \hat{E}|$ vs time dt=.01','interpreter','latex')
 legend('RK4','Euler','Location','northwest')
 subplot(2,2,3)
 plot(RK4d_0001(:,5), abs( abs(RK4d_0001(:,2)) - abs(RK4d_0001(:,6))), 'Color','r'); hold on
 plot(Euld_0001(:,5), abs( abs(Euld_0001(:,2)) - abs(Euld_0001(:,6))), 'Color','b');
  xlabel('time (s)')
 ylabel('Absolute Error')
 title('Damped $|\omega - \hat{\omega}|$ vs time dt=.0001','interpreter','latex')
 legend('RK4','Euler','Location','northwest')
 subplot(2,2,4)
  plot(RK4d_0001(:,5), abs( abs(RK4d_0001(:,3)) - abs(RK4d_0001(:,7))), 'Color','r'); hold on
 plot(Euld_0001(:,5), abs( abs(Euld_0001(:,3)) - abs(Euld_0001(:,7))), 'Color','b');
 xlabel('time (s)')
 ylabel('Absolute Error')
 title('Damped $|E - \hat{E}|$ vs time dt=.0001','interpreter','latex')
 legend('RK4','Euler','Location','northwest')
 