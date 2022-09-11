function [r,stry] = SolverRealRepeatedRoot(charpoly, y0, yp0)%function[output]=functionName(Input)


%charpoly=input('Enter the characteristic polynomial as a vector [a b c] =>');
disp(sprintf('We will solve the homogeneous equation: '));
disp(sprintf('      %d y'''' + %d y'' + %d y = 0.\n',charpoly(1),charpoly(2),charpoly(3)));
t0=0;
%y0=input('Enter the value of y(0)  => ');
%yp0 = input('Enter the value of y''(0) => ');

r=roots(charpoly);

%error handling for checking roots (only handles m1!=m2)
if (r(1) ~= r(2)) % == means Determine equality
    disp(sprintf('This program won''t work for distinct roots of the characteristic equation.'));
    disp(sprintf('Exiting program.'));
    return
elseif (imag(r(1))~=0)
    disp(sprintf('This program won''t work for complex roots of the characteristic equation.'));
    disp(sprintf('Exiting program.'));
    return
else
    disp(sprintf('This program can solve the ODE'))
end

%error handling for checking roots (only handles m1!=m2)
if (r(1) ~= r(2)) % == means Determine equality
    disp(sprintf('This program won''t work for distinct roots of the characteristic equation.'));
    disp(sprintf('Exiting program.'));
    return
elseif (imag(r(1))~=0)
    disp(sprintf('This program won''t work for complex roots of the characteristic equation.'));
    disp(sprintf('Exiting program.'));
    return
else
    disp(sprintf('This program can solve the ODE'))
end

% Define the fundamental set of solutions as strings
y1spec = "exp(%8.2g*t)";
y2spec = "t.*exp(%8.2g*t)";
y1str=sprintf(y1spec,r(1)); %y1 = e^(r1*t)
y2str=sprintf(y2spec,r(1)); %y1 = e^(r1*t)

% Convert fundamental set of solutions to functions
y1=inline(y1str,'t');
y2=inline(y2str,'t');

%solving system of y and y' to find C1 and C2
%y'=root*y1  ie y=e^mt so y'=me^mt
%A=
A=[1 0; r(1) 1];       % This is the coefficient matrix
b=[y0;yp0];
x=A\b;                                           % Solves Ax=b by x=Inv(A)*b, x is vector [c1,c2]

stry=sprintf('%.9g*%s + %.9g*%s',x(1),y1str,x(2),y2str); % general solution

%Plot Solution
disp(sprintf('\nThe solution to the IVP is y(t) = %s.',stry));
y=inline(stry,'t');
figure;
hold on;
tpts=linspace(-10,10,1000);
ypts=feval(y,tpts);
plot(tpts,ypts,'LineWidth', 3);
[ymin,j]=min(ypts);             % Find smallest y-value so we can construct
miny=min(round(ymin-1),0);      %     nice window dimensions
axis([-10 10 miny 10]);         % Set window size
gphtitle=sprintf('Solution to %dy'''' + %dy'' + %dy = 0, y(%.2g) = %.8g, y''(%.2g)=%.8g\n',charpoly(1),charpoly(2),charpoly(3),t0,y0,t0,yp0);
title(gphtitle);                % add title to graph.
end
