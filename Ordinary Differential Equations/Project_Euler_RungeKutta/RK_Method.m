%INPUT - ODE (string), y0=init cond (init), T=t_values (array), h= step size (int), t0
%OUTPT - euler_values = estimaties of y (array)
function [rk_values] = RK_Method(ODE, y0, T, h, t0)

f=inline(ODE,'t','y');

for j=1:length(T)

  steps=round(T(j)/h);

  y=y0;
  t=t0;

    for i=1:steps
        k1=f(t,y);
        k2=f(t + h/2, y + h*k1/2);
        k3=f(t + h/2, y + h*k2/2);
        k4=f(t+h, y + h*k3);
        next_y=y + h*(k1 + 2*k2 + 2*k3 + k4)/6;
        t=t+h;
        y=next_y;
    end
  %add y value to rk_values
  rk_values{j}=y; %returns y values as array
end
