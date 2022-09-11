%% Quesiton 1
y=dsolve('Dy = y^2+t^2', 't')

%Output
% y = -(t^(1/2)*(t*bessely(-3/4, t^2/2) - bessely(1/4, t^2/2)/(2*t)) + bessely(1/4, t^2/2)/(2*t^(1/2)))/(t^(1/2)*bessely(1/4, t^2/2))
% -(t^(1/2)*(t*besselj(-3/4, t^2/2) - besselj(1/4, t^2/2)/(2*t)) +
% besselj(1/4, t^2/2)/(2*t^(1/2)) + C1*t^(1/2)*(t*bessely(-3/4, t^2/2) -
% bessely(1/4, t^2/2)/(2*t)) + (C1*bessely(1/4,
% t^2/2))/(2*t^(1/2)))/(t^(1/2)*besselj(1/4, t^2/2) +
% C1*t^(1/2)*bessely(1/4, t^2/2))
%Bessel functions- canoncial solutions of Bessel's diff eq
%important for problems of wave propagation

%% Question 2
syms y(t)
%define diff eq y' = ty
ode = diff(y,t) == t*y;
dsolve(ode)
%output
% ans =C1*exp(t^2/2)

%% Question 2 part b
conditions = {'y(0)=1','Dy(0)=0'} %doesn't create vector just text
ode2 = diff(y,t,2)==(cos(2*t))^2-y
y = dsolve(ode2,conditions)
%I get error when using "conditions" it won't create a vector

%% Question 3

ezplot('3*y-10*sin(x)', [0,10,-5,5])

%% Question 3b

[x,y] = meshgrid(0: .3:10, -5: .3:5);
dy = 3*y-10*sin(x);
dx = ones(size(dy));
quiver(x,y,dx,dy)
dyu = dy./sqrt(dy.^2+dx.^2);
dxu= dx./sqrt(dy.^2+dx.^2);
quiver(x,y,dxu,dyu)





