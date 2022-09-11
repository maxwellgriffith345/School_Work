clc; clear all; close all;

ODE = '3-2*t-0.5*y';
t0 = 0;
y0 = 1;
t_values = [0.2 0.4 0.6 0.8 1.0];

%---------------------------------------------------------------
% allow user to enter the stepsize h
%---------------------------------------------------------------
step_size=input('Enter the stepsize => ');

y_exact = Exact_Method(ODE, y0, t_values)
y_euler = Euler_Method(ODE, y0, t_values, step_size)
y_rk = RK_Method(ODE, y0, t_values, step_size, t0)

%% Find absolute error using |y_exact-y_n_tot|
EulerAbsError = abs(y_exact - cell2mat(y_euler))
RKAbsError = abs(y_exact - cell2mat(y_rk))

%%Create Table-how to export as csv?
%Euler Sol, RK Sol, Exact Sol, Euler Error, RK Error

%%Sketch Graph
figure;
plot(t_values,y_exact, '-ro','Linewidth',2.5); hold on;
plot(t_values,cell2mat(y_euler),'-bs', 'Linewidth',2.5);
plot(t_values,cell2mat(y_rk),'-go', 'Linewidth',2.5);
legend('Exact','Euler','RK', 'Location','NorthWest');
xlabel('t');
ylabel('y');
grid on;
