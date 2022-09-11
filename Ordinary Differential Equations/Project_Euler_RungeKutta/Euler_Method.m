
%INPUT - ODE (string), y0=init cond (init), T=t_values (array), h= step size (int)
%OUTPT - euler_values = estimaties of y (array)
function [euler_values] = Euler_Method(ODE, y0, T, h)

%---------------------------------------------------------------
% Define the differential equation y'=f(t,y)
%---------------------------------------------------------------
f=inline(ODE,'t','y');

%---------------------------------------------------------------
% Set initial condition
%---------------------------------------------------------------
t0=0;

%---------------------------------------------------------------
% Loop to solve the IVP four times -- once for each entry in T
% Use Euler method.
%---------------------------------------------------------------
for j=1:length(T)

    % We need this many iterations to get to T with a stepsize of h.
    steps=round(T(j)/h);

    % Start at initial condition each time through
    y_n=y0;
    t_n=t0;

    % Implement the Euler method
    for i=1:steps
        y_np1=y_n+f(t_n,y_n)*h;
        t_n=t_n+h;
        y_n=y_np1;
    end

    euler_values{j}=y_n; %returns y values as array
end
