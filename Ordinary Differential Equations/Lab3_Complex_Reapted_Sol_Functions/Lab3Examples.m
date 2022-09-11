clc; clear all; close all;

%% Example 1 3.3
charpoly = [1 1 9.25]; % characteristic polynomial as a vector [a b c]
y0 = 2; % IC1
yp0 = 8; %IC2
[r,stry] = SolverComplexRoot(charpoly, y0, yp0);
% to get better plot limit x and y axeses as below
xlim([0 10])
ylim([-4 4])

% We will solve the homogeneous equation: 
%       1 y'' + 1 y' + 9.250000e+00 y = 0.
%
% This program can solve the ODE
%
% The solution to the IVP is y(t) = 2*exp(    -0.5*t).*cos(       3*t) + 3*exp(    -0.5*t).*sin(       3*t).

%% Example 2 3.3
charpoly = [16 -8 145]; % characteristic polynomial as a vector [a b c]
y0 = -2; % IC1
yp0 = 1; %IC2
[r,stry] = SolverComplexRoot(charpoly, y0, yp0);
% to get better plot limit x and y axeses as below
xlim([0 8])
ylim([-10 13])
%
% We will solve the homogeneous equation:
%       16 y'' + -8 y' + 145 y = 0.
%
% This program can solve the ODE
%
% The solution to the IVP is y(t) = -2*exp(    0.25*t).*cos(       3*t) + 0.5*exp(    0.25*t).*sin(       3*t).

%% Example 3 3.3
charpoly = [1 0 9]; % characteristic polynomial as a vector [a b c]
y0 = 2; % IC1
yp0 = 8; %IC2
[r,stry] = SolverComplexRoot(charpoly, y0, yp0);
% to get better plot limit x and y axeses as below
xlim([0 8])
ylim([-5 5])

% We will solve the homogeneous equation:
%       1 y'' + 0 y' + 9 y = 0.
%
% This program can solve the ODE
%
% The solution to the IVP is y(t) = 2*exp(      -0*t).*cos(       3*t) + 2.66666667*exp(      -0*t).*sin(       3*t).

%% Example 1 3.4
charpoly = [1 4 4]; % characteristic polynomial as a vector [a b c]
y0 = 1; % IC1
yp0 = 1; %IC2
[r,stry] = SolverRealRepeatedRoot(charpoly, y0, yp0);
% to get better plot limit x and y axeses as below
xlim([0 2.5])
ylim([0 1.6])

% We will solve the homogeneous equation:
%       1 y'' + 4 y' + 4 y = 0.
%
% This program can solve the ODE
% This program can solve the ODE
%
% The solution to the IVP is y(t) = 1*exp(      -2*t) + 3*t.*exp(      -2*t).


%% Example 2 3.4
charpoly = [1 -1 .25]; % characteristic polynomial as a vector [a b c]
y0 = 2; % IC1
yp0 = .333; %IC2
[r,stry] = SolverRealRepeatedRoot(charpoly, y0, yp0);
% to get better plot limit x and y axeses as below
xlim([0 3])
ylim([-1 3])

% We will solve the homogeneous equation:
%       1 y'' + -1 y' + 2.500000e-01 y = 0.
%
% This program can solve the ODE
% This program can solve the ODE
%
% The solution to the IVP is y(t) = 2*exp(     0.5*t) + -0.667*t.*exp(     0.5*t).
