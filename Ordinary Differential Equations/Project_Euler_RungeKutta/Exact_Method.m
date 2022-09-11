% INPUT - ODE (text), y0 (init) , t_values (array)
% Output - exact_values (array)

function [exact_values] = Exact_Method(ODE, y0, t_values)

eqn = strcat('Dy=',ODE)
inits = sprintf('y(0)=%0.2g',y0)

t = t_values;
y = dsolve(eqn,inits, 't');
exact_values= eval(vectorize(y));


%test values y' = 2y-3t; y(0)=1, at t=0.1, 0.2, 0.3
%exact_values = [1.2054,1.4230,1.6555,1.9064]
