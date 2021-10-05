% A minimalistic Echo State Networks demo with Mackey-Glass (delay 17) data 
% in "plain" Matlab.
% by Mantas Lukosevicius 2012
% http://minds.jacobs-university.de/mantas
clear all;
clc;
load Rossler
Leakingrate=0.5;
nL=length(Leakingrate);
Ydata(:,1)=Y(1000:32000,1)./max(abs(Y(1000:32000,1)));
Ydata(:,2)=Y(1000:32000,2)./max(abs(Y(1000:32000,2)));
Ydata(:,3)=Y(1000:32000,3)./max(abs(Y(1000:32000,3)));
%Ydata=Y(1000:11000,:);
%sdata(1,1000:end)=sdata(1,1000:end)./max(abs(sdata(1,1000:end)));
mse=zeros(1,nL);
for k=1:nL
indata=Ydata;
outdata=Ydata;
initLen = 100;
trainLen =2600;
testLen = 600;
density=0.25;
inSize = 3; 
outSize = 3;
resSize =500; % size of the reservoir nodes;
a =Leakingrate(k); % leaking rate
Win = 2.0*rand(resSize,1+inSize)-1.0;
W=sprand(resSize, resSize, density);  

% Win = (rand(resSize,1+inSize)-0.5) .* 1;
% W = rand(resSize,resSize)-0.5;
% Option 1 - direct scaling (quick&dirty, reservoir-specific):
% W = W .* 0.13;
% Option 2 - normalizing and setting spectral radius (correct, slower):
disp 'Computing spectral radius...';
opt.disp = 0;
rhoW = abs(eigs(W,1,'LM',opt));
disp 'done.'
W = W .* (0.95/rhoW); % the spectral radius is 1.25:
% allocated memory for the design (collected states) matrix
X = zeros(1+inSize+resSize,trainLen-initLen);
% set the corresponding target matrix directly
Yt = outdata(initLen+2:trainLen+1,:)';
% run the reservoir with the data and collect X
x = zeros(resSize,1);
for t = 1:trainLen
    u = indata(t,:)';
    x = (1-a)*x + a*tanh( Win*[1;u] + W*x );
    if t > initLen
        X(:,t-initLen) = [1;u;x];
    end
end

% train the output
reg = 1e-8;  % regularization coefficient
X_T = X';
% Wout = Yt*X_T * inv(X*X_T + reg*eye(1+inSize+resSize));
Wout = Yt*X_T / (X*X_T + reg*eye(1+inSize+resSize));
% Wout = Yt*pinv(X);

% run the trained ESN in a generative mode. no need to initialize here, 
% because x is initialized with training data and we continue from there.
Y1= zeros(outSize,testLen);
u = indata(trainLen+1,:)';
for t = 1:testLen 
    x = (1-a)*x + a*tanh( Win*[1;u] + W*x );
    y = Wout*[1;u;x];
    Y1(:,t) = y;
    % generative mode:
    u = y;
    % this would be a predictive mode:
    %u = data(trainLen+t+1);
end
% errorLen = testLen;
% mse(k) = sum((outdata(trainLen+2:trainLen+errorLen+1)'-Y1(1,1:errorLen)).^2)./errorLen;
% disp( ['MSE = ', num2str( mse )] );
end
figure(1);
plot( outdata(trainLen+2:trainLen+testLen+1,1),'linewidth',2);
hold on;
plot( Y1(1,:)','-- ','linewidth',2);
hold off;
axis tight;


% figure(2);
% plot( outdata(trainLen+2:trainLen+testLen+1,2),'linewidth',2);
% hold on;
% plot( Y1(2,:)','-- ','linewidth',2);
% hold off;
% axis tight;

% figure(3);
% plot( outdata(trainLen+2:trainLen+testLen+1,3),'linewidth',2);
% hold on;
% plot( Y1(3,:)','-- ','linewidth',2);
% hold off;
% axis tight;
%title('Target and generated signals y(n) starting at n=0');
% legend('Actual signal', 'Reservior output');
% xlabel('\it{t-T}','FontName','Times New Roman','FontSize',24);
% ylabel('\it{output}','FontName','Times New Roman','FontSize',24);
number=10000;
Pdata=zeros(number,3);
Pdata1=zeros(number,3);
x1=x;
u1=[1 0 -1]';
u1(2)=u(2);
Pdata(1,:)=u;
Pdata1(1,:)=u1;
for i=1:number-1
   x = (1-a)*x + a*tanh( Win*[1;u] + W*x );
   x1 = (1-a)*x1 + a*tanh( Win*[1;u1] + W*x1);
   y = Wout*[1;u;x];
   y1=Wout*[1;u1;x1];
   Pdata(i+1,:) = y;
   u=y;
   Pdata1(i+1,:) = y1;
   u1=y1;
   u1(2)=u(2);
end;
time1=[0:number-1]*0.1;

figure(4);
plot(time1,Pdata(:,1)','linewidth',2);
hold on
plot(time1,Pdata1(:,1)','-- ','linewidth',2);
hold off;
xlabel('\it{t}','FontName','Times New Roman','FontSize',26);
ylabel('\it{x(t)}','FontName','Times New Roman','FontSize',26);



figure(5);
plot(time1,Pdata(:,3)','linewidth',2);
hold on
plot(time1,Pdata1(:,3)','-- ','linewidth',2);
hold off;
xlabel('\it{t}','FontName','Times New Roman','FontSize',26);
ylabel('\it{z(t)}','FontName','Times New Roman','FontSize',26);


