%HW1 #4&5

    %#4 read .dat file and plot data
    D = dlmread('animage.dat');
    figure();
    plotmatrix( D(1:end,1) ,D(1:end,2))
    title('Tree');
    xlabel('Tree');
    ylabel('Tree');
    
    %#5 read data 
    D = dlmread('DataSet.dat');
    %seperate the data set into two matrices
     x=D(1:end,1);
    y=D(1:end,2);
    
    %this section plots the entire data set
    %figure();
   % subplot(1,2,1);
   % plotmatrix( D(1:end, 1), D(1:end,2));
   % subplot(1,2,2);
   % plot(D(1:end, 1), D(1:end,2));
    % The first value is, Friday, November 20, 2015 12:00:00 AM
    % The last value is, Tuesday, December 22, 2015 11:45:00 PM
    % Data spans approximately 33 days
    % Data spans approximately 4 full weeks
    %splitting by weeks @ 12:00:00AM 22-27th, 27-4th, 4-11th, 11-18th,
        % 1448604000 , 1449208800 , 1449813600 , 1450418400, 
   
  %this section plots energy consumption over each week
%     week1 = [x(x< 1448604000) , y(x< 1448604000)];
%     week2 = [x(x> 1448604000 & x< 1449208800), y(x> 1448604000 & x< 1449208800)];
%     week3 = [x(x> 1449208800 & x< 1449813600), y(x> 1449208800 & x< 1449813600)];
%     week4 = [x(x> 1449813600 & x< 1450418400), y(x> 1449813600 & x< 1450418400)];
%     week5 = [x(x> 1450418400) , y(x> 1450418400)];  
%     week1=int64(week1);
%     week2=int64(week2);
%     week3=int64(week3);
%     week4=int64(week4);
%     week6=int64(week5);
    
    
      
    
%     figure();
%     %subplot(2,3,1);
%     plot(week1(1:end,1),week1(1:end,2))
%     dateaxis('x',8);
%     %subplot(2,3,2);
%     figure();
%     plot(week2(1:end,1),week2(1:end,2))
%     dateaxis('x',8);
%     %subplot(2,3,3);
%     figure();
%     plot(week3(1:end,1),week3(1:end,2))
%     dateaxis('x',8);
%     %subplot(2,3,4);
%     figure();
%     plot(week4(1:end,1),week4(1:end,2))
%     dateaxis('x',8);
%     %subplot(2,3,5);
%     figure();
%     plot(week5(1:end,1),week5(1:end,2))
%     dateaxis('x',8);
   
  % this section plots energy consumption as a function of time of day, and
  % energy consumption as a function of days in a week
    z = datetime(x,'ConvertFrom','epochtime');
    [Y,M,D,H,MN,S] = datevec(z);
    figure();
    scatter(H,y)
    title('Power Consumption as a Function of Time of Day');
    xlabel('Time (Hrs)');
    ylabel('Power Used kwh');
    
    figure();
   [ WeekdayNum, WeekdayName] = weekday(z);
    scatter(WeekdayNum,y)
    title('Power Consumption as a Function of Day of the Week');
    xlabel('Day of the Week (Sun-Sat)');
    ylabel('Power Used kwh');
    
    %This section plots 33 figures, energy consumption for each day
     %48 datapoints should be a day
   % n=96;
   % nold=1;
   % i=1;
%     while nold < numel(x)
%       %  day = [z(nold:n),y(nold:n) ];
%       dayx = z(nold:n);
%       dayy = y(nold:n);
%         nold=nold+96;
%         n = n + 96;
%         if(n>numel(x)) 
%             n=numel(x) ;
%         end
%        % figure()%
%      %   plot(dayx,dayy)
%       
%     end
    
    