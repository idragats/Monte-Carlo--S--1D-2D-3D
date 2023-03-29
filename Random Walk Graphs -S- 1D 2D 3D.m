clf; clc;
file1=load("randomWalk1dS.txt");
file2=load("randomWalk2dS.txt");
 file3=load("randomWalk3dS.txt");

x1=file1(:,1);
y1=file1(:,2);

x2=file2(:,1);
y2=file2(:,2);

x3=file3(:,1);
y3=file3(:,2);



figure(1)
clf;
plot(x1,y1,'+g'), hold on
p1 = polyfit(log(x1),log(y1),1); 
m1 = p1(1);
b1 = exp(p1(2));
fplot(@(x1) b1*x1.^m1,[x1(1) x1(end)])
%fplot(@(x1) (8.*x1./pi).^(1/2),[x1(1) x1(end)])
%legend('data',['Power Low Equation is y =', num2str(b1),'*x ^','{',num2str(m1),'}'] ...
                %  ,'Location','northwest')  %,'Sn=(8N/ð)^{1/2}'
xlabel("time step")
ylabel("<S>")
title(" 1D")

plot(x2,y2,'+g'); 
p2 = polyfit(x2,y2,1); 
f2 = polyval(p2,x2); 
plot(x2,f2,'-') 
%legend('data',['Line Equation is y = ',num2str(p2(1)),'*x + ','(',num2str(p2(2)),')'],'Location','northwest')  

xlabel("time step")
ylabel("<S>")
title(" 2D")

plot(x3,y3,'+g');
p3 = polyfit(x3,y3,1); 
f3 = polyval(p3,x3); 
plot(x3,f3,'-') 
%legend('data',['Line Equation is y = ',num2str(p3(1)),'*x + ','(',num2str(p3(2)),')'],'Location','northwest')  
 
legend('data 1D',['Power Low Equation is y =', num2str(b1),'*x ^','{',num2str(m1),'}'], ...
                'data 2D',['Line Equation is y = ',num2str(p2(1)),'*x + ','(',num2str(p2(2)),')'], ...
                  'data 3D',['Line Equation is y = ',num2str(p3(1)),'*x + ','(',num2str(p3(2)),')'],'Location','northwest')

xlabel("time step")
ylabel("<S>")
title("1D,2D,3D")