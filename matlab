clear all; clc;
syms x
s = solve(cos(2*x)+sin(x)==1,x) 
s = solve(x^3-2*x^2==x-1,x)
vpa(s,10)
%%
%solve the second derivative equation
syms a b c x
f=a*x^2+b*x+c
solve(f)
b=solve(f,b)
%%
% solve the linear algebraic equations
syms x y z r1 r2 r3 
[x,y,z]=solve(1/x+1/(y+z)-1/r1,1/y+1/(z+x)-1/r2,1/z+1/(x+y)-1/r3)
%%
%Solve the ordinary differential equations
text(\farc{d}{dx}x=-ax)
dsolve('Dx=-ax')   %This is different from the way it was written above
%%
%Example 8 Compute sinx, sin4x and plot their figure ,for x from 0 to 6 and
%with interval 0.1
x=0:0.1:6;
plot(x,sin(x))
hold on 
plot(x,sin(4*x))
another writting
x=0:0.1:6;
A=[x;4*x];
B=sin(A);
plot(x,B(1,:),'b:s',x,B(2,:))
%%
%Draw a triangle
x=[1,2.3,3,1];
y=[1 1.5 1 1];
plot(x,y)
ballode
funtool  %The function calculator calculates the function
taylortool  %The Taylor expansion calculator for the function
%%
x=[1 3 5];
y=[2 4 6];
[X,Y]=meshgrid(x,y);
z = x.^2+2*y;
Z = X.^2+2*Y;
%%

1.2.5 set cell array 
G{1,1}=3;
G{1,2}=[1 2;3 5];
G{2,1}='good';
G{2,2}= 'sin(x)';
G
%% 
%Evaluate the function
F=@(x,t)cos(x.^2).^2+t;
F(3,2.1)
and 
syms x theta 
FFF=cos(x.^2).^2+theta
subs(FFF,{'x','theta'},{3,2.1})
%%
%example 12 evalute and plot the sin*pi*x(n=1,2,3,4; x=0:0.001:1)
x=[0:0.001:1];
y=sin(pi*[1:4]'*x);
plot(x,y,'k:s')
