data = dlmread('movmentdistribution.dat');
hist(data)
title('Movement Distribution 20mrads')
xlabel('Angular Displacement (rads) ')
ylabel('Events per bin')

data1 = dlmread('SecondaryInfections_Static_stats.dat');
%figure();
%errorbar(data(:,3),data(:,1),data(:,2),'.k')


data2 = dlmread('SecondaryInfections_Mobile_stats.dat');
%figure();
%errorbar(data(:,3),data(:,1),data(:,2),'.k')

data3 = dlmread('SecondaryInfections_Static_Probable_stats.dat');
%figure();
%errorbar(data(:,3),data(:,1),data(:,2),'.k')

%following plots are for infected rate
data = dlmread('nExposedAndnDays_Static_stats.dat');
figure();
errorbar(data(:,5),data(:,1)./1000,data(:,2)./1000,'.k')
title('Infection Rate, Spatially Certain, static model')
xlabel('Critical Angle (rads)')
ylabel('Percent of Exposed to Total Population')
figure();
errorbar(data(:,5),data(:,3),data(:,4),'.k')
title('Days until 0 infections, Spatially Certain, static model');
xlabel('Critical Angle (rads)')
ylabel('Number of Days')
figure();
errorbar(data1(:,3),data1(:,1),data1(:,2),'.k')
title('Day 2 Secondary Infections, Spatially Certain, static model');
xlabel('Critical Angle (rads)')
ylabel('Secondary Infections')

data = dlmread('nExposedAndnDays_Mobile_stats.dat');
figure();
errorbar(data(:,5),data(:,1)./1000,data(:,2)./1000,'.k')
title('Infection Rate, Spatially Certain, Mobile model')
xlabel('Critical Angle (rads)')
ylabel('Percent of Exposed to Total Population')
figure();
errorbar(data(:,5),data(:,3),data(:,4),'.k')
title('Days until 0 infections, Spatially Certain, Mobile model')
xlabel('Critical Angle (rads)')
ylabel('Number of Days')
figure();
errorbar(data2(:,3),data2(:,1),data2(:,2),'.k')
title('Day 2 Secondary Infections, Spatially Certain, Mobile model')
xlabel('Critical Angle (rads)')
ylabel('Secondary Infections')

data = dlmread('nExposedAndnDays_Static_Probable_stats.dat');
figure();
errorbar(data(:,5),data(:,1)./1000,data(:,2)./1000,'.k')
title('Infection Rate, Spatially Probable, static model')
xlabel('Critical Angle (rads)')
ylabel('Percent of Exposed to Total Population')
figure();
errorbar(data(:,5),data(:,3),data(:,4),'.k')
title('Days until 0 infections, Spatially Probable, static model')
xlabel('Critical Angle (rads)')
ylabel('Number of Days')
figure();
errorbar(data3(:,3),data3(:,1),data3(:,2),'.k')
title('Day 2 Secondary Infections, Spatially Probable, static model')
xlabel('Critical Angle (rads)')
ylabel('Secondary Infections')

